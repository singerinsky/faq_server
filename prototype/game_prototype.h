#ifndef _GAME_PROTOTYPE_H_
#define _GAME_PROTOTYPE_H_

#include "npc_data_prototype.h"
#include "../common/singleton.h"

class GamePrototype:public Singleton<GamePrototype>
{
    public:
        friend Singleton<GamePrototype>;
        bool Init();
        NpcDataPrototype* GetNpcDataPrototype()
        {
            return &_npc_data_prototype; 
        }
    public:
        NpcDataPrototype _npc_data_prototype;        
};

#define NpcDataProto  Singleton<GamePrototype>::GetInstance()->GetNpcDataPrototype()
#endif
