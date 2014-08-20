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

class data_work_action: public template_message<ClientHeartBeatRequest,ClientHeartBeatResponse,MSG_HEART_BEAT>  
{
    public:
        int process_message(ClientHeartBeatRequest *request,socket_client* client)
        {
            LOG(INFO)<<request->client_time();
            db_job* job = new db_job();
            job->_sql_str = "select * from tb_user";
            job->_selector = (db_client*)client;
            job->_operate_type = 1;
            job->_seq = 1;
            Singleton<work_manager>::GetInstance()->add_work_job(job);
            return 1;
        }

}g_data_work_action;

