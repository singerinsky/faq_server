#include "server_application.h"
#include "daemon.h"

server_appliaction::server_appliaction()
{
    _reactor = Singleton<ReactorCore>::GetInstance();
    _reactor->init(); 
}

server_appliaction::~server_appliaction()
{
    LOG(INFO)<<"delete server application";
}

bool server_appliaction::start_service(bool daemon)
{
    if(daemon)
    {
        init_daemon(); 
    }

    event_base_dispatch(_reactor->GetEventBase());
    return false;
}
