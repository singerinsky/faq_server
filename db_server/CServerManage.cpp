#include "CServerManage.h"
#include "CDBhandlerJob.h"
#include "CDBTaskManage.h"

CServerManage* CServerManage::_m_instance;

void GameServerClient::on_timeout(timer_manager* timer_mgr)
{
    if(_connection_status == WAIT_LOGIN || _connection_status == HEART_BEAT_TIME_OUT)
    {
        LOG(INFO)<<"data client check time out in 5's ,should disconnect.";
        fini();
    }
    else
    {
        _timer.set_expired(ServerRun->get_run_ms() + 5000);
        if((_timer_mgr->add_timer(&_timer)) != 0 )
        {
            LOG(INFO)<<"add timer success"; 
        }
    }
}

void GameServerClient::reset()
{
    index = -1;
    _match_list.clear();
    _timer_mgr->del_timer(&_timer);
}

int GameServerClient::on_error()
{
    LOG(INFO)<<"gameserver client disconnet"<<index;
    int temp = index;
    reset();
    fini();
    CServerManage::GetInstance()->RemoveServer(temp);
    return 1;
}

int GameServerClient::process_msg(packet_info* packet)
{
    //to some check like heart beat or other
    int packet_type = packet->type;

    if(packet_type != CS_MSG_GATE_REGISTER_REQ)
    {
        if(_connection_status == WAIT_LOGIN)
        {
            LOG(ERROR)<<"Recived Message Before Register!"; 
            return 1;
        }
    
    }

    int process_ret = 0;
    switch(packet_type)
    {
        case CS_MSG_CLIENT_LOGIN_REQ:
            do_check_client_log(packet);
            break;
        case  CS_MSG_SOCCER_PLAYER_REQ:
            do_get_soccer_player_info(packet);
            //process_ret = _packet.decode(packet->data,packet->size);
            break;
        case CS_MSG_GATE_REGISTER_REQ:
            do_register_gate(packet);
            break;
        case CS_MSG_COMMON_DATA_UPDATE_NTF: 
            do_common_update_del(packet);
            break;
        default:
            LOG(ERROR)<<"unknown message "<<packet_type;
    }
    return 1;

}

int GameServerClient::do_get_soccer_player_info(const packet_info* packet)
{
    cs_soccer_player_request request; 
    if(request.decode(packet->data,packet->size) != packet->size)return -1;
    LOG(INFO)<<"Message get soccer player"<<get_socket_fd()<<" info:size  "<<packet->size;
    _connection_status = ALREADY_LOGIN;
    cs_soccer_player_response response;
    response.body.set_player_id(19);
    response.body.set_player_name("guanlei");
    response.body.set_age(29);
    send_packet_msg(&response);
}

int GameServerClient::do_common_update_del(const packet_info* packet)
{
    cs_data_common_update_ntf ntf;
    if(ntf.decode(packet->data,packet->size) != packet->size)return -1;
    db_event* event = new db_event();
    event->operate_type = COMMON_UPDATE_DEL;
    event->seq = ntf.body.key();
    event->sql_str = ntf.body.sql_str();
    CDBTaskManage::GetInstance()->AddTaskEvent(event);
    return 1;
}


int GameServerClient::do_check_client_log(const packet_info* packet)
{
    cs_client_login_request request;
    if(request.decode(packet->data,packet->size) != packet->size)return -1;
    LOG(INFO)<<"Message get soccer player"<<get_socket_fd()<<" info:size  "<<packet->size;
    int player_id = request.body.player_id();
    std::string player_pwd = request.body.player_pwd();
    std::string md5_code = request.body.md5_code();
    LOG(INFO)<<"client "<<player_id<<" use password"<<player_pwd.c_str()<<" with code"<<md5_code.c_str();
    char    str_sql[256] = {0};
    snprintf(str_sql,256,"select * from  u_account where uid=%d and player_pwd='%s'",player_id,player_pwd.c_str());
    db_event *event = new db_event();
    event->operate_type = QUERY_LOGIN_INFO;
    event->seq = index;
    event->sql_str = str_sql; 
    CDBTaskManage::GetInstance()->AddTaskEvent(event);
    return 1; 
}

int GameServerClient::do_register_gate(const packet_info* packet)
{
    cs_gate_register_request request;
    if(request.decode(packet->data,packet->size) != packet->size)return -1;
    LOG(INFO)<<"Message register gate server "<<get_socket_fd()<<" info:size  "<<packet->size;

    int server_index = request.body.server_index();
    if(CServerManage::GetInstance()->GetGameServerByIndex(server_index) != NULL)
    {
        LOG(ERROR)<<"same game client has regitster"; 
        return -1;
    }
    shared_ptr<GameServerClient> ptr(this);
    CServerManage::GetInstance()->RegisterServer(server_index, ptr);
    ptr->index = server_index;
    ptr->set_connection_status(ALREADY_LOGIN);
    LOG(INFO)<<"gate server"<<server_index<<" register";
    return 1; 
}

