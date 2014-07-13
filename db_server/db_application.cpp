#include "db_application.h"
#include "db_service.h"
#include "daemon.h"
#include "session_manager.h"
#include "db_connection_pool.h"
#include "data_worker.h"

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

    Singleton<db_pool>::GetInstance()->init(10);

    ///////////test
    data_worker* work = new data_worker();
    work->init();
    
    db_job* job = new db_job(); 
    job->_sql_str = "SELECT * FROM tb_user";
    work->add_job(job);
    work->create();
    for(int i=0;i<10;i++)
    {
        LOG(INFO)<<"add job "<<i;
        work->add_job(job); 
    }
//    db_factory::GetInstance()->init();
    //////////////end test

    app.start_service();
    return 0;
}

