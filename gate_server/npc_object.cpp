#include "npc_object.h"
#include "head.h"
#include "map_manager.h"
#include "message.pb.h"
#include "logic_player.h"
#include "state.h"


template<> 
NpcManager* Singleton<NpcManager>::_instance = 0;

void NpcObject::init()
{
    NpcWaitState *state = new NpcWaitState();
    state->SetOwner(this);
}

bool NpcObject::enter_map(map_object* p_map,Position& pos)
{
    _map_in = p_map;
    _pos = pos;
    _map_in->map2cell(_pos,_cell_pos);
    _map_in->fill_all_player_cells(_cell_pos,&_player_round_set);
    _map_in->get_npc_incell(_cell_pos)->insert(this);
    //show_npc_around();
    return true;
}

bool NpcObject::CheckCanMove(Position& pos)
{
    return true;
}

void NpcObject::move(Position pos)
{
    VLOG(1)<<"npc move to"<<pos.pos_x()<<":"<<pos.pos_y();
    if(pos == _pos)
        return;
    if(CheckCanMove(pos))
    {
        Position rst = pos;
        Position delt;
        int step_count = _map_in->step(_pos,rst,&delt);
        if(step_count == -1)
        {
            return;
        }
        _pos.modify_pos(delt);

        Position new_cell_pos;
        _map_in->map2cell(_pos,new_cell_pos);
        if(new_cell_pos != _cell_pos)
        {
           _cell_pos = new_cell_pos;
           _map_in->get_npc_incell(_cell_pos)->erase(this);
           _map_in->get_npc_incell(new_cell_pos)->insert(this);
           player_set_vec_t new_set,enter_set,leave_set; 
           _map_in->fill_all_player_cells(new_cell_pos,&new_set);
           set_difference(new_set.begin(),new_set.end(),_player_round_set.begin(),_player_round_set.end(),std::inserter(enter_set,enter_set.begin()));
           set_difference(_player_round_set.begin(),_player_round_set.end(),new_set.begin(),new_set.end(),std::inserter(leave_set,leave_set.begin()));
           _player_round_set.clear();
           _map_in->fill_all_player_cells(new_cell_pos,&_player_round_set);

           //send 离开自己视野的玩家列表
            SendLeaveNpcViewNotf(leave_set);           
           //send 玩家自己在他们视野里的列表
           ////send enter view
            SendNpcEnterViewNotf(enter_set); 
           //
           //
        }

        LOG(INFO)<<"npc "<<get_id()<<" move to "<<_pos.pos_x()<<":"<<_pos.pos_y();
        //show all new npc
        set<NpcObject*> all_npc;
        _map_in->get_all_npc_round(_pos,all_npc);
        for(auto itr = all_npc.begin();itr!= all_npc.end();itr++)
        {
            LOG(INFO)<<"NPC "<<(*itr)->get_id()<<" around you"; 
        }
    }
}

void NpcObject::show_npc_around()
{
    npc_set_vec_t test_vec;
    test_vec.clear();
    _map_in->fill_all_npc_cells(_cell_pos,&test_vec);
    npc_set_vec_t::iterator itr = test_vec.begin();
    LOG(INFO)<<"npc "<<_npc_id <<" cell "<<_cell_pos.pos_x()<<":"<<_cell_pos.pos_y();
    while( itr != test_vec.end())
    {
        if((*itr)->size() > 0)
        {
            LOG(INFO)<<"npc "<<_npc_id<<"around has "<< (*(*itr)->begin())->get_id();
        }
        itr++; 
    }
}


void NpcObject::fill_npc_info(NpcInfo* info)
{
    info->set_npc_id(get_id());
    info->set_npc_nickname(_nickname);
    info->set_npc_level(_level);
    info->set_totoal_hp(_hp);
    info->set_current_hp(_hp);
    PosInfo* pos = info->mutable_pos();
    pos->set_x(_pos.pos_x());
    pos->set_y(_pos.pos_y());
}

        
LogicPlayer* NpcObject::get_nearest_player()
{
    auto itr = _player_round_set.begin();
    double distance = 1000.;
    LogicPlayer* near_player = NULL;
    while(itr != _player_round_set.end())
    {
        auto vec_itr = (*itr)->begin();    
        while(vec_itr != (*itr)->end())
        {
            double temp = (*vec_itr)->GetDistance(_pos);
            if(distance > temp)
            {
                distance = temp; 
                near_player = *vec_itr; 
            }
            vec_itr++;
        }
        itr++;
    }
    return near_player;
}

void NpcManager::Init()
{
    _m_timer.set_owner(this); 
    _m_timer.set_expire(1000); 
}

NpcObject* NpcManager::GetNpc(int id)
{
    auto itr = _all_npc.find(id);
    if(itr == _all_npc.end())
    {
        return NULL;
    }
    return itr->second;
}

void  NpcManager::AddNpc(int id,NpcObject* npc)
{
    _all_npc[id] = npc;
}

void  NpcManager::OnTimeOut()
{
    VLOG(2)<<"run npc state ....";
    auto itr = _all_npc.begin();
    for(;itr != _all_npc.end();itr++)
    {
        NpcObject* npc = itr->second;
        if(npc->GetState() != NULL)
        {
            npc->GetState()->Run();
        }
    }
    _m_timer.set_expire(1000);
}

void NpcObject::SendLeaveNpcViewNotf(player_set_vec_t& leave_set_vec)
{
    //cs_packet_leave_npc_notf notf;

}

void NpcObject::SendNpcEnterViewNotf(player_set_vec_t& enter_set_vec)
{

}


