#ifndef _TEMPLATE_MESSAGE_H_
#define _TEMPLATE_MESSAGE_H_

template<class RequestT,int MessageCode>
class template_message
{
    public:
        template_message()
        {
            LOG(INFO)<<"init message action "<<MessageCode;
            //TODO do register action
        }
        static int do_message_action(packet_info* info)
        {
            //TODO decode from packet_info
            RequestT t; 
            process_message(t);
            return 1;
        }
        virtual int process_message(RequestT &t) = 0;

};

#endif
