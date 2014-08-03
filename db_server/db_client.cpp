#include "db_client.h"
#include "actions_mananger.h"
#include "mysql_connection.h"
#include "data_worker.h"


int db_client::process_msg(packet_info* info)
{
    VLOG(1)<<"Recive message type "<<info->type;
    Singleton<actions_mananger>::GetInstance()->do_action(info->type,info);
    return 1;
}

void db_client::on_error(bufferevent* ev)
{
    LOG(INFO)<<"db client error"<<get_socket_fd();
    //Singleton<client_manager>::GetInstance()->remove_session(get_socket_fd());
    size_t job_count = work_job_left();
    if(job_count <= 0 )
    {
        release();
    }
    else//wait for all write in
    {
        init_timer();    
    }
}

void db_client::init_timer()
{
   _m_timer.set_owner(this); 
   _m_timer.set_expire(2000); 
}

void db_client::on_timeout()
{
    LOG(INFO)<<"without login virfy,kick out";
    //on_error(NULL);
    if(work_job_left() > 0)
    {
        init_timer();
    }
    else
    {
        release(); 
    }
}

void db_client::do_data_call(MysqlResult& result,db_job* job)
{
    LOG(INFO)<<"finish data query"<<job->_operate_type;
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

/*
int db_client::work_job_left()
{
    int job_left = 0;
    for(auto& worker_: _db_works)
    {
        job_left += worker_->job_in_list(); 
    }
    return job_left;
}

void db_client::release()
{
    for(auto& worker_:_db_works)
    {
        delete worker_; 
    }
    _db_works.clear();
    delete this;
}
*/
