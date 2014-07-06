#include "gate_client.h"
#include "actions_mananger.h"


int gate_client::process_msg(packet_info* info)
{
    LOG(INFO)<<"Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info);
    return 1;
}


void gate_client::on_error(bufferevent* ev)
{
    LOG(INFO)<<"gate client error"<<get_socket_fd();
    delete this;
}
