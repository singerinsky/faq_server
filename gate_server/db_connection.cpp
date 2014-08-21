#include "db_connection.h"
#include "actions_mananger.h"
#include "message_define.h"

void db_connection::on_error(bufferevent* bev)
{

}

int db_connection::process_msg(packet_info* info)
{
    VLOG(1)<<"db_connection Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info,this);
    return 1;
}

void db_connection::on_timeout()
{
typedef cs_packet<CS_MSG_HEART_BEAT_REQ,ClientHeartBeatRequest> cs_client_hb_request;  
    cs_client_hb_request request;
    request.body.set_client_time(11111);
    send_packet(&request);
}
