#include "db_connection.h"
#include "actions_mananger.h"
#include "message_define.h"

void db_connection::on_error(bufferevent* bev)
{

}

int db_connection::process_msg(packet_info* info)
{
    VLOG(1)<<"db_connection Recive message type "<<info->type;
    int message_type = info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info,this);
    return 1;
}

void db_connection::on_timeout()
{
    if(process_count == 0)
        LOG(INFO)<<"START";
    cs_packet_heart_request request;
    process_count++;
    request.body.set_client_time(process_count);
//    send_packet(&request);

    cs_packet_db_common_request req;    
    req.body.set_operate_type(DbOperateType::MSG_DB_GET_USER_INFO);
    req.body.set_operate_string("select * from tb_user");
    LOG(INFO)<<process_count<<"send ret ";
    int ret = send_packet(&req);
    if(ret < 0)
    {
        LOG(ERROR)<<"error ";
         return;
     }
     
    if(process_count== 10000)
        LOG(INFO)<<"end ";
    else
        _m_timer.set_expire(1); 
}
