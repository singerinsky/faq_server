#ifndef _SERVER_APPLIACTION_H_
#define _SERVER_APPLIACTION_H_
#include "head.h"
#include "reactor_core.h"

class server_appliaction
{
    public:
        server_appliaction();
        virtual ~server_appliaction();
        bool start_service(bool daemon);
        virtual bool init()=0;
    private:
        ReactorCore* _reactor;
};
#endif
