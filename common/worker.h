#ifndef _WORKER_H_
#define _WORKER_H_
#include <queue>
#include "thread.h"
#include "lock.h"
class job_event
{
    public:
        virtual void do_job() = 0;
};


class worker:public thread
{

    public:
        worker()
        {
            _list_locker.init(); 
        }
        void set_flag(bool value)
        {
            _work_flag = value; 
        }
        void run()
        {
           while(_work_flag)
           {
                job_event* event = pop_job(); 
                do_job(event); 
           }
        
        }

        virtual void do_job(job_event* event)=0;
        
        
        void add_job(job_event* event)
        {
            _list_locker.lock(); 
            _job_list.push_back(event);  
            _list_locker.unlock();
            thread_suspend(); 
        }

        job_event* pop_job()
        {
            job_event* event = NULL;
            _list_locker.lock();
            if(_job_list.size() == 0)
            {
                _list_locker.unlock(); 
                thread_resume(NULL);
                _list_locker.lock();
            }
            event = _job_list.pop();
            _list_locker.unlock();
            return event;
            
        }

    private:
        std::queue<job_event*> _job_list;
        bool                   _work_flag;
        MutexLock              _list_locker;
};


#endif
