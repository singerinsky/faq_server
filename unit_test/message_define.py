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
CSMSG_PLAYER_LEAVE_NOTF = MSG_PLAYER_LEAVE_VIEW_NOTF << 2|MSG_NOTIFY
CSMSG_LEAVE_PLAYERS_NOTF = MSG_LEAVE_PLAYERS_VIEW_NOTF << 2|MSG_NOTIFY
CSMSG_PLAYER_ENTER_NOTF = MSG_PLAYER_ENTER_VIEW_NOTF << 2|MSG_NOTIFY
CSMSG_ENTER_PLAYERS_NOTF = MSG_ENTER_PLAYERS_VIEW_NOTF << 2|MSG_NOTIFY
CSMSG_ENTER_NPCS_NOTF  = MSG_ENTER_NPCS_VIEW_NOTF<<2|MSG_NOTIFY

response_factory = {
        CSMSG_CLIENT_LOGIN_ACK:ClientLoginResponse(),
        CSMSG_HEART_REQ:ClientHeartBeatRequest(),
        CSMSG_HEART_REP:ClientHeartBeatResponse(),
        CSMSG_INIT_PLAYER_NOTF:ClientInitNotf(),
        CSMSG_CLIENT_MOVE_REQ:ClientMoveRequest(),
        CSMSG_CLIENT_MOVE_REP:ClientMoveResponse(),
        CSMSG_PLAYER_LEAVE_NOTF:PlayerLeaveViewNotf(),
        CSMSG_LEAVE_PLAYERS_NOTF:LeavePlayersViewNotf(),
        CSMSG_PLAYER_ENTER_NOTF:PlayerEnterViewNotf(),
        CSMSG_ENTER_PLAYERS_NOTF:EnterPlayersViewNotf(),
        CSMSG_ENTER_NPCS_NOTF:EnterNpcsViewNotf(),
}

MSG_NAME = {
        CSMSG_CLIENT_LOGIN_ACK:'CSMSG_CLIENT_LOGIN_ACK',
        CSMSG_HEART_REQ:'CSMSG_HEART_REQ',
        CSMSG_HEART_REP:'CSMSG_HEART_REP',
        CSMSG_INIT_PLAYER_NOTF:'CSMSG_INIT_PLAYER_NOTF',
        CSMSG_CLIENT_MOVE_REQ:'CSMSG_CLIENT_MOVE_REQ',
        CSMSG_CLIENT_MOVE_REP:'CSMSG_CLIENT_MOVE_REP',
        CSMSG_PLAYER_LEAVE_NOTF:'CSMSG_PLAYER_LEAVE_NOTF',
        CSMSG_LEAVE_PLAYERS_NOTF:'CSMSG_LEAVE_PLAYERS_NOTF',
        CSMSG_PLAYER_ENTER_NOTF:'CSMSG_PLAYER_ENTER_NOTF',
        CSMSG_ENTER_PLAYERS_NOTF:'CSMSG_ENTER_PLAYERS_NOTF',
        CSMSG_ENTER_NPCS_NOTF:'CSMSG_ENTER_NPCS_NOTF',
}
