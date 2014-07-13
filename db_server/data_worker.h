#ifndef _DATA_WORKER_H_
#define _DATA_WORKER_H_
#include "worker.h"
#include "mysql_connection.h"

class db_job
{
    public:
        int         _seq;
        int         _operate_type;
        std::string _sql_str;
};

class data_worker: public worker<db_job>
{
    public:
        void do_job(db_job* event);
        int  init();

    private:
        MysqlConnection*    _db_conn;
        int                 _job_count;
};

#endif
