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

void    work_manager::do_job(db_job*)
{

}


