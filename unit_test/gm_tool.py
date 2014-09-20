#!/bin/env python
#-*- coding: utf-8 -*- 

from sys import stdout
import sys
import random
import struct
import socket
import time
import string
from xml.dom.minidom import *

from game_common_pb2 import * 
from game_client_pb2 import * 
from game_server_pb2 import *
from game_mail_pb2 import * 

reload(sys)
sys.setdefaultencoding('utf8')

# server config

server_header_fmt = "!HHiii"
server_header_size = struct.calcsize(server_header_fmt)

def encode_packet(msgid,role_id,body):
    body_data = body.SerializeToString()
    print "request msg_id:" , msgid , "role_id:" , role_id
    buf = struct.pack(server_header_fmt,len(body_data) +server_header_size,msgid,role_id,1,0)
    return buf + body_data

def decode_packet(msgid,role_id,buf,body):
    raw_header = buf[:server_header_size]
    body_data = buf[server_header_size:]
    header = struct.unpack(server_header_fmt,raw_header)
    msg_size= header[0]
    decode_msgid = header[1]
    decode_role_id = header[2]
    print "response msg_id:" , decode_msgid , "role_id:" , decode_role_id
    if decode_msgid == msgid and decode_role_id == role_id :
        body.ParseFromString(body_data)
        return True

    return False


def do_gm_request(host,port,role_id,action_id,request,response):
    
    # create client socket
    print "connect to %s:%d" % (host,port)
    client = socket.socket( socket.AF_INET, socket.SOCK_STREAM )
    client.connect( (host, port) )
    
    req_msgid = MSG_MODULE_SERVER<< 12 | action_id<<2 | MSG_TYPE_REQUEST
    res_msgid = MSG_MODULE_SERVER<< 12 | action_id<<2 | MSG_TYPE_RESPONSE

    buffer = encode_packet(req_msgid,role_id,request)
    client.send( buffer )

    data = client.recv( 40960 )
    if len(data) == 0:
        print "server closed connection"
        client.close()
        return

    if not decode_packet(res_msgid,role_id,data,response):
        print "recv response failed"
    client.close()

def show_command():
    print "\tMSG_ACTION_GM_ADD_ITEM  \"GMAddItemRequest(tid=184400,count=1)\" \"GMAddItemResponse()\""
    print "\tMSG_ACTION_GM_ADD_MONEY  \"GMAddMoneyRequest(type=1,value=1000)\" \"GMAddMoneyResponse()\""

    print "\tMSG_ACTION_GM_ADD_EXP \"GMAddExpRequest(exp=10000)\" \"GMAddExpResponse()\""
    print "\tMSG_ACTION_GM_ADD_PHY_STRENGTH \"GMAddPhyStrengthRequest(type=1, phy_str=100)\" \"GMAddPhyStrengthResponse\""

    print "\tMSG_ACTION_GM_GET_PLAYER_INFO  \"GMGetPlayerInfoRequest()\" \"GMGetPlayerInfoResponse()\" "
    print "\tMSG_ACTION_GM_REMOVE_PLAYER_OBJECT  \"GMRemovePlayerObjectRequest()\" \"GMRemovePlayerObjectResponse()\" "
    
    print "\tMSG_ACTION_GM_UPDATE_ATTRIBUTE \"GMUpdateAttributeRequest()\" \"GMUpdateAttributeResponse()\""
    print "\tMSG_ACTION_GM_UPDATE_POSITION \"GMUpdatePositionRequest(map_id=2,map_x=45,map_y=14)\" \"GMUpdatePositionResponse()\""
    print "\tMSG_ACTION_GM_SEND_MAIL \"MailInfo(src_role_id=0,src_name='system',title=unicode('title'),content=unicode('content'),money=BankInfo(coin=1000,coupon=2000,diamond=3000),item_list=[MailItem(item_tid=184400,item_count=1)])\" \"GMSendMailResponse()\""

    print "\tMSG_ACTION_GM_TALK_SYSTEM \"GMTalkSystemRequest(content=unicode('welcome to game'))\" \"GMTalkSystemResponse()\""

    print "\tSSMSG_GM_ADD_SKILL_EXP_REQ \t\t\"GMAddSkillExpRequest(buddy_tid=201, skill_id=21001, exp=100)\""
    print "\tSSMSG_GM_SET_DAY_SECONDS_REQ \t\t\"GMSetDaySecondsRequest(seconds=600)\""
    print "\tSSMSG_GM_SET_QUEST_STATUS_REQ \t\"GMSetQuestStatusRequest(player_id=99190, quest_id=1009, quest_status=4)\""
    print "\tSSMSG_GM_ADD_LINGLI_REQ \t\"GMAddYinglingLingliRequest(player_id=99, add_lingli=-123)\""
    print "\tSSMSG_GM_SET_COOLDOWN_REQ \t\"GMSetCooldownRequest(player_id=99, cool_down_type=5, cool_down_value=120)\""
    print "\tSSMSG_GM_SET_LIMITCOUNT_REQ \t\"GMSetLimitCountRequest(player_id=99, limit_type=5, count_value=120)\""
    print "\tSSMSG_GM_SET_VIP_LEVEL_REQ \t\"GMSetPlayerVipLevelRequest(role_id=399, vip_level=1, vip_duration_sec=1500)\""
    print "\tSSMSG_GM_SET_FLAG_REQ \t\t\"GMSetFlagRequest(flag_type=32,value=0)\""
    print "\tSSMSG_GM_QUERY_FLAGS_REQ \t\t\"GmQueryPlayerFlagsRequest(player_id=1000132)\""
    print "\tSSMSG_GM_UPDATE_BIT_REQ \t\"UpdateBitRequest(bit=1,expired=1355701233,value=False)\""
    print "\tSSMSG_GM_UPDATE_PASS_INSTANCE_REQ \t\"GMUpdatePassInstance(instance_id=601,instance_grade=2)\""
    print "\tSSMSG_GM_SET_FIGHT_EXP_FACTOR_REQUEST\t\"GMSetFightExpFactorRequest(exp_factor=100,begin_time=int(time.time()),end_time=int(time.time())+60,begin_message='begin',end_message='end')\""
    print "\tSSMSG_GM_SET_GUILD_DATA_REQ \t\"GMSetGuildDataRequest(guild_id=601,exp=2,money=1)\""
    print "\tSSMSG_CHARGE_MONEY_REQ \t\"ChargeMoneyRequest(type=3,value=1000)\""
    print "\tSSMSG_GM_GET_ITEM_LIST_REQ \t\"GMGetItemListRequest(role_id=3,type=0)\""
    print "\tSSMSG_GM_GET_SKILL_LIST_REQ \t\"GMGetSkillListRequest(guid=13765371183782)\""
    print "\tSSMSG_GM_GET_TITLE_LIST_REQ \t\"GMGetTitleListRequest(role_id=3)\""
    print "\tSSMSG_GM_SET_ROLE_TITLE_REQ \t\"GMSetRoleTitleRequest(role_id=3,title_id=10011)\""
    print "\tSSMSG_GM_GET_TITLE_INFO_REQ \t\"GMGetTitleInfoRequest(title_id=10011)\""
    print "\tSSMSG_GM_SET_PVP_LEVEL_REQ \t\"GMSetPvPLevelRequest(level=19)\""
    print "\tSSMSG_GM_START_GUILD_TOWER_REQ \t\"GMStartGuildCrystalTowerRequest(guild_id=602, category=2)\""
    print "\tSSMSG_GM_WING_SPIRIT_ADD_SPIRIT_REQ \t\"GMWingSpiritAddSpiritRequest(role_id=601, tid=940127, level=5, exp=100000)\""
    print "\tSSMSG_GM_PLUGIN_REQ \t\"GMPluginRequest(plugin_name='print_player_name', role_id=601, arguments='')\""
    print "\tSSMSG_GM_SET_VIRTUAL_SPACE_TIME_REQ \t\"GMSetVirtualSpaceTimeRequest(hour=19, min=30) \""
    print "\tSSMSG_GM_SET_VIRTUAL_SPACE_LEVEL_REQ \t\"GMSetVirtualSpaceLevelRequest(level=50) \""
        
    print "\tSSMSG_GM_SUB_MONEY_REQ \t\"GMSubMoneyRequest(type=1, value=100, action_type=BUY_ONE_FLOWER) \""
    print "\tSSMSG_GM_SET_TITLE_REQ \t\"GMSetTitleRequest(role_id=1000101, title_id=10054) \""
    print "\tSSMSG_GM_SEND_WORLD_CHANNEL_MSG_REQ \t\"GMSendWorldChannelMsgRequest(role_id=1000101, msg='{\\\"msg\\\":\\\"hello,world\\\",\\\"smiley\\\":[]}' ) \""
    print "\tSSMSG_GM_SEND_MSG_TO_PLAYER_REQ \t\"GMSendMsgToPlayerRequest(src_role_id=1000101, dst_role_id=1000102, msg='{\\\"msg\\\":\\\"hello,world\\\",\\\"smiley\\\":[]}') \""
        
    print "\tSSMSG_GM_SEND_FLOWER_MSG_REQ \"GMSendFlowerMessageRequest(type=0, src_role_id=1000101, dst_role_id=0, format_msg='{\\\"msg\\\":\\\"hello,world\\\",\\\"smiley\\\":[]}') \""
        
    print "\tSSMSG_ADD_ACT_EXTRA_TIMER_REQ \"GMAddActExtraTimerRequest(act_id=8, start_time='10:00:00', end_time='10:50:00') \""
        
    print "\t SSMSG_GM_ADD_CAMP_POINT_REQ \t\"GMAddCampPointRequest(role_id=1000105, add_point=20)\""
    print "\t SSMSG_GM_GET_CAMP_INFO_REQ \t\"GMGetCampInfoRequest(camp_id=1)\""
    print "\t SSMSG_GM_GET_CAMP_PLAYER_REQ \t\"GMGetCampPlayerRequest(role_id=1000105)\""
    print ""


if __name__ == "__main__":
    try:
        if len(sys.argv) < 7 :
            print "usage:" , sys.argv[0] , " host port role_id action_id request_body resposne_body"
            show_command()
            exit(1)
        host = sys.argv[1]
        port = int(sys.argv[2])
        role_id = int(sys.argv[3])
        action_id = eval(sys.argv[4])
        request = eval(sys.argv[5])
        response = eval(sys.argv[6])
        do_gm_request(host,port,role_id,action_id,request,response)
        print response
 
    except KeyboardInterrupt:
        pass
