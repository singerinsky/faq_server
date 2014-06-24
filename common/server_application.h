#ifndef _SERVER_APPLIACTION_H_
#define _SERVER_APPLIACTION_H_
#include "head.h"
#include "reactor_core.h"

class service;
class server_appliaction
{
    public:
        server_appliaction();
        virtual ~server_appliaction();
        bool start_service();
        virtual bool init()=0;
        void add_service(service* pservice);
    private:
        ReactorCore* _reactor;
};
#endif
