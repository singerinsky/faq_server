#include "client_service.h"
#include "session_manager.h"

//typedef session_manager<int,gate_client> client_manager;
//template<> 
//client_manager* Singleton<client_manager >::_instance = 0;


int client_service::on_accept(struct bufferevent* event,evutil_socket_t fd,struct sockaddr_in* sa)
{
    //bufferevent* bev,int socket,sockaddr_in& addr
    gate_client* client = new gate_client(event,fd,sa);
    VLOG(1)<<"trigger client accept in fd "<<fd; 
    Singleton<client_manager>::GetInstance()->add_session(fd,client);
    //client->init_timer();
    return 1;
}

