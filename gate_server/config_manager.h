#ifndef _CONFIG_MANAGER_H_
#define _CONFIG_MANAGER_H_

#include "singleton.h"

class ConfigManager:public Singleton<ConfigManager>
{
    public:
        friend class Singleton<ConfigManager>;
        ConfigManager();
        ~ConfigManager();
        bool Init();
};

#endif
