#include "reactor_core.h"
#include "net_util.h"
#include "service.h"

template<> 
ReactorCore* Singleton<ReactorCore>::_instance = 0;

void common_listener_cb(struct evconnlistener* listener,evutil_socket_t fd,struct sockaddr* sa,int socklen,void* user_data)
{
    struct bufferevent* bev;
    service* ls = (service*)user_data; 
    bev = bufferevent_socket_new(ReactorCore::GetInstance()->GetEventBase(), fd, BEV_OPT_CLOSE_ON_FREE);
    if(!bev)
    {
        LOG(ERROR)<<"error build bufferevent"; 
        event_base_loopbreak(ReactorCore::GetInstance()->GetEventBase());
        return;
    }
    int rst = ls->on_accept(bev,fd);
    if(rst < 0 )
    {
        LOG(ERROR)<<"accept error ,free bev"; 
        bufferevent_free(bev);
    }
}


bool ReactorCore::init()
{
    _base = event_base_new(); 
    if(_base == NULL)
    {
        LOG(ERROR)<<"init event base failed"; 
        return false;
    }
    return true;
}

int ReactorCore::add_listener_event(std::string ip,int port,service* ls)
{
    sockaddr_in addr_in;
    int rst = init_sa_in(&addr_in, ip.c_str(),port);
    if(rst < 0)
    {
        LOG(ERROR)<<"init socket addr error";
        return -2;
    }
    evconnlistener *new_ev_ls = evconnlistener_new_bind(_base,common_listener_cb,(void*)ls, LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, -1,(struct sockaddr*)&addr_in,sizeof(addr_in));
    if(!ls)
    {
        LOG(ERROR)<<"can't create listener on"<<ip.c_str()<<":"<<port; 
        return -1;
    }
    _all_listener.push_back(new_ev_ls);
    return 0;
}

void ReactorCore::Start()
{
    event_base_dispatch(_base);
}
