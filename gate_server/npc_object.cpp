#include "npc_object.h"
#include "head.h"
#include "map_manager.h"

void NpcObject::init()
{

}

bool NpcObject::enter_map(map_object* p_map,Position& pos)
{
    _map_in = p_map;
    _pos = pos;
    Position cell_pos;
    _map_in->map2cell(_pos,cell_pos);
    _map_in->fill_all_player_cells(cell_pos,&_player_round);
    _map_in->get_npc_incell(cell_pos)->insert(this);
    npc_set_vec_t test_vec;
    _map_in->fill_all_npc_cells(cell_pos,&test_vec);
    npc_set_vec_t::iterator itr = test_vec.begin();
    while( itr != test_vec.end())
    {
        if((*itr)->size() > 0)
        {
            LOG(INFO)<<"npc "<< (*(*itr)->begin())->get_id();
        }
        
        itr++; 
    }
    return true;
}
