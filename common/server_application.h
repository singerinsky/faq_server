#ifndef _SERVER_APPLIACTION_H_
#define _SERVER_APPLIACTION_H_
#include "head.h"
#include "reactor_core.h"

class Service;
class server_appliaction
{
    public:
        server_appliaction(std::string name);
        virtual ~server_appliaction();
        bool start_service();
        virtual bool init()=0;
        virtual void process_signal(int signal) = 0;
        void add_service(Service* pservice);
        void init_signal_func();
    private:
        ReactorCore* _reactor;
        event*       _signal_event;
        std::string _service_name;
};
#endif
