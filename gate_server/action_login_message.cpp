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

class login_message_action: public template_message<ClientLoginRequest,ClientLoginResponse,MSG_CLIENT_LOGIN>
{
    public:
        int process_message(ClientLoginRequest *request,socket_client* client)
        {
            LOG(INFO)<<"role "<< request->role_id()<<" required login";
            gate_client* user_client = Singleton<client_manager>::GetInstance()->get_session(request->role_id());
            if(user_client != NULL)
            {
                LOG(INFO)<<"player "<<request->role_id()<<" has login"; 
            }
            //client->send_packet(&response);
            user_client = (gate_client*)client;
            user_client->set_role_id(request->role_id());
            Singleton<client_manager>::GetInstance()->add_session(request->role_id(),user_client);
            user_client->init_timer();
 
            gate_application::db_conn_->build_query(request->role_id(),DbOperateType::MSG_DB_GET_USER_INFO, LOAD_USER_INFO,request->role_id()); 
            rsp_message_packet response;
            response.body.set_ret(1); 
            client->send_packet(&response);
            return 1;
        }

}g_login_message_action;

