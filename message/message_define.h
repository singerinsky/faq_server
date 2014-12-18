#ifndef _MESSAGE_DEFINE_
#define _MESSAGE_DEFINE_

#include "packet.h"
#include "game_packet.h"
#include "message.pb.h"
#include "db_message.pb.h"

// DB TO GATE message
enum
{
    MSG_HEART_BEAT_REQ = MSG_HEART_BEAT << 2|MSG_REQUEST,
    MSG_HEART_BEAT_REP = MSG_HEART_BEAT << 2|MSG_RESPONSE,
    DB_MSG_COMMON_REQ = MSG_DB_COMMON << 2|MSG_REQUEST,
    DB_MSG_COMMON_REP = MSG_DB_COMMON << 2|MSG_RESPONSE,
};

typedef cs_packet<DB_MSG_COMMON_REQ,DBCommonReq> cs_packet_db_common_request;
typedef cs_packet<DB_MSG_COMMON_REP,DBCommonRep> cs_packet_db_common_response;
typedef cs_packet<MSG_HEART_BEAT_REQ,ClientHeartBeatRequest> cs_packet_heart_request;
typedef cs_packet<MSG_HEART_BEAT_REP,ClientHeartBeatResponse> cs_packet_heart_response;

/////////////////////////////////////////////////////////////////////////////////////////////////////
//GATE TO CLIENT NOTF MESSAGE DEFINE FOR ACTION UNDEFINE
enum
{
    GC_MSG_INIT_CLIENT_NOTF = MSG_INIT_CLIENT << 2|MSG_NOTIFY,
    GC_MSG_PLAYER_LEAVE_NOTF = MSG_PLAYER_LEAVE_VIEW_NOTF << 2|MSG_NOTIFY,
    GC_MSG_LEAVE_PLAYERS_NOTF = MSG_LEAVE_PLAYERS_VIEW_NOTF << 2|MSG_NOTIFY,
    GC_MSG_PLAYER_ENTER_NOTF = MSG_PLAYER_ENTER_VIEW_NOTF << 2|MSG_NOTIFY,
    GC_MSG_ENTER_PLAYERS_NOTF = MSG_ENTER_PLAYERS_VIEW_NOTF << 2|MSG_NOTIFY,
    GC_MSG_ENTER_NPCS_NOTF  = MSG_ENTER_NPCS_VIEW_NOTF<<2|MSG_NOTIFY,
    GC_MSG_LEAVE_NPC_NOTF = MSG_LEAVE_NPC_NOTF << 2|MSG_NOTIFY, 
};

typedef cs_packet<GC_MSG_INIT_CLIENT_NOTF,ClientInitNotf> cs_packet_init_client_notf;
typedef cs_packet<GC_MSG_PLAYER_LEAVE_NOTF,PlayerLeaveViewNotf> cs_packet_player_leave_notf;
typedef cs_packet<GC_MSG_LEAVE_PLAYERS_NOTF,LeavePlayersViewNotf> cs_packet_leave_players_notf;
typedef cs_packet<GC_MSG_PLAYER_ENTER_NOTF,PlayerEnterViewNotf> cs_packet_player_enter_notf;
typedef cs_packet<GC_MSG_ENTER_PLAYERS_NOTF,EnterPlayersViewNotf> cs_packet_enter_players_notf;
typedef cs_packet<GC_MSG_ENTER_NPCS_NOTF,EnterNpcsViewNotf> cs_packet_enter_npcs_notf;
typedef cs_packet<GC_MSG_LEAVE_NPC_NOTF,LeaveNpcViewNotf> cs_packet_leave_npc_notf;
#endif
