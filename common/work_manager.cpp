#include "work_manager.h"
#include "head.h"
#include <algorithm>

template<>
work_manager* Singleton<work_manager>::_instance = 0;

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
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), job->_selector);
    if(itr == _db_clients.end())
    {
        _db_clients.push_back(job->_selector); 
    }
   
    int index = job->_seq%_data_vec.size();
    _data_vec[index]->add_job(job);
    
}

void    work_manager::register_client(data_object* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), client);
    if(itr == _db_clients.end())
    {
        _db_clients.push_back(client); 
    }
}

void    work_manager::remove_client(data_object* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), client);
    if(itr != _db_clients.end())
    {
        _db_clients.erase(itr); 
    }
}

bool    work_manager::check_client(db_job* job)
{
    if((job== NULL) || (job->_selector == NULL))
        return false;
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), job->_selector);
    if(itr != _db_clients.end())
    {
        return true;
    }
    return false;
}


void    work_manager::process_query(MysqlResult& result,db_job* job)
{
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
