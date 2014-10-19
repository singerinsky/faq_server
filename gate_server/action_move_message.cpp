#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "head.h"
#include "socket.h"
#include "gate_client.h"
#include "gate_application.h"
#include "db_connection.h"
#include "sql_define.h"
#include "client_service.h"

class move_message_action: public template_message<ClientMoveRequest,ClientMoveResponse,MSG_CLIENT_MOVE>
{
    public:
        int process_message(ClientMoveRequest *request,socket_client* client)
        {
            gate_client* gclient = (gate_client*)client;
            LogicPlayer* logic_player = gclient->get_player_info();
            if(logic_player == NULL)
            {
                return -1; 
            }
            
            int pos_x = request->pos_x();
            int pos_y = request->pos_y();
            int map_id = request->map_id();
            LOG(INFO)<<"role move to"<<pos_x<<":"<<pos_y<<":"<<map_id; 
            rsp_message_packet response;
            //response.body.set_ret(1); 
            //client->send_packet(&response);
            return 1;
        }

}g_move_message_action;

