#include "service.h"
#include "gate_client.h"

class client_service:public service
{
    public:
        client_service(const char* ip,int port):service(ip,port)
    {


    }
        ~client_service(){};

    public:

        int on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa)
        {
            //bufferevent* bev,int socket,sockaddr_in& addr
            gate_client* client = new gate_client(event,fd,sa);
            client->init_cb();
            LOG(INFO)<<"trigger client accept in fd "<<fd; 
            return 1;
        }
};
