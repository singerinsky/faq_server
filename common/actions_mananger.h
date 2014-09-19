#ifndef _ACTIONS_MANAGER_H_
#define _ACTIONS_MANAGER_H_
#include <map>
#include "singleton.h"
#include "packet.h"

class socket_client;
class action_handler;
class actions_mananger:public Singleton<actions_mananger>
{
    public:
        friend Singleton<actions_mananger>;
    public:
        void register_action(int,action_handler*);
        void do_action(int,packet_info*,socket_client*);

    private:
        std::map<int,action_handler*> _actions;
};
#endif
