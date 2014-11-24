#include "config_manager.h"
#include "head.h"

ConfigManager::ConfigManager()
{
    if(Init() == false)
    {
        LOG(INFO)<"init config false!"; 
    }
}

ConfigManager::~ConfigManager()
{


}

bool ConfigManager::Init()
{


    return true;
}

