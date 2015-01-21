#include "server_application.h"
#include "daemon.h"
#include "service.h"
#include "head.h"

server_appliaction::server_appliaction(std::string name)
{
    _work_flag = false;
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
    _work_flag = true;
    int rst = event_base_dispatch(_reactor->GetEventBase());
    if(rst == 0)
    {
        return true; 
    }
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
    event* _signal_event = evsignal_new(_reactor->GetEventBase(),SIGUSR1,common_sign_cb,(void*)this);
    if(!_signal_event || event_add(_signal_event,NULL))
    {
        LOG(ERROR)<<"add signal usr1 call failed";
        assert(false);
    }

    _signal_event = evsignal_new(_reactor->GetEventBase(),SIGUSR2,common_sign_cb,(void*)this);
    if(!_signal_event || event_add(_signal_event,NULL))
    {
        LOG(ERROR)<<"add signal usr2 call failed";
        assert(false);
    }
}

void server_appliaction::process_signal(int signal)
{
    LOG(INFO)<<"signal receive signal "<<signal;
    if(signal == (int)SIGUSR1)
    {
        process_signal_usr1();
    }else if(signal == (int)SIGUSR2)//stop service
    {
        process_signal_usr2(); 
    }else
    {
        LOG(ERROR)<<"unhandle sign error"<<signal; 
        assert(false);
        exit(-1);
    }
}

void server_appliaction::process_signal_usr1()
{
    if(_work_flag == true)
    {
        LOG(INFO)<<"recive signal usr1,stop service...";    
        stop_listener_service();
    }else
    {
        LOG(INFO)<<"recive signal usr1,start service...";    
        start_listener_service();
    }
}

void server_appliaction::process_signal_usr2()
{
    LOG(INFO)<<"recive signal usr2";    
}

void server_appliaction::stop_listener_service()
{
    _reactor->StopAllListener();
    _work_flag =false;
}

void server_appliaction::start_listener_service()
{
    _reactor->StartAllListener();
    _work_flag = true;
}
