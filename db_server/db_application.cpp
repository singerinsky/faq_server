#include "db_application.h"
#include "db_service.h"
#include "daemon.h"
#include "session_manager.h"
#include "db_connection_pool.h"
#include "data_worker.h"
#include "work_manager.h"

db_application::~db_application()
{

}

bool db_application::init()
{
    LOG(INFO)<<"init db_application...";
    return true;
}

DEFINE_bool(daemon,false,"if start not daemon");
int main(int argc,char** argv)
{
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
    db_application app("db");
    app.init();
    db_service* cs = new db_service("127.0.0.1",9999);
    app.add_service(cs);

    int init_number = Singleton<db_pool>::GetInstance()->init(10);
    Singleton<work_manager>::GetInstance()->init(10);
    LOG(INFO)<<"init db pool "<<init_number;

    app.start_service();
    return 0;
}

