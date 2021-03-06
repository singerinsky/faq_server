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

class move_message_action: public template_message<ClientMoveRequest,ClientMoveResponse,MSG_CLIENT_MOVE,gate_client>
{
    public:
        int process_message(ClientMoveRequest *request,gate_client* client)
        {
            rsp_message_packet response;
            gate_client* gclient = (gate_client*)client;
            LogicPlayer* logic_player = gclient->get_player_info();
            if(logic_player == NULL)
            {
                return -1; 
            }
            
            int pos_x = request->pos_x();
            int pos_y = request->pos_y();
            int map_id = request->map_id();
            map_object* map = logic_player->GetMapIn();
            if(map == NULL)
            {
                response.body.set_ret(-1); 
                client->send_packet(&response);
                return 1;
            }
            Position pos;
            pos.set_pos_x(pos_x);
            pos.set_pos_y(pos_y);
            if(!(map->is_vaild(pos)))
            {
                response.body.set_ret(-1); 
                client->send_packet(&response);
                return 1;
            }
            LOG(INFO)<<"role move to"<<pos_x<<":"<<pos_y<<":"<<map_id; 
            logic_player->Move(pos_x,pos_y);
            
            response.body.set_map_id(map_id);
            response.body.set_pos_x(logic_player->GetDbUserInfo().get_pos_x());
            response.body.set_pos_y(logic_player->GetDbUserInfo().get_pos_y());
            response.body.set_ret(1); 
            client->send_packet(&response);
            return 1;
        }

}g_move_message_action;

