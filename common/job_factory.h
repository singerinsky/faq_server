#ifndef _JOB_FACTORY_H_
#define _JOB_FACTORY_H_
#include "worker.h"
#include "singleton.h"
#include "head.h"


template<class TJOB>
class job_factory:public Singleton<job_factory<TJOB> >
{
public:
    friend class Singleton<job_factory<TJOB> >;
    //TODO
    virtual bool init(int worker_need){
        return false; 
    }

    void add_job_to_do(TJOB *job)
    {
        int job_id = job->id();
        int job_index = job_id%_all_worker.size();
        _all_worker[job_index]->add_job(job); 
    }

    int add_worker(worker<TJOB>* new_worker)
    {
        return 1; 
    }
    
    void remove_worker(worker<TJOB>* new_worker)
    {
    
    }

private:
    std::vector<worker<TJOB> *>    _all_worker;

};


#endif
