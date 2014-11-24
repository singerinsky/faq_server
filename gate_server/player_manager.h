#ifndef _LOGICPLAYER_MANAGER_H_
#define _LOGICPLAYER_MANAGER_H_

#include "singleton.h"
#include <map>

class LogicPlayer;
class LogicPlayerManager:public Singleton<LogicPlayerManager>
{
    public:
        friend Singleton<LogicPlayerManager>;
        LogicPlayer*    GetPlayer(int ply_id);
        void    AddPlayer(int ply_id,LogicPlayer*);

    private:
        std::map<int,LogicPlayer* > _player_map;
};

#define LogicManagerPtr LogicPlayerManager::GetInstance()
#endif
