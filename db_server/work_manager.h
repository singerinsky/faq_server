#ifndef _WORK_MANAGER_H_
#define _WORK_MANAGER_H_
#include "singleton.h"

class work_manager:public Singleton<work_manager>
{
    public:
        friend class Singleton<work_manager>;
        void    init();
        void    register_client(db_client*);
        void    do_job(db_job*);

    private:
        std::vector<data_worker*>   _data_vec;
        std::vector<db_client*>     _db_clients;
        MutexLock                   _lock;
};


#endif
