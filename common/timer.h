#ifndef _TIMER_H_
#define _TIMER_H_

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
        template_timer(T* owner = NULL):m_owner(owner){};

        void set_owner(T* owner)
        {
            m_owner = owner;
        }
    protected:
        virtual void on_timeout()
        {
            m_owner->*callback(); 
        }

    private:
        T* m_owner;
};

#endif
