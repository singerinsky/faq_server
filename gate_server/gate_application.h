#ifndef _GATE_APPLIACTION_H_
#define _GATE_APPLICATION_H_
#include "head.h"
#include "server_application.h" 

class gate_application: public server_appliaction
{
    public:
        gate_application();
        ~gate_application();
        virtual bool init();
    private:
        
};


#endif
