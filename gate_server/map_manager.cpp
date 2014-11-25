#include "map_manager.h"
#include <sys/types.h>
#include <dirent.h>
#include "util_file.h"
#include "head.h"
#include "npc_object.h"
#include "packet.h"

template<> 
map_manager* Singleton<map_manager>::_instance = 0;

//TODO 
void map_cells::broadcast_region(packet* p)
{

}

//TODO
void map_cells::enter(LogicPlayer* player)
{
    _player_set.insert(player);
}

//TODO
void map_cells::leave(LogicPlayer* player)
{
   _player_set.erase(player); 
}

bool map_manager::init()
{
    vector<string> all_file;
    string map_path = "./game_config/map/";
    get_file_in_dir(map_path.c_str(),all_file); 

    for(auto itr = all_file.begin();itr != all_file.end();itr++)
    {
        LOG(INFO)<<*itr; 
        map_object* pmap = new map_object();
        pmap->init(map_path+*itr); 
    }
    return true;
}

void map_object::init(std::string map_file)
{
    LOG(INFO)<<map_file;

    TiXmlDocument* doc = new TiXmlDocument;
    bool load_rst = doc->LoadFile(map_file.c_str());
    if(!load_rst)
    {
        LOG(ERROR)<<"load map"<<map_file<<" failed!"; 
        exit(-1);
    }

    TiXmlNode* node = doc->FirstChild("map");
    TiXmlElement* ele_node = node->ToElement();
    int length,width=0;
    ele_node->Attribute("id",&_map_id);
    ele_node->Attribute("length",&length);
    ele_node->Attribute("width",&width);
    TiXmlNode* map_data= node->FirstChild();  
    TiXmlElement* ele_map_data = map_data->ToElement();
    std::string map_data_str = ele_map_data->Attribute("data");
    LOG(INFO)<<"load map "<<map_file<<" success!";
    if(init_map_data(map_data_str,width,length) == false)
    {
        LOG(ERROR)<<"init map data "<<map_file<<" error";
        assert(false);
    }
    TiXmlNode* npc_node = node->FirstChild("npc_list");
    if(npc_node)
    {
        TiXmlNode* child_node = NULL;//npc_node->FirstChild();
        while((child_node = npc_node->IterateChildren(child_node)) != NULL)
        {
            TiXmlElement* ele = child_node->ToElement();
            int npc_id = 0;
            ele->Attribute("npc_id",&npc_id);
            NpcObject* object = new NpcObject(npc_id);
            _all_npc.push_back(object);
            LOG(INFO)<<npc_id;
        }
    }

    delete doc;
}

bool map_object::map2cell(Position& src_pos,Position& rst_pos)
{
    if(!is_vaild(src_pos))return false;
    rst_pos.set_pos_x(src_pos.pos_x()/MAP_CELL_WIDTH);
    rst_pos.set_pos_y(src_pos.pos_y()/MAP_CELL_HEIGHT);
    return true;
}

bool map_object::init_map_data(std::string data,int w,int h)
{
    _map_width = w;
    _map_height = h;
    std::vector<std::string> data_split;
    split(data,',',data_split);

    if(data_split.size() != h*w)
        return false;

    int index = 0;
    for(auto itr:data_split)
    {
        int map_type = atoi((itr).c_str()); 
        if(map_type == 1)
        {
            _map_pos.set(index);
        }
    }
    
    _cells_vec = new map_cells[((_map_height+ MAP_CELL_HEIGHT - 1)/MAP_CELL_HEIGHT)*((_map_width + MAP_CELL_WIDTH - 1)/MAP_CELL_WIDTH)];    
//     auto test_itr = data_split.begin();
//     for(;test_itr != data_split.end();test_itr++)
//     {
//         LOG(INFO)<<atoi((test_itr)->c_str()); 
//     }
    return true;
}

map_cells* map_object::get_cells(Position pos,int cell_offset)
{
    assert(cell_offset<=8);
    assert(cell_offset>=0);
    static char cell_seq[] ={
        CELL_SLEF  ,
        CELL_EAST  ,
        CELL_SOUTH ,
        CELL_WEST  ,
        CELL_NORTH ,
        CELL_SOUTH_EAST,
        CELL_SOUTH_WEST,
        CELL_NORTH_EAST,
        CELL_NORTH_WEST
    };

    char cell_offset_value = cell_seq[cell_offset];

    if(CELL_EAST&cell_offset_value)
    {
        pos.set_pos_x(pos.pos_x()+1);
    }
    if(CELL_WEST&cell_offset_value)
    {
        pos.set_pos_x(pos.pos_x()-1); 
    }
    if(CELL_NORTH&cell_offset_value)
    {
        pos.set_pos_y(pos.pos_y() - 1); 
    }
    if(CELL_SOUTH&cell_offset_value)
    {
        pos.set_pos_y(pos.pos_y() + 1); 
    }

    if(pos.pos_x()< 0 || pos.pos_y() < 0)return NULL;
    if(pos.pos_x() > _map_width)return NULL;
    if(pos.pos_y() > _map_height) return NULL;
    return _cells_vec + pos.pos_y()*_map_width + pos.pos_x();
}

player_set_t* map_object::get_player_incell(Position pos)
{
    map_cells* cell = get_cells(pos,0);
    if(cell == NULL)return NULL;
    return &(cell->_player_set);
}
void map_object::fill_all_player_cells(Position& pos,player_set_vec_t* ply_vec)
{
    for(int i=0;i<=8;i++)
    {
        map_cells* cell = get_cells(pos,i); 
        if(cell == NULL)continue;
        ply_vec->push_back(&(cell->_player_set));
    }
}

map_object* map_manager::get_map(int map_id)
{
    auto itr = _all_map.find(map_id);
    if(itr != _all_map.end())
    {
        return itr->second;    
    }
    return NULL;
}

int map_object::step(Position src_pos,Position rst_pos,Position* delt_pos)
{
    delt_pos->set_pos_x(rst_pos.pos_x() - src_pos.pos_y());
    delt_pos->set_pos_y(rst_pos.pos_y() - src_pos.pos_y());
    int step_count = 0;
    if(delt_pos->pos_x() == delt_pos->pos_y() || delt_pos->pos_x() == -delt_pos->pos_y())
    {
        step_count = abs(delt_pos->pos_x()); 
    }
    else if(delt_pos->pos_x() == 0)
    {
        step_count = abs(delt_pos->pos_y()); 
    }
    else if(delt_pos->pos_y() == 0)
    {
        step_count = abs(delt_pos->pos_x()); 
    }
    else
    {
        return -1; 
    }

    if(step_count != 0)
    {
        delt_pos->set_pos_x(delt_pos->pos_x()/step_count); 
        delt_pos->set_pos_y(delt_pos->pos_y()/step_count); 
    }

    for(int i=0;i<step_count;i++)
    {
        src_pos.set_pos_x(src_pos.pos_x() + delt_pos->pos_x()); 
        src_pos.set_pos_y(src_pos.pos_y() + delt_pos->pos_y()); 
        if(!is_set(src_pos))return -1;
    }
    return step_count;
}

void map_object::get_all_npc_round(Position& pos,std::set<NpcObject*>& npc_set)
{
    for(int i=0;i<=8;i++)
    {
        map_cells* cell = get_cells(pos,i); 
        if(cell == NULL)continue;
        npc_set.insert(cell->_npc_set.begin(),cell->_npc_set.end());
    }

}
