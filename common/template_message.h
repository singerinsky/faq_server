#ifndef _TEMPLATE_MESSAGE_H_
#define _TEMPLATE_MESSAGE_H_

template<class ResponseT,class SubT>
class template_message
{
    public:
        template_message()
        {
             
        }
        static int do_message_action(packet_info* info)
        {
            //TODO decode from packet_info
            ResponseT t; 
            process_message(t);
            return 1;
        }
        virtual int process_message(ResponseT &t) = 0;

};

#endif
