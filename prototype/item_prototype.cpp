#include "item_prototype.h"

const ItemTemplate&  ItemTemplatePrototype::GetItemTemplate(TID tid)
{
    auto itr =  _template_map.find(tid);
    return itr.second;
}
