#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "db_message.pb.h"
#include "head.h"
#include "data_worker.h"
#include "work_manager.h"

class data_work_action: public template_message<DBCommonReq,DBCommonRep,MSG_DB_COMMON>  
{
    public:
        int process_message(DBCommonReq* request,socket_client* client)
        {
            LOG(INFO)<<"message  common "<<request->operate_string() << count++;
            db_job* job = new db_job();
            job->_sql_str = request->operate_string();
            job->_selector = (db_client*)client;
            job->_operate_type = request->operate_type(); 
            job->_seq = 1;
            Singleton<work_manager>::GetInstance()->add_work_job(job);
            return 1;
        }

    private:
        int count = 0;

}g_data_work_action;

