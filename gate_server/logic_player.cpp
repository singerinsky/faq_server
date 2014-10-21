#include "logic_player.h"
#include "db_message.pb.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "gate_application.h"
#include "db_connection.h"

void LogicPlayer::LoadPlayerInfo()
{

}

void LogicPlayer::InitPlayer(const db_tb_user& user_info)
{
    _user_info.load_from_pb(user_info);
    LOG(INFO)<<_user_info.get_user_name();
    _pos.set_pos_x(_user_info.get_pos_x());
    _pos.set_pos_y(_user_info.get_pos_y());
//    gate_application::db_conn_->update_binder(&_user_info);
}

bool LogicPlayer::CheckCanMove(int x,int y)
{
    return true;
}

void LogicPlayer::Move(int x,int y)
{
    if(CheckCanMove(x,y))
    {
        _pos.set_pos_x(x);
        _pos.set_pos_y(y);
        _user_info.set_pos_x(x);
        _user_info.set_pos_y(y);
        LOG(INFO)<<"player "<<_user_info.get_id()<<" move to "<<x<<":"<<y;
    }
}

void LogicPlayer::SavePlayer()
{
    gate_application::db_conn_->update_binder(&_user_info);
}
