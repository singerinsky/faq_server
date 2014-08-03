#include "work_manager.h"

void    work_manager::init()
{
    _lock.init();

    data_worker* work = new data_worker();
    work->init();
    work->create();
    _data_vec.push_back(work);
}

void    work_manager::register_client(db_client* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), client);
    if(itr == _db_clients.end())
    {
        _db_clients.push_back(client); 
    }
}

void    work_manager::remove_client(db_client* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), client);
    if(itr != _db_clients.end())
    {
        _db_clients.erase(itr); 
    }
}

bool    work_manager::check_client(db_client* client)
{
    ScopeLock<MutexLock> lock(_lock);
    auto itr = std::find(_db_clients.begin(),_db_clients.end(), client);
    if(itr != _db_clients.end())
    {
        return true;
    }
    return false;
}


void    work_manager::process_query(MysqlResult& result,db_job* job)
{
    if(check_client(job->_selector))
    {
        job->_selector->process_query(result,job); 
    }
    else
    {
        LOG(ERROR)<<"db_client disconnection.job result drop"; 
    }
    
}
