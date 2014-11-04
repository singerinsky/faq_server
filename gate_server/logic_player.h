#ifndef _GATE_CLIENT_H_
#define _GATE_CLIENT_H_

#include "gate_client.h"
#include "head.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "timer.h"
#include "map_manager.h"
#include "game_define.h"

class gate_client;

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
        tb_user& get_db_user_info()
        {
            return _user_info; 
        }

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

