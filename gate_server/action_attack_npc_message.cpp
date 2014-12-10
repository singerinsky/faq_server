#include "packet.h"
#include "game_packet.h"
#include "actions_mananger.h"
#include "template_message.h"
#include "message.pb.h"
#include "message_define.h"
#include "head.h"
#include "gate_client.h"
#include "gate_application.h"
#include "db_connection.h"
#include "sql_define.h"
#include "logic_player.h"

class player_attack_npc_message_action: public template_message<PlayerAttackNpcRequest,PlayerAttackNpcResponse,MSG_PLAYER_ATTACK_NPC,gate_client>
{
    public:
        int process_message(PlayerAttackNpcRequest*request,gate_client* client)
        {
            rsp_message_packet response;
            gate_client* gclient = (gate_client*)client;
            LogicPlayer* logic_player = gclient->get_player_info();
            if(logic_player == NULL)
            {
                return -1; 
            }
            
            response.body.set_ret(1); 
            client->send_packet(&response);
            return 1;
        }
}g_player_attack_npc_message_action;

