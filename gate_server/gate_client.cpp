#include "gate_client.h"


int gate_client::process_msg(packet_info* info)
{
    LOG(INFO)<<"Recive message type "<<info->type;
    return 1;
}


int gate_client::on_error(bufferevent* ev)
{
    LOG(INFO)<<"gate client error";
    return 1;
}
