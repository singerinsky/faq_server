#include "server_application.h"
#include "daemon.h"
#include "service.h"

server_appliaction::server_appliaction(std::string name)
{
    _service_name = name;
    _reactor = Singleton<ReactorCore>::GetInstance();
    _reactor->init(); 
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

