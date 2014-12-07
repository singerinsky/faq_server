#include "gate_application.h"
#include "client_service.h"
#include "daemon.h"
#include "session_manager.h"
#include "db_connection.h"
#include "map_manager.h"
#include "npc_object.h"
#include "../prototype/game_prototype.h"

db_connection* gate_application::db_conn_ = NULL;
gate_application::~gate_application()
{

}


bool gate_application::init()
{
    LOG(INFO)<<"init gate_application...";
    db_conn_ = new db_connection();
    db_conn_->connect_to("127.0.0.1",9999);
    return true;
}

DEFINE_bool(daemon,false,"if start not daemon");
int main(int argc,char** argv)
{
    signal(SIGPIPE, SIG_IGN);
//    test* te = new test(); 
//    te->do_message_action();
 	google::ParseCommandLineFlags(&argc,&argv,true);		
	google::InitGoogleLogging(argv[0]);
	if(FLAGS_daemon){
		if(init_daemon() == -1){
			VLOG(0)<<"ERROR OF DAEMON";
		}
	}
    FLAGS_logtostderr = !FLAGS_daemon;

    gate_application app("gate");
    app.init();
    if(!Singleton<GamePrototype>::GetInstance()->Init())
    {
        exit(-1); 
    }
    Singleton<map_manager>::GetInstance()->init();
    Singleton<NpcManager>::GetInstance()->Init();
    client_service* cs = new client_service("127.0.0.1",9998);
    app.add_service(cs);

    app.start_service();
    return 0;
}

