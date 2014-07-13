#include "data_worker.h"
#include "db_connection_pool.h"

void data_worker::do_job(db_job* event)
{
    LOG(INFO)<<"process one job"<<_job_count;
    _job_count++;
}

int data_worker::init()
{
    _db_conn = Singleton<db_pool>::GetInstance()->pop();    
    if(_db_conn == NULL)
    {
        LOG(ERROR)<<"init data worker error ,because db_connection is NULL"; 
        return -1;
    }
    return 1;
}


