#ifndef _LOGIC_PLAYER_H_
#define _LOGIC_PLAYER_H_

#include "head.h"
#include "tb_user.pb.h"
#include "tb_user.h"
#include "timer.h"
#include "map_manager.h"
#include "game_define.h"
#include "fighter.h"
#include "message.pb.h"
#include "gate_client.h"

class NpcObject;
class gate_client;
class map_object;

class LogicPlayer:public Fighter
{
    public:
        LogicPlayer()
        {
            _map = NULL;
            _client = NULL;
        };
        virtual ~LogicPlayer()
        {

        };

        void OnLogout()
        {
            LeaveMap();
            SavePlayer(); 
        }
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
        Position& GetPos()
        {
            return _pos; 
        }
    public:
        void SetHp(int hp) 
        {
            _user_info.set_hp(hp); 
        }

        void SetMp(int mp) 
        {
            _user_info.set_mp(mp); 
        }
       
        int GetHp() 
        {
            return _user_info.get_hp(); 
        }

        int GetMp() 
        {
            return _user_info.get_mp(); 
        }

        double GetDistance(Position& pos);
 
        void BroadRoundPlayer(packet*);
        void EnterMap(int map_id,int x,int y);
        map_object* GetMapIn() const 
        {
            return _map;
        }

        void SendLeaveViewNotf(player_set_vec_t& leave_set);
        void SendPlayerEnterViewNotf(player_set_vec_t& enter_set);
        void SendNpcEnterViewNotf(npc_set_vec_t&);
        void CopyTo(PlayerInfo& info);
        void FillPlayerInfo(PlayerInfo* info);
        void LeaveMap();
        int  SendPacket(packet* p)
        {
            if(_client)
            {
                return _client->send_packet(p); 
            }
            return -1; 
        }

    private:
        gate_client* _client;
    protected:
        int         _level;
        int         _exp;
        std::string _name;

        map_object* _map;
        Position    _pos;
        Position    _cell_pos;
        tb_user     _user_info;
        template_timer<LogicPlayer,&LogicPlayer::OnSaveTime>    _save_timer;

        player_set_vec_t    _player_round_set;
        npc_set_vec_t       _npc_round_set;
};


#endif
