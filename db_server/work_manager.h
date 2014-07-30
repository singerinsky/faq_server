#ifndef _WORK_MANAGER_H_
#define _WORK_MANAGER_H_
#include "singleton.h"

class work_manager:public Singleton<work_manager>
{
    public:
        friend class Singleton<work_manager>;


    private:
        std::vector<data_worker*>   _data_vec;
};


#endif
