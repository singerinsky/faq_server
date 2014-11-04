#ifndef _npc_object_h_
#define _npc_object_h_

#include "game_define.h"
#include "map_manager.h"

class npc_object
{
    public:
        npc_object(int npc_id)
        {
        }

        void init();
    private:
        Position pos_; 
        int  _attr[PLY_ATTR_END];
        int  _hp;
        int  _mp;
};


#endif
