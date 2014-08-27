#ifndef _DB_CONNECTION_H_
#define _DB_CONNECTION_H_
#include "socket.h"
#include "timer.h"


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
    private:
        template_timer<db_connection,&db_connection::on_timeout>    _m_timer;
        int process_count;
};

#endif
