#ifndef _WORKER_H_
#define _WORKER_H_
#include <queue>

class job
{
    public:
        virtual void do_job() = 0;
};


class worker:public thread
{

    public:
        void run()
        {
        
        }

    private:
        std::queue<job> _job_list;
};


#endif
