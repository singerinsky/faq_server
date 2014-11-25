#include "npc_object.h"
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
    return true;
}
