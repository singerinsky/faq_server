#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "head.h"
#include "socket.h"

class heart_message_action: public template_message<ClientHeartBeatRequest,ClientHeartBeatResponse,MSG_HEART_BEAT>  
{
    public:
        int process_message(ClientHeartBeatRequest *request,socket_client* client)
        {
//            LOG(INFO)<<request->client_time();
            rsp_message_packet response;
            response.body.set_server_time(time(NULL));
            client->send_packet(&response);
            return 1;
        }

}g_heart_message_action;

