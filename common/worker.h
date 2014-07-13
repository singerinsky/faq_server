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
            _list_locker.init(); 
            _work_flag = true;
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
            }

        }

        virtual void do_job(T* event)=0;


        void add_job(T* event)
        {
            _list_locker.lock(); 
            _job_list.push(event);  
            _list_locker.unlock();
            thread_suspend(); 
        }

        T* pop_job()
        {
            T* event = NULL;
            _list_locker.lock();
            if(_job_list.size() == 0)
            {
                _list_locker.unlock(); 
                thread_resume(NULL);
                _list_locker.lock();
            }

            if(_job_list.size() >0)
            {
                event = _job_list.front();
                _job_list.pop();
            }
            _list_locker.unlock();
            return event;
        }

        bool is_working()
        {
            return _work_flag; 
        }

    private:
        std::queue<T*> _job_list;
        volatile bool  _work_flag;
        MutexLock      _list_locker;
};


#endif
