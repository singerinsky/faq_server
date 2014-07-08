/*
 * CDBTaskManage.h
 *
 *  Created on: 2012-3-22
 *      Author: guanlei
 */

#ifndef CDBTASKMANAGE_H_
#define CDBTASKMANAGE_H_
#include <vector>
#include "CDBhandlerJob.h"
using namespace std;

class CDBTaskManage {
    public:
        CDBTaskManage()
        {
        }

        virtual ~CDBTaskManage();
        static CDBTaskManage* GetInstance(){
            if(_m_instance == NULL){
                _m_instance = new CDBTaskManage();
            }
            return _m_instance;
        }

        void AddProcessThread(CDBQueryhandlerJob* job){
            _job_vec.push_back(job);    
        }

        void AddTaskEvent(db_event* event){
            int seq = event->seq;
            if(_job_vec.size() <= 0)
            {
                LOG(ERROR)<<"no running thread ";
                return ;
            }
            int process_index = seq%_job_vec.size();
            (_job_vec[process_index])->AddTask(event);
        }

    private:
        static CDBTaskManage* _m_instance;
        std::vector<CDBQueryhandlerJob*>   _job_vec;
};

#endif /* CDBTASKMANAGE_H_ */
