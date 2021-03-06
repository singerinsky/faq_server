#ifndef _map_manager_h_
#define _map_manager_h_
#include "singleton.h"
#include <set>
#include <string>
#include <vector>
#include <bitset>
#include "game_define.h"
#include <map>

class NpcObject;
class packet;
using namespace std;

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

        void modify_pos(Position& pos)
        {
            _x += pos.pos_x(); 
            _y += pos.pos_y(); 
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

class LogicPlayer;
class map_cells
{
    public:
        int                 _cell_index;
        set<LogicPlayer*>   _player_set;
        set<NpcObject*>     _npc_set;
    public:
        void                broadcast_region(packet* p);
        void                enter(LogicPlayer*);
        void                leave(LogicPlayer*);
};

typedef std::set<LogicPlayer*> player_set_t;
typedef std::vector<player_set_t*> player_set_vec_t;

typedef std::set<NpcObject*> npc_set_t;
typedef std::vector<npc_set_t*> npc_set_vec_t;


class map_object
{
    public:
        ~map_object()
        {
            delete[] _cells_vec;
        }
        void init(std::string);
        bool init_map_data(std::string,int,int);
        void init_map_region();
        bool is_vaild(Position& pos)
        {
            return (pos.pos_x() >= 0) && (pos.pos_x() <= _map_x) &&  (pos.pos_y() >= 0) && (pos.pos_y() <= _map_y);
        }
        bool map2cell(Position& src_pos,Position& rst_pos);
        int  pos2off(Position& pos)
        {
            return pos.pos_y()*_map_x+ pos.pos_x();
        }
        bool is_set(Position& pos)
        {
            int index = pos2off(pos); 
            return _map_pos.test(index);
        }
        map_cells*    get_cells(Position pos,int cell_offset = 0);
        player_set_t* get_player_incell(Position pos);
        void          fill_all_player_cells(Position& pos, player_set_vec_t*);
        npc_set_t*    get_npc_incell(Position pos);
        void          fill_all_npc_cells(Position& pos, npc_set_vec_t*);
        void          get_all_npc_round(Position& pos,std::set<NpcObject*>& npc_set);
        int           step(Position src_pos,Position rst_pos,Position* delt_pos);
        int           map_id(){return _map_id;}
    private:
        int                 _map_id;
        int                 _map_x;
        int                 _map_y;

        int                 _map_width;
        int                 _map_height;
        vector<NpcObject*>  _all_npc;
        std::bitset<MAP_MAX_POS>    _map_pos;
        map_cells*          _cells_vec;
};


class map_manager:public Singleton<map_manager>
{
    public:
        friend Singleton<map_manager>;
    public:
        bool init();
        map_object* get_map(int id);
    private:
        std::map<int ,map_object*> _all_map;
};

class MapPlayerVisitor
{
    public:
        MapPlayerVisitor(){}
        virtual ~MapPlayerVisitor(){}
        virtual void visit(LogicPlayer* player) = 0; 
};

class MapNpcVisitor
{
    public:
        MapNpcVisitor(){}
        virtual ~MapNpcVisitor(){}
        virtual void visit(NpcObject* npc) = 0; 
};


void visit_all_map_player(player_set_vec_t& t,MapPlayerVisitor*);
void visit_all_map_npc(npc_set_vec_t& t,MapNpcVisitor*);

#endif
