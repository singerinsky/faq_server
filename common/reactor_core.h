#include "singleton.h"
#include "head.h"

class socketlistener;
void common_listener_cb(struct evconnlistener* listener,evutil_socket_t fd,struct sockaddr* sa,int socklen,void* user_data);

class ReactorCore:public Singleton<ReactorCore>
{
    public:
        friend Singleton<ReactorCore>;
    public:
        bool init();
        event_base* GetEventBase(){return _base;} 
        void        AddEvent(){}
        int         AddListenerEvent(string ip,int port,socketlistener* ls);
        void        RemoveEvent(){}
        void        Start();

    private:
        event_base* _base;
        std::vector<evconnlistener*> _all_listener; 

};

