#ifndef _WORK_MANAGER_H_
#define _WORK_MANAGER_H_
#include "head.h"
#include "lock.h"
#include "singleton.h"
#include "mysql_connection.h"
#include "data_worker.h"
class db_client;
class work_manager:public Singleton<work_manager>
{
    public:
        friend class Singleton<work_manager>;
        void    init();
        void    register_client(db_client*);
        void    remove_client(db_client*);
        void    process_query(MysqlResult& result,db_job* job);
        bool    check_client(db_job* job);

    private:
        std::vector<data_worker*>   _data_vec;
        std::vector<db_client*>     _db_clients;
        MutexLock                   _lock;
};


#endif
