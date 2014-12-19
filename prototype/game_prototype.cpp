#include "game_prototype.h"
#include "../common/head.h"

//template<> 
//GamePrototype* Singleton<GamePrototype>::_instance = 0;
#define stream_list_file "bin_list.xml"
bool GamePrototype::Init()
{ 
    TiXmlDocument* doc = new TiXmlDocument;
    bool load_rst = doc->LoadFile(stream_list_file);
    if(!load_rst)
    {
        LOG(ERROR)<<"load prototype file"<<stream_list_file<<" failed!"; 
        exit(-1);
    }

    TiXmlNode* node = doc->FirstChild("streams_list");

    TiXmlNode* npc_config_node = node->FirstChild("npc_config");
    TiXmlElement* ele = NULL;
    std::string stream_file;
    if(npc_config_node != NULL)
    {
        ele = npc_config_node->ToElement();
        stream_file = ele->Attribute("stream_file");
        load_rst = _npc_data_prototype.Load(stream_file.c_str());
    }
 

    if(load_rst == false)
    {
        return false; 
    }
    LOG(INFO)<<"load game config!";
    return true;
}

void GamePrototype::Reload()
{
    LOG(INFO)<<"reload game prototype!";
}
