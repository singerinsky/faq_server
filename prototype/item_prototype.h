#ifndef _ITEM_PROTOTYPE_H_
#define _ITEM_PROTOTYPE_H_

#include "game_define.h"
#include "../common/singleton.h"
#include <map>
using namespace std;

class ItemTemplate
{
    public:
        ItemTemplate()
        {
        
        }
        void Init()
        {
        }
        TID GetTid(){return _item_template_id;}
        ITEM_TYPE GetItemType(){return _item_type;}
    protected:
        TID _item_template_id;
        ITEM_TYPE   _item_type;
        PlyAttrType _item_attr[PLY_ATTR_END];
};


class ItemTemplatePrototype:public Singleton<ItemTemplatePrototype>
{
    public:
        bool Load(const char* file);
        friend Singleton<ItemTemplatePrototype>;
        const ItemTemplate&  GetItemTemplate(TID tid);

    private:
        std::map<TID,ItemTemplate> _template_map;
};

#endif
