#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "head.h"
#include "socket.h"
#include "db_client.h"

class heart_message_action: public template_message<ClientHeartBeatRequest,ClientHeartBeatResponse,MSG_HEART_BEAT,db_client>  
{
    public:
        int process_message(ClientHeartBeatRequest *request,db_client* client)
        {
            if((request->client_time() - process_count_) != 1)
            {
                LOG(INFO)<<"lost paket";
                exit(-1);
                return 1;
            }
            LOG(INFO)<<request->client_time()<<"---->"<<process_count_ ;
            process_count_ = request->client_time();
            rsp_message_packet response;
            response.body.set_server_time(time(NULL));
            client->send_packet(&response);
            return 1;
        }
    private:
        int process_count_ = 0;

}g_heart_message_action;

