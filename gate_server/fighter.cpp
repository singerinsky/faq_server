#include "fighter.h"


int Fighter::Attack(Fighter& f)
{
    int attack_rst = _attr[PLY_ATTR_ATTACK] - f._attr[PLY_ATTR_DEFENSE];
    if(attack_rst > 0)
    {
        f.set_hp(attack_rst); 
    }
    return 0;
}

int Fighter::MagicAttack(Fighter& f,int skill_id)
{
    return 0;
}
 
