#include "db_connection.h"

void db_connection::on_error(bufferevent* bev)
{

}

int db_connection::process_msg(packet_info* msg_packet)
{
    VLOG(1)<<"db_connection Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info,this);
    return 1;
}
