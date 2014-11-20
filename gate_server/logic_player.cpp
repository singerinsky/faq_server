#include "logic_player.h"
#include "timer.h"
#include "db_message.pb.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "gate_application.h"
#include "db_connection.h"
#include "map_object.h"

void LogicPlayer::LoadPlayerInfo()
{

}

void LogicPlayer::InitPlayer(const db_tb_user& user_info)
{
    _user_info.load_from_pb(user_info);
    LOG(INFO)<<_user_info.get_user_name();
    _pos.set_pos_x(_user_info.get_pos_x());
    _pos.set_pos_y(_user_info.get_pos_y());
    _save_timer.set_owner(this);
    _save_timer.set_expire(10000);
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

void LogicPlayer::OnSaveTime()
{
    SavePlayer();
    _save_timer.set_owner(this);
    _save_timer.set_expire(10000);
}

void LogicPlayer::broad_round_player(packet* data)
{
    std::vector<player_set_t*>::iterator itr = _player_round_set.begin();
    while(itr != _player_round_set.end())
    {
        player_set_t::iterator cell_itr = (*itr)->begin(); 
        while(cell_itr != (*itr)->end())
        {
            cell_itr++; 
            LOG(INFO)<<"player in round";
        }
        itr++;
    }
}

void LogicPlayer::enter_map(int map_id,int x,int y)
{
    if(_user_info.get_map_id() == map_id)
        return;
    map_object map_enter= Singleton<map_manager>::GetInstance()->get_map(map_id);    
    if(map_enter == NULL)
    {
        LOG(ERROR)<<"require enter a unexist map";
        return; 
    }

    LOG(INFO)<<"player "<< _user_info.get_id()<<" require enter map "<<map_id <<" x:"<<x<<"  y:"<<y;
    _map =  map_enter; 
    _user_info.set_map_id(map_id);
}
