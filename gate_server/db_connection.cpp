#include "db_connection.h"
#include "actions_mananger.h"
#include "message_define.h"
#include "db_message.pb.h"
#include "logic_player.h"
#include "client_service.h"
#include "player_manager.h"

void db_connection::on_error()
{
    LOG(INFO)<<"lost connection!";
    _m_timer.set_owner(this);
    _m_timer.set_expire(2000); 
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
    LOG(INFO)<<"do reconnect!";
    if(is_online() ==false)
    {
        re_connect();
        return; 
    }
      
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
        case DbOperateType::DB_GET_USER_INFO:
            return on_load_user_info(response.body.user_info());
        case DbOperateType::DB_GET_ITEM_LIST:
            return load_user_item_list(response.body.user_item_list());
        default:
            LOG(INFO)<<"unregister db operate "<<response.body.operate_type();
            return -2;
    }
}

int db_connection::on_load_user_info(const db_tb_user& info)
{
    cs_packet_init_client_notf notf;
    notf.body.set_ret(1);
    db_tb_user * user_info = notf.body.mutable_user_info();
    *user_info = info;
    gate_client* client = Singleton<client_manager>::GetInstance()->get_session(info.id());
    if(client != NULL)
    {
        LogicPlayer* player = client->get_player_info();
        player->InitPlayer(info);
        Singleton<LogicPlayerManager>::GetInstance()->AddPlayer(player->GetDbUserInfo().get_id(),player);

        client->send_packet(&notf);
    }
    else
    {
        LOG(INFO)<<"user init info ,connection disconnection"; 
    }


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

void db_connection::update_binder(sql_binder* binder)
{
    if(socket_client::is_online() == false)
    {
        LOG(ERROR)<<"lost connection to db_server!"; 
        return;
    }

    if(!(binder->is_dirty()))
    {
        return; 
    }
    char buffer[2048] = {0};
    int update_size = binder->sql_update(buffer,2048);
    VLOG(3)<<"update sql str size "<<update_size;
    cs_packet_db_common_request request;
    request.body.set_seq(1);
    request.body.set_operate_type(DbOperateType::DB_WORK_UPDATE);
    request.body.set_operate_string(buffer);
    send_packet(&request);
    VLOG(1)<<buffer;
    binder->clear_dirty();
}




















