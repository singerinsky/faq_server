#include "server_application.h"
#include "daemon.h"
#include "service.h"

server_appliaction::server_appliaction()
{
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

void server_appliaction::add_service(service *pservice)
{
    _reactor->add_listener_event(pservice->get_service_ip(),pservice->get_service_port(),pservice);
}

