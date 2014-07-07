#ifndef _GATE_CLIENT_H_
#define _GATE_CLEINT_H_
#include "socket.h"
#include "timer.h"

class gate_client: public socket_client
{
    public:
        //bufferevent* bev,int socket,sockaddr_in& addr
        gate_client(bufferevent* bev,evutil_socket_t socket,sockaddr_in* addr
                ):socket_client(bev,socket,addr)
        {
            LOG(INFO)<<"new socket connect"; 
        }
        virtual ~gate_client(){
        };

        void init_timer();


    public:
        int process_msg(packet_info* info);
        void on_error(bufferevent* ev);
        void on_timeout();
    private:
        template_timer<gate_client,&gate_client::on_timeout>    _m_timer;

};

#endif
