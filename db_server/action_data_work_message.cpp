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
#include "db_client.h"

class data_work_action: public template_message<DBCommonReq,DBCommonRep,MSG_DB_COMMON,db_client>  
{
    public:
        int process_message(DBCommonReq* request,db_client* client)
        {
            count++;
            db_job* job = new db_job(client,request->operate_string(),request->operate_type());
            Singleton<work_manager>::GetInstance()->add_work_job(job);
            return 1;
        }

    private:
        int count = 0;

}g_data_work_action;

