#include "db_application.h"
#include "client_service.h"
#include "daemon.h"
#include "session_manager.h"

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
/////////////////////////////////////////////
    TiXmlDocument doc(SERVER_XML);
    bool load_rst = doc.LoadFile();
    if(!load_rst)
    {
        LOG(ERROR)<<"load server failed!"; 
        exit(-1);
    }

    TiXmlNode* node = doc.FirstChild("server");
    TiXmlElement* ele = node->ToElement();
    int id = 0;
    ele->Attribute("id",&id);
    LOG(INFO)<<"ID"<<id;
///////////////////////////////////////////////
    db_application app("db");
    app.init();
    client_service* cs = new client_service("127.0.0.1",9999);
    app.add_service(cs);

    app.start_service();
    return 0;
}

