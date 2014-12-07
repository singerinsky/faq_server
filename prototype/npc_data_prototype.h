#ifndef _NPC_DATA_PROTOTYPE_H_
#define _NPC_DATA_PROTOTYPE_H_

#include <map>
#include "npc_data.pb.h"
class NpcDataPrototype
{
    public:
        bool Load(const char* file);
        NpcData* GetNpcData(int npc_id);

    public:
        typedef std::map<int,NpcData> Prototypes;
        Prototypes  _prototype;
};


#endif
