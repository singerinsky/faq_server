#ifndef _CLIENT_SERVICE_H_
#define _CLIENT_SERVICE_H_
#include "service.h"
#include "gate_client.h"
#include "session_manager.h"

typedef session_manager<int,gate_client> client_manager;
class client_service:public Service
{
    public:
        client_service(const char* ip,int port):Service(ip,port)
    {

    }
        ~client_service(){};

    public:
        int on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa);
};
#endif
