#ifndef _REATOR_CORE_H_
#define _REATOR_CORE_H_
#include "singleton.h"
#include "head.h"

class service;
void common_listener_cb(struct evconnlistener* listener,evutil_socket_t fd,struct sockaddr* sa,int socklen,void* user_data);

class ReactorCore:public Singleton<ReactorCore>
{
    public:
        friend Singleton<ReactorCore>;
    public:
        bool init();
        event_base* GetEventBase(){return _base;} 
        void        AddEvent(){}
        int         add_listener_event(string ip,int port,service* ls);
        void        RemoveEvent(){}
        void        Start();
        bufferevent* GetNewSocketEvent();

    private:
        event_base* _base;
        std::vector<evconnlistener*> _all_listener; 

};

#endif
