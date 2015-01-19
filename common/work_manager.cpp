#include "work_manager.h"
#include "head.h"
#include <algorithm>

void    work_manager::init(int work_count)
{
    _lock.init();

    for(int i=0;i<work_count;i++)
    {
        data_worker* work = new data_worker();
        work->init();
        int create_rst = work->create();
        _data_vec.push_back(work);
        LOG(INFO)<<"init worker "<<i <<" rst "<<create_rst;
    }
}

void work_manager::add_work_job(db_job* job)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_objects.begin(),_db_objects.end(), job->_selector);
    if(itr == _db_objects.end())
    {
        return;
    }
   
    int index = job->_seq_id%_data_vec.size();
    _data_vec[index]->add_job(job);
}

void    work_manager::register_client(data_object* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_objects.begin(),_db_objects.end(), client);
    if(itr == _db_objects.end())
    {
        _db_objects.push_back(client); 
    }
}

void    work_manager::remove_client(data_object* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_objects.begin(),_db_objects.end(), client);
    if(itr != _db_objects.end())
    {
        _db_objects.erase(itr); 
    }
}

bool    work_manager::check_client(db_job* job)
{
    if((job== NULL) || (job->_selector == NULL))
    {
        return false;
    }
    auto itr = std::find(_db_objects.begin(),_db_objects.end(), job->_selector);
    if(itr != _db_objects.end())
    {
        return true;
    }
    return false;
}


void    work_manager::process_query(MysqlResult& result,db_job* job)
{
    ScopeLock<MutexLock> lock(_lock);
    if(check_client(job))
    {
        job->_selector->do_data_call(result,job); 
    }
    else
    {
        LOG(ERROR)<<"db_client disconnection.job result drop"; 
    }
    
}

void    work_manager::process_update(db_job* job)
{
//    LOG(INFO)<<"update success!";
}
