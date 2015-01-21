#include "db_service.h"
#include "session_manager.h"
#include "db_client.h"

int db_service::on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa)
{
    db_client* db = new db_client(event,fd,sa);
    Singleton<db_manager>::GetInstance()->add_session(fd,db);
    db->init_timer();
    return 1;
}

