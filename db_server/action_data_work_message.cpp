#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "db_message.pb.h"
#include "head.h"

class data_work_action: public template_message<ClientHeartBeatRequest,ClientHeartBeatResponse,MSG_HEART_BEAT>  
{
    public:
        int process_message(ClientHeartBeatRequest *request,socket_client* client)
        {
            LOG(INFO)<<request->client_time();
            return 1;
        }

}g_data_work_action;

