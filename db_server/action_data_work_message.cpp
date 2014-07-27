#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "db_message.pb.h"
#include "head.h"

class data_work_action: public template_message<ClientHeartBeatRequest,CS_MSG_HEART_BEAT_REQ>  
{
    public:
        int process_message(ClientHeartBeatRequest *request)
        {
            LOG(INFO)<<request->client_time();
            return 1;
        }

}g_data_work_action;

