#ifndef _SERVICE_H
#define _SERVICE_H
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#include <string>

using namespace std;
class Service
{
    public:
        Service(const char* ip,int port):_ip(ip),_port(port)
        {
        }
        virtual ~Service(){}
        virtual int on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa) = 0;
        string  get_service_ip()
        {
            return _ip; 
        }

        int  get_service_port()
        {
            return _port; 
        }

    private:
        std::string _ip;
        int         _port;
};
#endif
