#include "db_client.h"
#include "actions_mananger.h"
#include "mysql_connection.h"
#include "data_worker.h"
#include "mysql_connection.h"
#include "db_message.pb.h"


int db_client::process_msg(packet_info* info)
{
    VLOG(1)<<"Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info,this);
    return 1;
}

void db_client::on_error(bufferevent* ev)
{
    LOG(INFO)<<"db client error"<<get_socket_fd();
    //Singleton<client_manager>::GetInstance()->remove_session(get_socket_fd());
    //init_timer();    
}

void db_client::init_timer()
{
   _m_timer.set_owner(this); 
   _m_timer.set_expire(2000); 
}

void db_client::on_timeout()
{
    //LOG(INFO)<<"without login virfy,kick out";
    //on_error(NULL);
    //release(); 
}

void db_client::do_data_call(MysqlResult& result,db_job* job)
{
    DbOperateType query_type = ( DbOperateType)job->_operate_type;
    LOG(INFO)<<"finish query  "<<DbOperateType_Name(query_type);
    
    switch(query_type)
    {
        case DbOperateType::MSG_DB_GET_USER_INFO:
             on_load_user_data(result,job); 
             break;
        default:
            LOG(ERROR)<<"unkown query type "<<query_type;
    }
   
}

void db_client::init(int db_work)
{
    /*
    for(int i=0;i<db_work;i++)
    {
        data_worker* worker = new data_worker();    
        worker->init();
        _db_works.push_back(worker);
        worker->create();
    }
    */
}

void db_client::on_load_user_data(MysqlResult& result,db_job* job)
{
    LOG(INFO)<<"finish data query"<<job->_operate_type;
    while(result.next())
    {
        MysqlResultRow row = result.get_next_row(); 
        LOG(INFO)<<row.get_int(0); 
    }
}
