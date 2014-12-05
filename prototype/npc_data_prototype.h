#ifndef _NPC_DATA_PROTOTYPE_H_
#define _NPC_DATA_PROTOTYPE_H_

#include <map>
class NpcDataPrototype
{
    public:
        bool Load(const char* file);

    public:
        typedef std::map<int,NpcData> Prototypes;
        Prototypes  _prototype;
};


#endif
