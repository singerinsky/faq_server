#ifndef _DB_THREAD_H_
#define _DB_THREAD_H_
#include "mysql_connection.h"
#include "thread.h"

classs db_thread:public thread
{
    public:
        db_thread();


    private:
        MysqlConnection* conn;
};


#endif
