#include "server_application.h"
#include "daemon.h"
#include "service.h"
#include "head.h"

server_appliaction::server_appliaction(std::string name)
{
    _service_name = name;
    _reactor = Singleton<ReactorCore>::GetInstance();
    _reactor->init(); 
    init_signal_func();
}

server_appliaction::~server_appliaction()
{
    LOG(INFO)<<"delete server application";
}

bool server_appliaction::start_service()
{
    event_base_dispatch(_reactor->GetEventBase());
    return false;
}

void server_appliaction::add_service(Service *pservice)
{
    if(_reactor->add_listener_event(pservice->get_service_ip(),pservice->get_service_port(),pservice) < 0)
    {
        LOG(INFO)<<"add server " <<_service_name.c_str() << "not success"; 
    }
    LOG(INFO)<<"add service"<<_service_name.c_str()<<" listen in "<<pservice->get_service_ip() <<":"<<pservice->get_service_port();
}

void server_appliaction::init_signal_func()
{
    _signal_event = event_new(_reactor->GetEventBase(),SIGUSR1,EV_SIGNAL|EV_PERSIST,common_sign_cb,this);
    event_assign(_signal_event,_reactor->GetEventBase(),SIGUSR1,EV_SIGNAL|EV_PERSIST,common_sign_cb,(void*)this);
    event_add(_signal_event,NULL);
}
