#ifndef _GATE_CLIENT_H_
#define _GATE_CLIENT_H_

#include  "gate_client.h"
#include "head.h"

class gate_client;
enum
{
    PLY_ATTR_STR,//强壮
    PLY_ATTR_ING,//智力
    PLY_ATTR_AGC,//敏捷
    PLY_ATTR_HP,//生命值
    PLY_ATTR_MP,//魔法值
    PLY_ATTR_END,
};

struct PlayerInfo
{
    int  _level;
    int  _exp;
    string _name;
    int  _attr[PLY_ATTR_END];
};

class LogicPlayer
{
    public:
        LogicPlayer(){};
        ~LogicPlayer(){};
        void BindPlayer(gate_client* client)
        {
            _client = client; 
        }

        void LoadPlayerInfo();

    private:
        gate_client* _client;
        PlayerInfo   _info;
};

#endif

