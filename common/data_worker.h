#ifndef _DATA_WORKER_H_
#define _DATA_WORKER_H_
#include "worker.h"
#include "mysql_connection.h"

class db_job;
class data_object
{
    public:
        data_object()
        {
            _seq_id = get_next_id();
        }

        virtual ~data_object()
        {
            _seq_id = -1;        
        }

        virtual void do_data_call(MysqlResult& result,db_job* job) = 0;
        int     get_seq_id()
        {
            return _seq_id;
        }

        static int get_next_id()
        {
            return ++_next_id; 
        }

    private:
        int     _seq_id;
        static  int _next_id;
};


class db_job
{
    public:
        int         _seq_id;
        int         _operate_type;
        std::string _sql_str;
        data_object*  _selector;

    public:
        db_job(data_object* selector,std::string sql_str,int operate_type)
        {
            _operate_type = operate_type;
            _selector = selector;
            _sql_str = sql_str;
            _seq_id = selector->get_seq_id(); 
        }
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
