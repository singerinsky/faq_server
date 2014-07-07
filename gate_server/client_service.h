#ifndef _CLIENT_SERVICE_H_
#define _CLIENT_SERVICE_H_
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
        int on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa);
};
#endif
