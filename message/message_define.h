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
// 

#endif
