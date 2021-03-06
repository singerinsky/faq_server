#include "data_worker.h"
#include "db_connection_pool.h"
#include "work_manager.h"
#include "../message/message.pb.h"

int data_object::_next_id = 1;

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
        LOG(ERROR)<<ret<<":"<<event->_sql_str.c_str(); 
        return;
    }
    else
    {
        LOG(INFO)<<ret<<":"<<event->_sql_str.c_str(); 
    }

    if(event->_operate_type == DbOperateType::DB_WORK_UPDATE)
    {
        Singleton<work_manager>::GetInstance()->process_update(event); 
    }else
    {
        MysqlResult result = _db_conn->get_data_result();
        Singleton<work_manager>::GetInstance()->process_query(result,event); 
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

void data_worker::do_test(MysqlResult& result)
{
    while(result.next())
    {
        MysqlResultRow row = result.get_next_row(); 
        LOG(INFO)<<row.get_int(0); 
    }
}

