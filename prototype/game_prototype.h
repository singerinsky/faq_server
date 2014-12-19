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
        void Reload();
    public:
        NpcDataPrototype _npc_data_prototype;        
};

#define GameDataProto Singleton<GamePrototype>::GetInstance()
#define NpcDataProto  Singleton<GamePrototype>::GetInstance()->GetNpcDataPrototype()
#endif
