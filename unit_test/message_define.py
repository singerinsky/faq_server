import struct
from message_pb2 import *
cs_head_format = "HH"
cs_head_len = struct.calcsize(cs_head_format) 


def pack_head_message(msg_id,body_data):
    global cs_head_format
    global cs_head_len
    msg_len = cs_head_len + len(body_data)
    head_packet = struct.pack(cs_head_format,msg_id,msg_len)
    return head_packet


#message define
CSMSG_CLIENT_LOGIN_REQ  = MSG_CLIENT_LOGIN << 2|MSG_REQUEST  
CSMSG_CLIENT_LOGIN_ACK  = MSG_CLIENT_LOGIN << 2|MSG_RESPONSE

CSMSG_HEART_REQ =   MSG_HEART_BEAT<< 2|MSG_REQUEST
CSMSG_HEART_REP =   MSG_HEART_BEAT<< 2|MSG_RESPONSE

CSMSG_INIT_PLAYER_NOTF = MSG_INIT_CLIENT << 2|MSG_NOTIFY
CSMSG_CLIENT_MOVE_REQ = MSG_CLIENT_MOVE <<2 |MSG_REQUEST
CSMSG_CLIENT_MOVE_REP = MSG_CLIENT_MOVE << 2|MSG_RESPONSE

response_factory = {
        CSMSG_CLIENT_LOGIN_ACK:ClientLoginResponse(),
        CSMSG_HEART_REQ:ClientHeartBeatRequest(),
        CSMSG_HEART_REP:ClientHeartBeatResponse(),
        CSMSG_INIT_PLAYER_NOTF:ClientInitNotf(),
        CSMSG_CLIENT_MOVE_REQ:ClientMoveRequest(),
        CSMSG_CLIENT_MOVE_REP:ClientMoveResponse(),
}
