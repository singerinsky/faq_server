#include "logic_player.h"
#include "timer.h"
#include "db_message.pb.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "gate_application.h"
#include "db_connection.h"
#include "map_manager.h"
#include "npc_object.h"
#include <iterator>
#include <algorithm>
#include "message_define.h"
#include "gate_client.h"

void LogicPlayer::LoadPlayerInfo()
{

}

void LogicPlayer::InitPlayer(const db_tb_user& user_info)
{
    _user_info.load_from_pb(user_info);
    LOG(INFO)<<_user_info.get_user_name()<<" init data from db";
    _pos.set_pos_x(_user_info.get_pos_x());
    _pos.set_pos_y(_user_info.get_pos_y());
    _save_timer.set_owner(this);
    _save_timer.set_expire(10000);
    enter_map(_user_info.get_map_id(),_pos.pos_x(),_pos.pos_y());
//    gate_application::db_conn_->update_binder(&_user_info);
}

bool LogicPlayer::CheckCanMove(int x,int y)
{
    return true;
}

void LogicPlayer::Move(int x,int y)
{
    if((x == _user_info.get_pos_x()) && (y == _user_info.get_pos_y()))
        return;
    if(CheckCanMove(x,y))
    {
        Position rst(x,y),delt;
        int step_count = _map->step(_pos,rst,&delt);
        if(step_count == -1)
            return;
        _pos.modify_pos(delt);
        _user_info.set_pos_x(_pos.pos_x());
        _user_info.set_pos_y(_pos.pos_y());

        Position new_cell_pos;
        _map->map2cell(_pos,new_cell_pos);
        if(new_cell_pos != _cell_pos)
        {
           _map->get_player_incell(_cell_pos)->erase(this);
           _map->get_player_incell(new_cell_pos)->insert(this);
           player_set_vec_t new_set,enter_set,leave_set; 
           _map->fill_all_player_cells(new_cell_pos,&new_set);
           set_difference(new_set.begin(),new_set.end(),_player_round_set.begin(),_player_round_set.end(),std::inserter(enter_set,enter_set.begin()));
           set_difference(_player_round_set.begin(),_player_round_set.end(),new_set.begin(),new_set.end(),std::inserter(leave_set,leave_set.begin()));
           _player_round_set.clear();
           _map->fill_all_player_cells(new_cell_pos,&_player_round_set);

           //send 离开自己视野的玩家列表
            send_leave_view_notf(leave_set);           
           //send 玩家自己在他们视野里的列表
           ////send enter view
            send_player_enter_view_notf(enter_set); 
           //
           //
        }

        LOG(INFO)<<"player "<<_user_info.get_id()<<" move to "<<_user_info.get_pos_x()<<":"<<_user_info.get_pos_y();
        //show all new npc
        set<NpcObject*> all_npc;
        _map->get_all_npc_round(_pos,all_npc);
        for(auto itr = all_npc.begin();itr!= all_npc.end();itr++)
        {
            LOG(INFO)<<"NPC "<<(*itr)->get_id()<<" around you"; 
        }
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
    //if(_user_info.get_map_id() == map_id)
    //    return;
    map_object* map_enter= Singleton<map_manager>::GetInstance()->get_map(map_id);    
    if(map_enter == NULL)
    {
        LOG(ERROR)<<"require enter a unexist map";
        return; 
    }

    LOG(INFO)<<"player "<< _user_info.get_id()<<" require enter map "<<map_id <<" x:"<<x<<"  y:"<<y;
    _map =  map_enter; 
    _user_info.set_map_id(map_id);
    _user_info.set_pos_x(x);
    _user_info.set_pos_y(y);
    _pos.set_pos_x(x);
    _pos.set_pos_y(y);
    _map->map2cell(_pos,_cell_pos);
    _player_round_set.clear();
    _map->fill_all_player_cells(_cell_pos,&_player_round_set);
    _npc_round_set.clear();
    _map->fill_all_npc_cells(_cell_pos,&_npc_round_set);
    _map->get_player_incell(_cell_pos)->insert(this);

    send_player_enter_view_notf(_player_round_set);
    send_npc_enter_view_notf(_npc_round_set);
}

void LogicPlayer::send_leave_view_notf(player_set_vec_t& leave_set)
{
    LOG(INFO)<<"send player leave";
}

void LogicPlayer::fill_player_info(PlayerInfo* info)
{
    info->set_player_id(GetDbUserInfo().get_id());
    info->set_player_nickname(GetDbUserInfo().get_user_name());
    info->set_player_level(GetDbUserInfo().get_level());
    info->set_career_id(1);
    info->set_player_status(1);
    PosInfo* pos = info->mutable_pos();
    pos->set_x(GetDbUserInfo().get_pos_x());
    pos->set_y(GetDbUserInfo().get_pos_y());

}

void LogicPlayer::send_player_enter_view_notf(player_set_vec_t& enter_set)
{
    cs_packet_enter_players_notf player_notf;
    auto itr = enter_set.begin();
    for(;itr != enter_set.end();itr++)
    {
        auto ply_itr = (*itr)->begin();
        for(;ply_itr != (*itr)->end(); ply_itr++)
        {
            LogicPlayer* player = *ply_itr;
            PlayerInfo* info = player_notf.body.add_player_info();          
            player->fill_player_info(info);
       }
         
    }
}

void LogicPlayer::send_npc_enter_view_notf(npc_set_vec_t& enter_set)
{
    cs_packet_enter_npcs_notf notf;
    auto itr = enter_set.begin();
    for(;itr != enter_set.end();itr++)
    {
        auto npc_itr = (*itr)->begin();
        for(;npc_itr != (*itr)->end(); npc_itr++)
        {
            NpcObject* npc = *npc_itr;
            NpcInfo* info = notf.body.add_npc_info();
            npc->fill_npc_info(info);
            LOG(INFO)<<"npc "<<npc->get_id()<<" around";
        }
    }
    _client->send_packet(&notf);
}

void LogicPlayer::copy_to(PlayerInfo& info)
{

}
