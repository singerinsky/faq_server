#ifndef _DATA_WORKER_H_
#define _DATA_WORKER_H_
#include "worker.h"
#include "mysql_connection.h"

class data_object;
class db_job
{
    public:
        int         _seq;
        int         _operate_type;
        std::string _sql_str;
        data_object*  _selector;

        db_job()
        {
            _seq = -1; 
            _operate_type = -1;
            _selector = NULL;
            _sql_str = "";
        }
};

class data_object
{
    public:
        virtual ~data_object(){}
        virtual void do_data_call(MysqlResult& result,db_job* job) = 0;
};

class data_worker: public worker<db_job>
{
    public:
        void do_job(db_job* event);
        virtual ~data_worker();
        int  init();
    public:
        /////////////////////////////////////
        void do_test(MysqlResult& result);

    private:
        MysqlConnection*    _db_conn;
};

#endif
