#include "item_prototype.h"

const ItemTemplate&  ItemTemplatePrototype::GetItemTemplate(TID tid)
{
    auto itr =  _template_map.find(tid);
    return itr.second;
}

bool ItemTemplatePrototype::Load(const char* file)
{
    std::fstream fs(stream,std::ios::in | std::ios::binary);
    if(fs.fail())return false;

    ItemDataGroup data_group_;
    if(!data_group_.ParseFromIstream(&fs))
    {
        return false; 
    }

    for(int i=0;i<data_group_.item_data_size();i++)
    {
        const ItemData &data = data_group_.item_data(i);
        _template_map[data.item_id()] = data;
    }
    return true;
}
