#ifndef _TEMPLATE_MESSAGE_H_
#define _TEMPLATE_MESSAGE_H_
#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "head.h"

enum
{
    MSG_REQUEST_MASK,
    MSG_RESPONSE_MASK,
};
class socket_client;
class action_handler
{
    public:
        virtual int do_message_action(packet_info* info,socket_client*) = 0;

};

template<class RequestBody,class ResponseBoby,int MessageCode,class TClient>
class template_message:public action_handler
{
    public:
        //typedef RequestBody type T;
        enum
        {
            REQ_ID = MessageCode<<2|MSG_REQUEST_MASK,
            RSP_ID = MessageCode<<2|MSG_RESPONSE_MASK,
        };
        typedef cs_packet<REQ_ID,RequestBody>     req_message_packet;
        typedef cs_packet<RSP_ID,ResponseBoby>    rsp_message_packet;
    public:
        template_message()
        {
            Singleton<actions_mananger>::GetInstance()->register_action(REQ_ID,(action_handler*)this); 
        }
        
        int do_message_action(packet_info* info,socket_client* client)
        {
            req_message_packet t; 
            if(t.decode(info->data,info->size) != info->size)
                return -1;
            VLOG(2)<<"process message "<<(&(t.body))->descriptor()->name();
            process_message(&(t.body),(TClient*)client);
            return 1;
        }

        virtual int process_message(RequestBody *body,TClient*) = 0;
};

#endif
