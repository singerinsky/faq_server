#include "data_worker.h"
#include "db_connection_pool.h"

data_worker::~data_worker()
{
    Singleton<db_pool>::GetInstance()->push(_db_conn);    
    _db_conn = NULL;
}

void data_worker::do_job(db_job* event)
{
    int ret = _db_conn->exec_format(event->_sql_str.c_str());
    if(ret < 0)
    {
        LOG(ERROR)<<ret<<event->_sql_str.c_str(); 
        return;
    }
    
    MysqlResult result = _db_conn->get_data_result();
    while(result.next())
    {
        MysqlResultRow row = result.get_next_row(); 
        LOG(INFO)<<row.get_int(0); 
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


