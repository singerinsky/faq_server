#ifndef _CLIENT_SERVICE_H_
#define _CLIENT_SERVICE_H_
#include "service.h"
#include "db_client.h"

class db_service:public Service
{
    public:
        db_service(const char* ip,int port):Service(ip,port)
        {

        }
        ~db_service()
        {
        }

    public:
        int on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa);
};
#endif
