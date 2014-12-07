#include "npc_data_prototype.h"
#include "../common/head.h"
#include <fstream>
#include "npc_data.pb.h"

bool NpcDataPrototype::Load(const char* stream)
{
    std::fstream fs(stream,std::ios::in | std::ios::binary);
    if(fs.fail())return false;

    NpcDataGroup data_group_;
    if(!data_group_.ParseFromIstream(&fs))
    {
        return false; 
    }

    for(int i=0;i<data_group_.npc_data_size();i++)
    {
        const NpcData &data = data_group_.npc_data(i);
        LOG(INFO)<<data.npc_name()<<";;;;;;;;;;;;;;;;;;;;;";
    }

    return true;
}
