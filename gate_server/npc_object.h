#ifndef _NpcObject_h_
#define _NpcObject_h_

#include "game_define.h"
#include "message.pb.h"
#include "map_manager.h"
#include "fighter.h"
#include "state.h"
#include "singleton.h"
#include "timer.h"

class LogicPlayer;
class NpcObject:public Fighter,public StateObject
{
    public:
        NpcObject(int npc_id)
        {
            _npc_id = npc_id;
            _hp = 0;
            _mp = 0;
            _state = NULL;
            init();
        }

        void  init();
        int   GetHp(){return _hp;} 
        void  SetHp(int new_hp){_hp = new_hp;} 

        int   GetMp(){return _mp;} 
        void  SetMp(int new_mp){_mp = new_mp;} 
        bool  is_alive(){return _alive;}
        int   get_id(){return _npc_id;}
        void  set_name(std::string name)
        {
            _nickname = name;
        }
        std::string get_name()
        {
            return _nickname;
        }
        void  set_player_round(player_set_vec_t& ply_vec)
        {
            _player_round_set = ply_vec; 
        }

        bool  enter_map(map_object*,Position& pos);
        void  move(Position pos); 
        void  fill_npc_info(NpcInfo* info);
        void  show_npc_around();
        LogicPlayer* get_nearest_player();

        void SendLeaveNpcViewNotf(player_set_vec_t& leave_set_vec);           
        void SendNpcEnterViewNotf(player_set_vec_t& enter_set_vec); 
        bool CheckCanMove(Position& pos);
        Position&   GetPos()
        {
            return _pos; 
        }

    private:
        Position _pos; 
        Position _cell_pos;
        int  _attr[PLY_ATTR_END];
        int  _hp;
        int  _mp;
        bool _alive;
        int  _npc_id;
        int  _level;
        string _nickname;
        player_set_vec_t    _player_round_set;
        map_object*         _map_in;
};


class NpcManager:public Singleton<NpcManager>
{

friend  Singleton<NpcManager>;
public:
    void       Init();
    NpcObject* GetNpc(int id);
    void       AddNpc(int id,NpcObject*);
    void       OnTimeOut();

private:
    template_timer<NpcManager,&NpcManager::OnTimeOut>    _m_timer;
    std::map<int,NpcObject*>    _all_npc;
};
#define NpcManagerPtr NpcManager::GetInstance()
#endif
