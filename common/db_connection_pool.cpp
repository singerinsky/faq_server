#include "db_connection_pool.h"
#include "head.h"

//template<> 
//db_pool* Singleton<db_pool>::_instance = 0;

#define DB_CONFIG "server.xml"

bool db_pool::init_config()
{
    TiXmlDocument* doc = new TiXmlDocument;
    bool load_rst = doc->LoadFile("server.xml");
    if(!load_rst)
    {
        LOG(ERROR)<<"load db server failed!"; 
        exit(-1);
    }

    TiXmlNode* node = doc->FirstChild("db");
    TiXmlElement* ele = node->ToElement();

    ele->QueryIntAttribute("port",&(_config._port));
    _config._ip.append(ele->Attribute("ip"));
    _config._user.append(ele->Attribute("user"));
    _config._pwd.append(ele->Attribute("pwd"));
    _config._dbname.append(ele->Attribute("db_name"));
    delete doc;

    return true;
}
