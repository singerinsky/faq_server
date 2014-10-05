#ifndef _GATE_CLIENT_H_
#define _GATE_CLIENT_H_

#include  "gate_client.h"
#include "head.h"
class DBUserInfo;

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

class Position
{
    public:
        Position()
        {
            _x = 0;
            _y = 0;
        }
        Position(int x,int y)
        {
            _x = x;
            _y = y;
        }

        bool operator==(const Position& pos)
        {
            return ((pos.pos_x() == pos_x()) && (pos.pos_y()== pos_y()); 
        }

        bool operator!=(const Position& pos)
        {
            return ((pos.pos_x() != pos_x()) || (pos.pos_y()!= pos_y()); 
        }

        int square_distance_to(const Position& pos)
        {
            int delt_x = pos.pos_x() - pos_x(); 
            int delt_y = pos.pos_y() - pos_y();
            return delt_y*delt_y + delt_x*delt_x;
        }


        int pos_x(){return _x;}
        int pos_y(){return _y;}
    private:
        int _x;
        int _y;
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

        void InitPlayer(const DBUserInfo& user_info);

        void LoadPlayerInfo();

    private:
        gate_client* _client;
    protected:
        int  _level;
        int  _exp;
        string _name;
        int  _attr[PLY_ATTR_END];
        Position _pos;
};

#endif

