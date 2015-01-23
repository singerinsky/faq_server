#include "item.h"
#include "head.h"

int Item::ModiferCount(int modifer_count)
{
    if(modifer_count == 0)
        return 1;
    if(modifer_count + _item_count < 0)
        return -1;
    _item_count += modifer_count;
    return 1;
}

int Item::Merge(Item& item)
{
    assert(item.GetItemType() == GetItemType());
    return 1;
}
