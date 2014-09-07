#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "head.h"
#include "socket.h"
#include "gate_client.h"

class login_message_action: public template_message<ClientLoginRequest,ClientLoginResponse,MSG_CLIENT_LOGIN>
{
    public:
        int process_message(ClientLoginRequest *request,socket_client* client)
        {
            LOG(INFO)<<"role "<< request->role_id()<<" required login";
            //client->send_packet(&response);
            gate_client* user_client = (gate_client*)client;
            return 1;
        }

}g_login_message_action;

