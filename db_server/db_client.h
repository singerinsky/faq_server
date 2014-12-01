#ifndef _GATE_CLIENT_H_
#define _GATE_CLEINT_H_
#include "socket.h"
#include "timer.h"
#include "mysql_connection.h"

class MysqlResultRow;
class db_job;
class data_worker;
class db_client: public socket_client
{
    public:
        //bufferevent* bev,int socket,sockaddr_in& addr
        db_client(bufferevent* bev,evutil_socket_t socket,sockaddr_in* addr
                ):socket_client(bev,socket,addr)
        {
            LOG(INFO)<<"new db client connect!"; 
            socket_client::init_cb();
        }
        virtual ~db_client(){
        };
        void init(int db_work);
        void init_timer();

    public:
        int process_msg(packet_info* info);
        void on_error(bufferevent* ev);
        void on_timeout();
    protected:
        
        void on_load_user_data(MysqlResult& result,db_job* job);
        void on_load_item_list_data(MysqlResult& result,db_job* job);
        //       void release();
    public:
        void do_data_call(MysqlResult& result,db_job* job);
    private:
        template_timer<db_client,&db_client::on_timeout>    _m_timer;
};

#endif
