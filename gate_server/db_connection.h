#ifndef _DB_CONNECTION_H_
#define _DB_CONNECTION_H_

class db_connection:public socket_client
{
    public:
        db_connection()
        {

        }

    public:
        void on_error(bufferevent* bev);
        int process_msg(packet_info* msg_packet);
};

#endif
