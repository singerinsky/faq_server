#include "data_worker.h"
#include "db_connection_pool.h"

void data_worker::do_job(db_job* event)
{
    _db_conn->exec_format(event->_sql_str.c_str());
    int row = _db_conn->result_row_count();
    if(row > 0 )
    {
       LOG(INFO)<<"Get data "<<_db_conn->result_row_data(0)[0]; 
    }
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


