#ifndef _fighter_h_
#define _fighter_h_

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
        virtual void set_hp(int hp) = 0;
        virtual void set_mp(int hp) = 0;
        virtual void get_hp() = 0;
        virtual void get_mp() = 0;
    private:
        int  _attr[PLY_ATTR_END];
};


#endif
