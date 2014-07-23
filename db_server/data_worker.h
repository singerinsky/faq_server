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
        (void)(*)(MYSQL_RES*) _call_back; 
        int         _selector_id;

    public:
        db_job()
        {
            _seq = -1; 
            _operate_type = -1;
            _client = NULL;
            _call_back = NULL;
            _selector_id = -1;
        }
};

class data_worker: public worker<db_job>
{
    public:
        void do_job(db_job* event);
        virtual ~data_worker();
        int  init();
        

    private:
        MysqlConnection*    _db_conn;
};

#endif
