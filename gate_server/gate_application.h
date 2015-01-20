#ifndef _GATE_APPLIACTION_H_
#define _GATE_APPLICATION_H_
#include "head.h"
#include "server_application.h" 
#define SERVER_XML "server.xml"

class client_service;
class db_connection;
class gate_application: public server_appliaction
{
    public:
        gate_application(std::string name):server_appliaction(name)
        {}
        ~gate_application();
        virtual bool init();
    protected:
        virtual void process_signal_usr1();
        virtual void process_signal_usr2();
    private:
        client_service* client_service_;
    public:
        static db_connection*  db_conn_;
};


#endif
