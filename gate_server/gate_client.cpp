#include "gate_client.h"
#include "actions_mananger.h"


int gate_client::process_msg(packet_info* info)
{
    VLOG(1)<<"Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info);
    return 1;
}

void gate_client::on_error(bufferevent* ev)
{
    LOG(INFO)<<"gate client error"<<get_socket_fd();
    //Singleton<client_manager>::GetInstance()->remove_session(get_socket_fd());
    delete this;
}

void gate_client::init_timer()
{
   _m_timer.set_owner(this); 
   _m_timer.set_expire(2000); 
}

void gate_client::on_timeout()
{
    LOG(INFO)<<"without login virfy,kick out";
    //on_error(NULL);
}
