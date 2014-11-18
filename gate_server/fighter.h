#ifndef _fighter_h_
#define _fighter_h_
#include "game_define.h"

enum FighterType
{
    PLAYER,
    NPC, 
};

class Fighter
{
    public:
        Fighter(){}
        int Attack(Fighter& f);
        int MagicAttack(Fighter& f,int skill_id);
        virtual void set_hp(int hp) = 0;
        virtual void set_mp(int hp) = 0;
        virtual int  get_hp() = 0;
        virtual int  get_mp() = 0;
    public:
        int  _attr[PLY_ATTR_END];
};


#endif
