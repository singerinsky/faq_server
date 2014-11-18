#ifndef _NpcObject_h_
#define _NpcObject_h_

#include "game_define.h"
#include "map_manager.h"
#include "fighter.h"

class NpcObject:public Fighter
{
    public:
        NpcObject(int npc_id)
        {
            _hp = 0;
            _mp = 0;
        }

        void  init();
        int   get_hp(){return _hp;} 
        void  set_hp(int new_hp){_hp = new_hp;} 

        int   get_mp(){return _mp;} 
        void  set_mp(int new_mp){_mp = new_mp;} 
        bool  is_alive(){return _alive;}
    private:
        Position pos_; 
        int  _attr[PLY_ATTR_END];
        int  _hp;
        int  _mp;
        bool _alive;
};
#endif
