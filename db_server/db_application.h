#ifndef _GATE_APPLIACTION_H_
#define _GATE_APPLICATION_H_
#include "head.h"
#include "server_application.h" 
#define SERVER_XML "server.xml"

class db_service;
class db_application: public server_appliaction
{
    public:
        db_application(std::string name):server_appliaction(name)
        {}
        ~db_application();
        virtual bool init();
    private:
        db_service* db_service_;
};


#endif
