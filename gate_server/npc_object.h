#ifndef _NpcObject_h_
#define _NpcObject_h_

#include "game_define.h"
#include "message.pb.h"
#include "map_manager.h"
#include "fighter.h"
#include "state.h"

class NpcObject:public Fighter,StateObject
{
    public:
        NpcObject(int npc_id)
        {
            _npc_id = npc_id;
            _hp = 0;
            _mp = 0;
            _state = NULL;
        }

        void  init();
        int   get_hp(){return _hp;} 
        void  set_hp(int new_hp){_hp = new_hp;} 

        int   get_mp(){return _mp;} 
        void  set_mp(int new_mp){_mp = new_mp;} 
        bool  is_alive(){return _alive;}
        int   get_id(){return _npc_id;}
        void  set_player_round(player_set_vec_t& ply_vec)
        {
            _player_round = ply_vec; 
        }

        bool  enter_map(map_object*,Position& pos);
        void  fill_npc_info(NpcInfo* info);
        void  show_npc_around();

    private:
        Position _pos; 
        Position _cell_pos;
        int  _attr[PLY_ATTR_END];
        int  _hp;
        int  _mp;
        bool _alive;
        int  _npc_id;
        int  _level;
        string _nickname;
        player_set_vec_t    _player_round;
        map_object*         _map_in;
};
#endif
