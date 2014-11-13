#ifndef _map_manager_h_
#define _map_manager_h_
#include "singleton.h"
#include <set>
#include <string>
#include <vector>

class NpcObject;
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
struct map_cell
{
    Position _pos; 
    set<LogicPlayer*>   _player_set;
};


class map_object
{
    public:
        void init(std::string);
        bool init_map_data(std::string,int,int);
    private:
        vector<map_cell>    _all_cell;
        int                 _map_id;
        vector<NpcObject*> _all_npc;
};

class map_manager:public Singleton<map_manager>
{
    public:
        friend Singleton<map_manager>;
    public:
        bool init();
};


#endif
