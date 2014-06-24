#include "service.h"

class client_service:public service
{
    public:
        client_service(const char* ip,int port):service(ip,port)
        {}
        int on_accept(struct bufferevent* event,evutil_socket_t fd)
        {
            LOG(INFO)<<"trigger client accept"; 
            return 1;
        }
};
