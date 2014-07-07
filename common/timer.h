#ifndef _TIMER_H_
#define _TIMER_H_
#include "head.h"
#include "reactor_core.h"

void common_timeout_call(evutil_socket_t,short,void *);

class base_timer
{
    public:
        virtual ~base_timer(){}
        virtual void on_timeout() = 0;
};


template<typename T,void (T::*callback)() = &T::on_timeout>
class template_timer:public base_timer
{
    public:
        template_timer(T* owner = NULL):m_owner(owner){
            m_ev = evtimer_new(Singleton<ReactorCore>::GetInstance()->GetEventBase(),common_timeout_call,(void*)this); 
        
        }

        ~template_timer(){
            if(m_ev != NULL)
            {
                evtimer_del(m_ev);
            }
        }

        void set_owner(T* owner)
        {
            m_owner = owner;
        }

        void set_expire(int64_t ms)
        {
            if(m_ev != NULL)
            {
               struct timeval tv;
               evutil_timerclear(&tv);
               tv.tv_sec = ms/(1000);
               tv.tv_usec = (ms%1000)*1000;
               int rst = evtimer_add(m_ev,&tv);             
               if(rst == -1)
               {
                   LOG(ERROR)<<"add timer error"<<ms; 
               }
            }
        }

        void remove_timer()
        {
            if(m_ev != NULL)
            {
                evtimer_del(m_ev); 
                m_ev = NULL;
            }
        }

    protected:
        virtual void on_timeout()
        {
            (m_owner->*callback)(); 
        }

    private:
        T* m_owner;
        struct event* m_ev;
};

#endif
