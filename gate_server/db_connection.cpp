#include "db_connection.h"
#include "actions_mananger.h"
#include "message_define.h"
#include "db_message.pb.h"
#include "logic_player.h"

void db_connection::on_error(bufferevent* bev)
{
    if(is_online() == false)
        LOG(INFO)<<"connect to db failed";
    else 
        LOG(INFO)<<"lost connection to db server";
}

int db_connection::process_msg(packet_info* info)
{
    VLOG(1)<<"db_connection Recive message type "<<info->type;
    int message_type = info->type;
    switch(message_type)
    {
        case   cs_packet_db_common_response::packet_type: 
            process_db_response(info);
            break;
        default:
            LOG(ERROR)<<"message type unregister"<<message_type;
    
    }
    return 1;
}

void db_connection::on_timeout()
{
    if(is_online() ==false)
    {
        return; 
    }
    if(process_count == 0)
        LOG(INFO)<<"START";
//     cs_packet_heart_request request;
//     process_count++;
//     request.body.set_client_time(process_count);
// //    send_packet(&request);

    // cs_packet_db_common_request req;    
    // req.body.set_operate_type(DbOperateType::MSG_DB_GET_USER_INFO);
    // req.body.set_operate_string("select * from tb_user");
    // LOG(INFO)<<process_count<<"send ret ";
    // int ret = send_packet(&req);
    // if(ret < 0)
    // {
    //      LOG(ERROR)<<"error ";
    //      return;
    // }

    // req.body.set_operate_type(DbOperateType::MSG_DB_GET_ITEM_LIST);
    // req.body.set_operate_string("select * from tb_user_item where bi_ply_guid = 1");
    // ret = send_packet(&req);
    // 
    //  
    // if(process_count== 10000)
    //     LOG(INFO)<<"end ";
   // else
       // _m_timer.set_expire(1); 
}

int db_connection::process_db_response(packet_info* info)
{
    cs_packet_db_common_response response;
    if(response.decode(info->data,info->size) != info->size)return -1;
    if(response.body.ret() != 0)
    {
        LOG(ERROR)<<"db response error "<<response.body.operate_type(); 
    }
    switch(response.body.operate_type())
    {
        case DbOperateType::MSG_DB_GET_USER_INFO:
            return on_load_user_info(response.body.user_info());
        case DbOperateType::MSG_DB_GET_ITEM_LIST:
            return load_user_item_list(response.body.user_item_list());
        default:
            LOG(INFO)<<"unregister db operate "<<response.body.operate_type();
            return -2;
    }
}

int db_connection::on_load_user_info(const DBUserInfo& info)
{
    LOG(INFO)<<"load user info "<<info.user_name();
    cs_packet_init_client_notf notf;
    notf.body.set_ret(1);
    DBUserInfo* user_info = notf.body.mutable_user_info();
    *user_info = info;

   // LogicPlayer* player = new LogicPlayer();
    return 1;
}

int db_connection::load_user_item_list(const DBUserItemList& info)
{
    return 1;
}

int db_connection::build_query(int seq,int operate_type,const char* sql_str,...)
{
    char buffer[2048] = {0};
    va_list argp;
    va_start (argp,sql_str);
    vsnprintf(buffer,2048,sql_str,argp);
    va_end(argp);
    cs_packet_db_common_request request;
    request.body.set_seq(seq);
    request.body.set_operate_type(operate_type);
    request.body.set_operate_string(buffer);
    VLOG(2)<<"query  sql:"<<buffer;
    return send_packet(&request);
}










