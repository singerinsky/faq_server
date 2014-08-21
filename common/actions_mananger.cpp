#include "actions_mananger.h"
#include "head.h"
#include "template_message.h"

template<> 
actions_mananger* Singleton<actions_mananger>::_instance = 0;

void actions_mananger::register_action(int action_id,action_handler* p_action)
{
    auto itr = _actions.find(action_id);
    if(itr != _actions.end())
    {
        LOG(ERROR)<<"register same action "<<action_id; 
        exit(-1); 
    }
    LOG(INFO)<<"register action "<<action_id;
    _actions[action_id] = p_action;
}


void actions_mananger::do_action(int action_id,packet_info* packet,socket_client* client)
{
    auto itr = _actions.find(action_id);
    if(itr != _actions.end())
    {
        itr->second->do_message_action(packet,client); 
    }
    else
    {
        //TODO
        LOG(ERROR)<<"recive unregister code unkown "<<action_id; 
    }

}
