#include "gate_application.h"
#include "client_service.h"
#include "daemon.h"

gate_application::~gate_application()
{

}

bool gate_application::init()
{
    LOG(INFO)<<"init gate_application...";
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

    gate_application app("gate");
    app.init();
    client_service* cs = new client_service("127.0.0.1",9999);
    app.add_service(cs);

    app.start_service();
    return 0;
}

