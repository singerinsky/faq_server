#ifndef _WORK_MANAGER_H_
#define _WORK_MANAGER_H_
#include "head.h"
#include "lock.h"
#include "singleton.h"
#include "mysql_connection.h"
#include "data_worker.h"
class work_manager:public Singleton<work_manager>
{
    public:
        friend class Singleton<work_manager>;
        void    init(int);
        void    register_client(data_object*);
        void    remove_client(data_object*);
        void    process_query(MysqlResult& result,db_job* job);
        void    process_update(db_job* job);
        bool    check_client(db_job* job);
        void    add_work_job(db_job* job);

    private:
        std::vector<data_worker*>   _data_vec;
        std::vector<data_object*>     _db_clients;
        MutexLock                   _lock;
};


#endif
