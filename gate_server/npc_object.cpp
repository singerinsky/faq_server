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
    _map_in->fill_all_player_cells(_cell_pos,&_player_round);
    _map_in->get_npc_incell(_cell_pos)->insert(this);
    //show_npc_around();
    return true;
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
    auto itr = _player_round.begin();
    double distance = 1000.;
    LogicPlayer* near_player = NULL;
    while(itr != _player_round.end())
    {
        auto vec_itr = (*itr)->begin();    
        while(vec_itr != (*itr)->end())
        {
            double temp = (*vec_itr)->get_distance(_pos);
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
    _m_timer.set_expire(100); 
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
    _m_timer.set_expire(100);
}


