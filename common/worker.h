#ifndef _WORKER_H_
#define _WORKER_H_
#include <queue>
#include "thread.h"
#include "lock.h"

template<class T>
class worker:public thread
{

    public:
        worker()
        {
            _work_flag = true;
        }
        virtual ~worker()
        {
        }

        void set_flag(bool value)
        {
            _work_flag = value; 
        }
        void run()
        {
            while(_work_flag)
            {
                T* event = pop_job(); 
                do_job(event); 
                delete event;
            }

        }

        virtual void do_job(T* event)=0;


        void add_job(T* event)
        {
            thread_lock();
            _job_list.push(event);  
            thread_unlock();
            thread_suspend(); 
        }

        T* pop_job()
        {
            T* event = NULL;
            thread_lock();
            if(_job_list.size() == 0)
            {
                thread_unlock();
                thread_resume(NULL);
                thread_lock();
            }

            if(_job_list.size() >0)
            {
                event = _job_list.front();
                _job_list.pop();
            }
            thread_unlock();
            return event;
        }

        bool is_working()
        {
            return _work_flag; 
        }

        size_t job_in_list()
        {
            thread_lock();
            return _job_list.size();
        }

    private:
        std::queue<T*> _job_list;
        volatile bool  _work_flag;
};


#endif
