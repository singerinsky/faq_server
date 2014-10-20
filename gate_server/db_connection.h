#ifndef _DB_CONNECTION_H_
#define _DB_CONNECTION_H_
#include "socket.h"
#include "timer.h"
#include "db_message.pb.h"
#include "gate_client.h"


class db_connection:public socket_client
{
    public:
        db_connection()
        {
            process_count = 0;
        }

    public:
        void on_error(bufferevent* bev);
        int process_msg(packet_info* msg_packet);
        void on_timeout();
        int  build_query(int seq,int operate_type,const char* sql_str,...);
        void on_connection(bufferevent* bev)
        {
            LOG(INFO)<<"on connection build!"; 
        }
    protected:
        int process_db_response(packet_info* info);
        int on_load_user_info(const db_tb_user& info);
        int load_user_item_list(const DBUserItemList& info);
    private:
        template_timer<db_connection,&db_connection::on_timeout>    _m_timer;
        int process_count;
};

#endif
