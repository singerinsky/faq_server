/*
 * CDBhandlerJob.h
 *
 *  Created on: 2012-3-16
 *      Author: root
 */

#ifndef CDBHANDLERJOB_H_
#define CDBHANDLERJOB_H_

#include <sstream>
#include "../net/IMsgDispatcher.h"
#include "../common/IJob.h"
#include "../common/lock.h"
#include "../common/queue.h"
#include <mysql++/mysql++.h>
#include "DBConnectionPool.h"
#include "../orm/role_info.h"

using namespace omg;

enum DB_OPERATE
{
    COMMON_INSERT,
    COMMON_UPDATE_DEL,
    QUERY_LOGIN_INFO,
};

class db_event
{
    public:
        DB_OPERATE operate_type;
        int seq;
        std::string sql_str;
};

class CDBQueryhandlerJob: public omg::IJob {
    public:
        CDBQueryhandlerJob(DBConnectionPool* pool,int number):_conn(*pool,true){
            _task_all = 0;
            _task_processed = 0;
            _id = number;
        };
        virtual ~CDBQueryhandlerJob();
        virtual void ExecuteJob();
        void 	AddTask(db_event *event);

        int		GetTaskInProcess(){
            return _task_all - _task_processed;
        }
        int     getId(){
            return _id;
        }
    private:
        mysqlpp::ScopedConnection _conn;
        int  _task_all;
        int  _task_processed;
        int  _id;

        void QueryClientLoginInfo(db_event*);
        void DoCommonDelOrUpdate(db_event*);
        int  DoCommonInsert(db_event* event);
        bool LoadRoleInfo(db_role_info& pb_role,int role_id);
    private:
        omg::ConcurrenceLockQueue<db_event,omg::MutexLock>	_msg_queue;
        //omg::WRQueue<CMsgEvent,omg::MutexLock>	_msg_queue;
};

#endif /* CDBHANDLERJOB_H_ */
