#ifndef _GATE_CLIENT_H_
#define _GATE_CLIENT_H_

#include  "gate_client.h"
#include "head.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "timer.h"

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
        void set_pos_x(int x)
        {
            _x = x; 
        }

        void set_pos_y(int y)
        {
            _y = y; 
        }

        bool operator==(const Position& pos)
        {
            return ((pos.pos_x() == pos_x()) && (pos.pos_y()== pos_y())); 
        }

        bool operator!=(const Position& pos)
        {
            return ((pos.pos_x() != pos_x()) || (pos.pos_y()!= pos_y())); 
        }

        int square_distance_to(const Position& pos)
        {
            int delt_x = pos.pos_x() - pos_x(); 
            int delt_y = pos.pos_y() - pos_y();
            return delt_y*delt_y + delt_x*delt_x;
        }


        int pos_x()const {return _x;}
        int pos_y()const {return _y;}
    private:
        int _x;
        int _y;
};

class LogicPlayer
{
    public:
        LogicPlayer(){

        };
        ~LogicPlayer(){

        };
        void BindPlayer(gate_client* client)
        {
            _client = client; 
        }

        void InitPlayer(const db_tb_user& user_info);

        void LoadPlayerInfo();

        void Move(int x,int y);
        bool CheckCanMove(int x,int y);

        void SavePlayer();
        void on_savetime();
    private:
        gate_client* _client;
    protected:
        int  _level;
        int  _exp;
        string _name;
        int  _attr[PLY_ATTR_END];
        Position _pos;
        tb_user _user_info;
        template_timer<LogicPlayer,&LogicPlayer::on_savetime>    _save_timer;
};

#endif

