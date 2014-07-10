#ifndef _DB_CONNECTION_H_
#define _DB_CONNECTION_H_
#include "mysql/mysql.h"
#include "object_pool.h"

class db_pool:public object_pool<MYSQL>
{
    public:
        MYSQL* create()
        {
            return NULL; 
        }

};

#endif
