#ifndef _NpcObject_h_
#define _NpcObject_h_

#include "game_define.h"
#include "map_manager.h"

class NpcObject
{
    public:
        NpcObject(int npc_id)
        {
        }

        void init();
        int   get_hp(){return _hp;} 
        void  set_hp(int new_hp){_hp = new_hp;} 

        int   get_mp(){return _mp;} 
        void  set_mp(int new_mp){_mp = new_mp;} 
    private:
        Position pos_; 
        int  _attr[PLY_ATTR_END];
        int  _hp;
        int  _mp;
};


#endif
