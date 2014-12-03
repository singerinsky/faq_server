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
        virtual ~Fighter(){}
        int Attack(Fighter& f);
        int MagicAttack(Fighter& f,int skill_id);
        virtual void SetHp(int hp) = 0;
        virtual void SetMp(int hp) = 0;
        virtual int  GetHp() = 0;
        virtual int  GetMp() = 0;
    public:
        int  _attr[PLY_ATTR_END];
};


#endif
