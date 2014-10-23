#include "map_manager.h"
#include <sys/types.h>
#include <dirent.h>
#include "util_file.h"
#include "head.h"

template<> 
map_manager* Singleton<map_manager>::_instance = 0;


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

    TiXmlNode* npc_node = node->FirstChild("npc_list");
    if(npc_node)
    {
        TiXmlNode* child_node = NULL;//npc_node->FirstChild();
        while((child_node = npc_node->IterateChildren(child_node)) != NULL)
        {
            TiXmlElement* ele = child_node->ToElement();
            int npc_id = 0;
            ele->Attribute("npc_id",&npc_id);
            npc_object* object = new npc_object(npc_id);
            _all_npc.push_back(object);
            LOG(INFO)<<npc_id;
        }
    }

    delete doc;
}

bool map_object::init_map_data(std::string data,int h,int w)
{
    std::vector<std::string> data_split;
    split(data,',',data_split);

    if(data_split.size() != h*w)
        return false;
    // for(auto itr:data_split)
    // {
    //     LOG(INFO)<<atoi((itr).c_str()); 
    // }
// 
//     auto test_itr = data_split.begin();
//     for(;test_itr != data_split.end();test_itr++)
//     {
//         LOG(INFO)<<atoi((test_itr)->c_str()); 
//     }
    return true;
}




