#ifndef _game_define_h_
#define _game_define_h_

#define MAP_CELL_WIDTH  5
#define MAP_CELL_HEIGHT 5 

#define MOVE_SPEED 5 

#define MAP_MAX_POS 40000


typedef int TID;
typedef int ItemId;
typedef int PlyAttrType;

enum ITEM_TYPE
{
    ITEM_BEGIN = 0,
    ITEM_NORMAL,//normal item 
    ITEM_EQUIPMENT,//equipment item
    ITEM_BOX,//item of box
    ITEM_END,
};

enum
{
    CELL_SLEF  = 0,
    CELL_EAST  = 0x1<<1,
    CELL_SOUTH = 0x1<<2,
    CELL_WEST  = 0x1<<3,
    CELL_NORTH = 0x1<<4,
    CELL_SOUTH_EAST = CELL_EAST|CELL_SOUTH,
    CELL_SOUTH_WEST = CELL_WEST|CELL_SOUTH,
    CELL_NORTH_EAST = CELL_NORTH|CELL_EAST,
    CELL_NORTH_WEST = CELL_NORTH|CELL_WEST,
};

enum
{
    PLY_ATTR_STR,//强壮
    PLY_ATTR_ING,//智力
    PLY_ATTR_AGC,//敏捷
    PLY_ATTR_ATTACK,//
    PLY_ATTR_DEFENSE,//
    PLY_ATTR_END,
};


enum CARRER_TYPE
{
    Soldider,
    Archer,
    Wizard,
};



#endif
