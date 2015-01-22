#include "gate_client.h"
#include "actions_mananger.h"
#include "gate_application.h"
#include "message_define.h"
#include "db_message.pb.h"
#include "sql_define.h"
#include "db_connection.h"
#include "client_service.h"
#include "logic_player.h"
#include "player_manager.h"

gate_client::~gate_client()
{

}

int gate_client::process_msg(packet_info* info)
{
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info,this);
    return 1;
}

void gate_client::on_error()
{
    LOG(INFO)<<"gate client "<<_role_id<<" disconnection ";
    fini();
}

void gate_client::init_timer()
{
    _m_timer.set_owner(this); 
    _m_timer.set_expire(2000); 
}

void gate_client::on_timeout()
{
    //on_error(NULL);
}

void gate_client::init()
{
    _player_info = LogicPlayer::CreateObject();
    _player_info->BindPlayer(this);
}

void gate_client::kick_out()
{
    socket_client::disconnection();
    on_error(); 
}

void gate_client::fini()
{
    _login_status = UN_LOGIN;
    if( _player_info != nullptr)
    {
        _player_info->OnLogout(); 
        LogicManagerPtr->RemovePlayer(_role_id);
        _player_info = nullptr;
    }

    Singleton<client_manager>::GetInstance()->remove_session(_role_id);
}

