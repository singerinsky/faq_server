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

bool map_object::init(std::string map_file)
{
    LOG(INFO)<<map_file;

    TiXmlDocument* doc = new TiXmlDocument;
    bool load_rst = doc->LoadFile(map_file.c_str());
    if(!load_rst)
    {
        LOG(ERROR)<<"load db server failed!"; 
        exit(-1);
    }

    TiXmlNode* node = doc->FirstChild("map");
    TiXmlElement* ele_node = node->ToElement();
    int id,length,width=0;
    ele_node->Attribute("id",&id);
    ele_node->Attribute("length",&length);
    ele_node->Attribute("width",&width);
    LOG(INFO)<<":"<<id<<":"<<length<<":"<<width;

    TiXmlNode* map_data= node->FirstChild();  
    TiXmlElement* ele_map_data = map_data->ToElement();
    std::string map_data_str = ele_map_data->Attribute("data");
    LOG(INFO)<<map_data_str;

    delete doc;
}
