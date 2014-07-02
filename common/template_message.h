#ifndef _TEMPLATE_MESSAGE_H_
#define _TEMPLATE_MESSAGE_H_
#include "packet.h"
#include "actions_mananger.h"

class action_handler
{
    public:
        virtual int do_message_action(packet_info* info) = 0;

};

template<class RequestT,int MessageCode>
class template_message:public action_handler
{
    public:
        template_message()
        {
            //TODO do register action
            Singleton<actions_mananger>::GetInstance()->register_action(MessageCode,(action_handler*)this); 
        }
        
        int do_message_action(packet_info* info)
        {
            //TODO decode from packet_info
            RequestT t; 
            if(t.decode(info->data,info->size) != info->size)return -1;
            process_message(t);
            return 1;
        }
        virtual int process_message(RequestT &t) = 0;

};

#endif
