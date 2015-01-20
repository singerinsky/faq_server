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
        void stop_listener_service();
        //subclass implement this class ,create it's own method
        virtual bool init() =0;
        //
        void process_signal(int signal);
    protected:
        //subclass can extend this class ,and create these function
        virtual void process_signal_usr1();
        virtual void process_signal_usr2();
        
    public:
        void add_service(Service* pservice);
        void init_signal_func();
    private:
        ReactorCore* _reactor;
        std::string _service_name;
        bool        _work_flag;
};
#endif
