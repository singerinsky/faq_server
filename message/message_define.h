#ifndef _MESSAGE_DEFINE_
#define _MESSAGE_DEFINE_


#include "../common/packet.h"
#include "../common/game_packet.h"
#include "message.pb.h"

enum
{
    CS_MSG_HEART_BEAT_REQ        = MSG_HEART_BEAT        << 2|MSG_REQUEST,
    CS_MSG_HEART_BEAT_REP        = MSG_HEART_BEAT        << 2|MSG_RESPONSE,
/*
    CS_MSG_SOCCER_PLAYER_REQ = MSG_SOCCER_PLAYER_INFO << 2 |MSG_REQUEST, 
    CS_MSG_SOCCER_PLAYER_REP = MSG_SOCCER_PLAYER_INFO << 2 |MSG_RESPONSE,

    CS_MSG_CLIENT_LOGIN_REQ         = MSG_CLIENT_LOGIN  <<2|MSG_REQUEST,
    CS_MSG_CLIENT_LOGIN_REP         = MSG_CLIENT_LOGIN  <<2|MSG_RESPONSE,

    CS_MSG_GATE_REGISTER_REQ    = MSG_GATE_SERVER_REGISTER << 2|MSG_REQUEST,
    CS_MSG_GATE_REGISTER_REP    = MSG_GATE_SERVER_REGISTER << 2|MSG_RESPONSE,
    
    CS_MSG_COMMON_DATA_UPDATE_NTF    = MSG_DB_COMMON_UPDATE<< 2|MSG_NOTIFY,
    */
};



//typedef cs_packet<CS_MSG_SOCCER_PLAYER_REQ,SoccerPlayerInfoRequest> cs_soccer_player_request;
//typedef cs_packet<CS_MSG_SOCCER_PLAYER_REP,SoccerPlayerInfoResponse> cs_soccer_player_response;

//typedef cs_packet<CS_MSG_HEART_BEAT_REQ,ClientHeartBeatRequest> cs_client_hb_request;
//typedef cs_packet<CS_MSG_HEART_BEAT_REP,ClientHeartBeatResponse> cs_client_hb_response;
/*
typedef cs_packet<CS_MSG_CLIENT_LOGIN_REQ,ClientLoginRequest> cs_client_login_request;
typedef cs_packet<CS_MSG_CLIENT_LOGIN_REP,ClientLoginResponse> cs_client_login_response;

typedef cs_packet<CS_MSG_GATE_REGISTER_REQ,GateServerRegisterRequest> cs_gate_register_request;
typedef cs_packet<CS_MSG_GATE_REGISTER_REP,GateServerRegisterResponse> cs_gate_register_response;

typedef cs_packet<CS_MSG_COMMON_DATA_UPDATE_NTF,DataCommonUpdateNtf> cs_data_common_update_ntf;
*/
#endif
