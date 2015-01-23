#ifndef _ITEM_H_
#define _ITEM_H_

#include "game_define.h"
#include "item_prototype.h"

class Item:public ItemTemplate
{
    public:
        Item()
        {

        }

        static void      CreateItemByTid(TID template_id);
        int       GetItemCount(){return _item_count;}
        int       ModiferCount(int modifer_value);
        int       Merge(Item& item);

    private:
        int     _item_count;
};

#endif
