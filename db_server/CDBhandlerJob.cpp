/*
 * CDBhandlerJob.cpp
 *
 *  Created on: 2012-3-16
 *      Author: root
 */

#include "CDBhandlerJob.h"
#include "../message/message_define.h"
#include "CServerManage.h"

CDBQueryhandlerJob::~CDBQueryhandlerJob() {
    // TODO Auto-generated destructor stub
}

void CDBQueryhandlerJob::AddTask(db_event* event) {
    this->_task_all++;
    this->_msg_queue.enqueue(event);
}

void CDBQueryhandlerJob::ExecuteJob() {
    while(1){
        db_event* event = _msg_queue.dequeue();
        if (event != NULL) {
            this->_task_processed++;
            if(event->operate_type == QUERY_LOGIN_INFO)
            {
                QueryClientLoginInfo(event);
            }
            else if(event->operate_type == COMMON_UPDATE_DEL)
            {
                DoCommonDelOrUpdate(event); 
            }
            else
            {
                DoCommonInsert(event); 
            }
            delete event;
        }
    }
}

void CDBQueryhandlerJob::QueryClientLoginInfo(db_event* event)
{
    mysqlpp::Query query = _conn->query(event->sql_str.c_str());
    LOG(INFO)<<event->sql_str.c_str();
    cs_client_login_response response;
    if(mysqlpp::StoreQueryResult ret = query.store())
    {
        if(ret.num_rows() > 0){
            LOG(INFO)<<"found "<<ret.num_rows();
            response.body.set_ret(1);
            response.body.set_player_id(ret[0]["uid"]);
            response.body.set_player_name(ret[0]["real_name"]);
            bool load_ret=LoadRoleInfo(*response.body.mutable_role_data(),121);
            if(load_ret == false)
            {
                response.body.set_ret(-2); 
            }
        }
        else
        {
            response.body.set_ret(-2);
        }
    }else
    {
        response.body.set_ret(-2);
        LOG(INFO)<<"nothing found!!"; 
    }

    game_client_spr ptr = CServerManage::GetInstance()->GetGameServerByIndex(event->seq);
    if(ptr)
    {
        ptr->send_packet_msg(&response); 
    }
}

bool CDBQueryhandlerJob::LoadRoleInfo(db_role_info& pb_role,int role_id)
{
    role_info role;
    role.set_role_id(role_id);
    char sql_buff[256] = {0};
    role.sql_query(sql_buff,256);
    LOG(INFO)<<sql_buff;
    mysqlpp::Query query = _conn->query(sql_buff);
    mysqlpp::StoreQueryResult ret = query.store();
    if(ret.num_rows() > 0)
    {
        role.load(ret[0]); 
        role.copy_to_pb(pb_role);
        return true;
    }
    return false;
}

void CDBQueryhandlerJob::DoCommonDelOrUpdate(db_event* event)
{
    mysqlpp::Query query = _conn->query(event->sql_str.c_str()); 
    mysqlpp::SimpleResult ret = query.execute();
    if(!ret)
    {
        LOG(ERROR)<<"-1:"<<query.error();
        return; 
    }
    if(ret.rows() <= 0)
    {
        LOG(ERROR)<<"-1:"<<event->sql_str.c_str();
    }
    else
    {
        LOG(INFO)<<"1:"<<event->sql_str.c_str(); 
    }
}

int CDBQueryhandlerJob::DoCommonInsert(db_event* event)
{
    mysqlpp::Query query = _conn->query(event->sql_str.c_str());
    mysqlpp::SimpleResult ret = query.execute();
    if(!ret)
    {
        LOG(ERROR)<<"-1:"<<query.error();
        return -1; 
    }
    LOG(INFO)<<"1:"<<event->sql_str.c_str();
    return ret.insert_id(); 
}

