#ifndef _DB_CONNECTION_H_
#define _DB_CONNECTION_H_
#include "socket.h"
#include "timer.h"
#include "db_message.pb.h"


class db_connection:public socket_client
{
    public:
        db_connection()
        {
            _m_timer.set_owner(this); 
            _m_timer.set_expire(2000); 
            process_count = 0;
        }

    public:
        void on_error(bufferevent* bev);
        int process_msg(packet_info* msg_packet);
        void on_timeout();
        int  build_query(int seq,int operate_type,const char* sql_str,...);
    protected:
        int process_db_response(packet_info* info);
        int load_user_info(const DBUserInfo& info);
        int load_user_item_list(const DBUserItemList& info);
    private:
        template_timer<db_connection,&db_connection::on_timeout>    _m_timer;
        int process_count;
};

#endif
