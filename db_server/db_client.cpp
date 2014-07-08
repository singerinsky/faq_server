#include "db_client.h"
#include "actions_mananger.h"


int db_client::process_msg(packet_info* info)
{
    VLOG(1)<<"Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info);
    return 1;
}

void db_client::on_error(bufferevent* ev)
{
    LOG(INFO)<<"db client error"<<get_socket_fd();
    //Singleton<client_manager>::GetInstance()->remove_session(get_socket_fd());
    delete this;
}

void db_client::init_timer()
{
   _m_timer.set_owner(this); 
   _m_timer.set_expire(2000); 
}

void db_client::on_timeout()
{
    LOG(INFO)<<"without login virfy,kick out";
    //on_error(NULL);
}
