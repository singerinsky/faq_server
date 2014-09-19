#ifndef _DB_MESSAGE_DEFINE_
#define _DB_MESSAGE_DEFINE_


#include "packet.h"
#include "game_packet.h"
#include "message.pb.h"
#include "db_message.pb.h"

enum
{
    DB_MSG_GET_USER_INFO_REP  = MSG_DB_GET_USER_INFO  << 2|MSG_REQUEST,
    DB_MSG_GET_USER_INFO_REQ  = MSG_DB_GET_USER_INFO  << 2|MSG_RESPONSE,
};


#endif
