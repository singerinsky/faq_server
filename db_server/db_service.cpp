#include "db_service.h"
#include "session_manager.h"

typedef session_manager<int,db_client> db_manager;
template<> 
db_manager* Singleton<db_manager >::_instance = 0;


int db_service::on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa)
{
    //bufferevent* bev,int socket,sockaddr_in& addr
    gate_db* db = new gate_db(event,fd,sa);
    db->init_cb();
    LOG(INFO)<<"trigger db accept in fd "<<fd; 
    Singleton<db_manager>::GetInstance()->add_session(fd,db);
    db->init_timer();
    return 1;
}

