#ifndef _LOGIC_PLAYER_H_
#define _LOGIC_PLAYER_H_

#include "head.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "timer.h"
#include "map_manager.h"
#include "game_define.h"
#include "fighter.h"

class NpcObject;
class gate_client;
class map_object;

class LogicPlayer:public Fighter
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
        void OnSaveTime();
        tb_user& GetDbUserInfo()
        {
            return _user_info; 
        }
    public:
        void set_hp(int hp) 
        {
            _user_info.set_hp(hp); 
        }

        void set_mp(int mp) 
        {
            _user_info.set_mp(mp); 
        }
       
        int get_hp() 
        {
            return _user_info.get_hp(); 
        }

        int get_mp() 
        {
            return _user_info.get_mp(); 
        }
 
        void broad_round_player(packet*);
        void enter_map(int map_id,int x,int y);

        void send_leave_view_notf(player_set_vec_t& leave_set);
        void send_enter_view_notf(player_set_vec_t& enter_set);

    private:
        gate_client* _client;
    protected:
        int  _level;
        int  _exp;
        string _name;

        map_object* _map;
        Position _pos;
        Position _cell_pos;
        tb_user _user_info;
        template_timer<LogicPlayer,&LogicPlayer::OnSaveTime>    _save_timer;

        player_set_vec_t    _player_round_set;
};

#endif

