# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: message.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import db_message_pb2
import tb_user_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='message.proto',
  package='',
  serialized_pb='\n\rmessage.proto\x1a\x10\x64\x62_message.proto\x1a\rtb_user.proto\"\x1f\n\x07PosInfo\x12\t\n\x01x\x18\x01 \x02(\x05\x12\t\n\x01y\x18\x02 \x02(\x05\"\x8f\x01\n\nPlayerInfo\x12\x11\n\tplayer_id\x18\x01 \x02(\x05\x12\x17\n\x0fplayer_nickname\x18\x02 \x02(\t\x12\x14\n\x0cplayer_level\x18\x03 \x02(\x05\x12\x11\n\tcareer_id\x18\x04 \x02(\x05\x12\x15\n\rplayer_status\x18\x05 \x02(\x05\x12\x15\n\x03pos\x18\x06 \x02(\x0b\x32\x08.PosInfo\"\x80\x01\n\x07NpcInfo\x12\x0e\n\x06npc_id\x18\x01 \x02(\x05\x12\x14\n\x0cnpc_nickname\x18\x02 \x02(\t\x12\x11\n\tnpc_level\x18\x03 \x02(\x05\x12\x11\n\ttotoal_hp\x18\x04 \x02(\x05\x12\x12\n\ncurrent_hp\x18\x05 \x02(\x05\x12\x15\n\x03pos\x18\x06 \x02(\x0b\x32\x08.PosInfo\"-\n\x16\x43lientHeartBeatRequest\x12\x13\n\x0b\x63lient_time\x18\x01 \x02(\x05\".\n\x17\x43lientHeartBeatResponse\x12\x13\n\x0bserver_time\x18\x01 \x02(\x05\"4\n\x12\x43lientLoginRequest\x12\x0f\n\x07role_id\x18\x01 \x02(\x05\x12\r\n\x05token\x18\x02 \x02(\t\"\"\n\x13\x43lientLoginResponse\x12\x0b\n\x03ret\x18\x01 \x02(\x05\"=\n\x0e\x43lientInitNotf\x12\x0b\n\x03ret\x18\x01 \x02(\x05\x12\x1e\n\tuser_info\x18\x02 \x02(\x0b\x32\x0b.db_tb_user\"A\n\x11\x43lientMoveRequest\x12\x0e\n\x06map_id\x18\x01 \x02(\x05\x12\r\n\x05pos_x\x18\x02 \x02(\x05\x12\r\n\x05pos_y\x18\x03 \x02(\x05\"O\n\x12\x43lientMoveResponse\x12\x0b\n\x03ret\x18\x01 \x02(\x05\x12\x0e\n\x06map_id\x18\x02 \x01(\x05\x12\r\n\x05pos_x\x18\x03 \x01(\x05\x12\r\n\x05pos_y\x18\x04 \x01(\x05\"(\n\x13PlayerLeaveViewNotf\x12\x11\n\tplayer_id\x18\x01 \x02(\x05\")\n\x14LeavePlayersViewNotf\x12\x11\n\tplayer_id\x18\x01 \x03(\x05\"\"\n\x10LeaveNpcViewNotf\x12\x0e\n\x06npc_id\x18\x01 \x02(\x05\"7\n\x13PlayerEnterViewNotf\x12 \n\x0bplayer_info\x18\x01 \x02(\x0b\x32\x0b.PlayerInfo\"8\n\x14\x45nterPlayersViewNotf\x12 \n\x0bplayer_info\x18\x01 \x03(\x0b\x32\x0b.PlayerInfo\"/\n\x11\x45nterNpcsViewNotf\x12\x1a\n\x08npc_info\x18\x01 \x03(\x0b\x32\x08.NpcInfo\"=\n\x16PlayerAttackNpcRequest\x12\x0e\n\x06npc_id\x18\x01 \x02(\x05\x12\x13\n\x0b\x61ttack_type\x18\x02 \x02(\x05\"&\n\x17PlayerAttackNpcResponse\x12\x0b\n\x03ret\x18\x01 \x02(\x05*D\n\x0fMSG_ACTION_TYPE\x12\x0f\n\x0bMSG_REQUEST\x10\x00\x12\x10\n\x0cMSG_RESPONSE\x10\x01\x12\x0e\n\nMSG_NOTIFY\x10\x02*\xee\x02\n\x0bMessageType\x12\x1a\n\x16MSG_SOCCER_PLAYER_INFO\x10\x01\x12\x12\n\x0eMSG_HEART_BEAT\x10\x02\x12\x14\n\x10MSG_CLIENT_LOGIN\x10\x03\x12\x1c\n\x18MSG_GATE_SERVER_REGISTER\x10\x04\x12\x13\n\x0fMSG_INIT_CLIENT\x10\x05\x12\x13\n\x0fMSG_CLIENT_MOVE\x10\x06\x12\x1e\n\x1aMSG_PLAYER_LEAVE_VIEW_NOTF\x10\x07\x12\x1f\n\x1bMSG_LEAVE_PLAYERS_VIEW_NOTF\x10\x08\x12\x1e\n\x1aMSG_PLAYER_ENTER_VIEW_NOTF\x10\t\x12\x1f\n\x1bMSG_ENTER_PLAYERS_VIEW_NOTF\x10\n\x12\x1c\n\x18MSG_ENTER_NPCS_VIEW_NOTF\x10\x0b\x12\x16\n\x12MSG_LEAVE_NPC_NOTF\x10\x0c\x12\x19\n\x15MSG_PLAYER_ATTACK_NPC\x10\r*#\n\rDbMessageType\x12\x12\n\rMSG_DB_COMMON\x10\x90N')

_MSG_ACTION_TYPE = _descriptor.EnumDescriptor(
  name='MSG_ACTION_TYPE',
  full_name='MSG_ACTION_TYPE',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='MSG_REQUEST', index=0, number=0,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_RESPONSE', index=1, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_NOTIFY', index=2, number=2,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=1144,
  serialized_end=1212,
)

MSG_ACTION_TYPE = enum_type_wrapper.EnumTypeWrapper(_MSG_ACTION_TYPE)
_MESSAGETYPE = _descriptor.EnumDescriptor(
  name='MessageType',
  full_name='MessageType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='MSG_SOCCER_PLAYER_INFO', index=0, number=1,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_HEART_BEAT', index=1, number=2,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_CLIENT_LOGIN', index=2, number=3,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_GATE_SERVER_REGISTER', index=3, number=4,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_INIT_CLIENT', index=4, number=5,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_CLIENT_MOVE', index=5, number=6,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_PLAYER_LEAVE_VIEW_NOTF', index=6, number=7,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_LEAVE_PLAYERS_VIEW_NOTF', index=7, number=8,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_PLAYER_ENTER_VIEW_NOTF', index=8, number=9,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ENTER_PLAYERS_VIEW_NOTF', index=9, number=10,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_ENTER_NPCS_VIEW_NOTF', index=10, number=11,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_LEAVE_NPC_NOTF', index=11, number=12,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='MSG_PLAYER_ATTACK_NPC', index=12, number=13,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=1215,
  serialized_end=1581,
)

MessageType = enum_type_wrapper.EnumTypeWrapper(_MESSAGETYPE)
_DBMESSAGETYPE = _descriptor.EnumDescriptor(
  name='DbMessageType',
  full_name='DbMessageType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='MSG_DB_COMMON', index=0, number=10000,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=1583,
  serialized_end=1618,
)

DbMessageType = enum_type_wrapper.EnumTypeWrapper(_DBMESSAGETYPE)
MSG_REQUEST = 0
MSG_RESPONSE = 1
MSG_NOTIFY = 2
MSG_SOCCER_PLAYER_INFO = 1
MSG_HEART_BEAT = 2
MSG_CLIENT_LOGIN = 3
MSG_GATE_SERVER_REGISTER = 4
MSG_INIT_CLIENT = 5
MSG_CLIENT_MOVE = 6
MSG_PLAYER_LEAVE_VIEW_NOTF = 7
MSG_LEAVE_PLAYERS_VIEW_NOTF = 8
MSG_PLAYER_ENTER_VIEW_NOTF = 9
MSG_ENTER_PLAYERS_VIEW_NOTF = 10
MSG_ENTER_NPCS_VIEW_NOTF = 11
MSG_LEAVE_NPC_NOTF = 12
MSG_PLAYER_ATTACK_NPC = 13
MSG_DB_COMMON = 10000



_POSINFO = _descriptor.Descriptor(
  name='PosInfo',
  full_name='PosInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='x', full_name='PosInfo.x', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='y', full_name='PosInfo.y', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=50,
  serialized_end=81,
)


_PLAYERINFO = _descriptor.Descriptor(
  name='PlayerInfo',
  full_name='PlayerInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='player_id', full_name='PlayerInfo.player_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='player_nickname', full_name='PlayerInfo.player_nickname', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='player_level', full_name='PlayerInfo.player_level', index=2,
      number=3, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='career_id', full_name='PlayerInfo.career_id', index=3,
      number=4, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='player_status', full_name='PlayerInfo.player_status', index=4,
      number=5, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos', full_name='PlayerInfo.pos', index=5,
      number=6, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=84,
  serialized_end=227,
)


_NPCINFO = _descriptor.Descriptor(
  name='NpcInfo',
  full_name='NpcInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='npc_id', full_name='NpcInfo.npc_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='npc_nickname', full_name='NpcInfo.npc_nickname', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='npc_level', full_name='NpcInfo.npc_level', index=2,
      number=3, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='totoal_hp', full_name='NpcInfo.totoal_hp', index=3,
      number=4, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='current_hp', full_name='NpcInfo.current_hp', index=4,
      number=5, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos', full_name='NpcInfo.pos', index=5,
      number=6, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=230,
  serialized_end=358,
)


_CLIENTHEARTBEATREQUEST = _descriptor.Descriptor(
  name='ClientHeartBeatRequest',
  full_name='ClientHeartBeatRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='client_time', full_name='ClientHeartBeatRequest.client_time', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=360,
  serialized_end=405,
)


_CLIENTHEARTBEATRESPONSE = _descriptor.Descriptor(
  name='ClientHeartBeatResponse',
  full_name='ClientHeartBeatResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='server_time', full_name='ClientHeartBeatResponse.server_time', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=407,
  serialized_end=453,
)


_CLIENTLOGINREQUEST = _descriptor.Descriptor(
  name='ClientLoginRequest',
  full_name='ClientLoginRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='role_id', full_name='ClientLoginRequest.role_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='token', full_name='ClientLoginRequest.token', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=455,
  serialized_end=507,
)


_CLIENTLOGINRESPONSE = _descriptor.Descriptor(
  name='ClientLoginResponse',
  full_name='ClientLoginResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ret', full_name='ClientLoginResponse.ret', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=509,
  serialized_end=543,
)


_CLIENTINITNOTF = _descriptor.Descriptor(
  name='ClientInitNotf',
  full_name='ClientInitNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ret', full_name='ClientInitNotf.ret', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_info', full_name='ClientInitNotf.user_info', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=545,
  serialized_end=606,
)


_CLIENTMOVEREQUEST = _descriptor.Descriptor(
  name='ClientMoveRequest',
  full_name='ClientMoveRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='map_id', full_name='ClientMoveRequest.map_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos_x', full_name='ClientMoveRequest.pos_x', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos_y', full_name='ClientMoveRequest.pos_y', index=2,
      number=3, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=608,
  serialized_end=673,
)


_CLIENTMOVERESPONSE = _descriptor.Descriptor(
  name='ClientMoveResponse',
  full_name='ClientMoveResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ret', full_name='ClientMoveResponse.ret', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='map_id', full_name='ClientMoveResponse.map_id', index=1,
      number=2, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos_x', full_name='ClientMoveResponse.pos_x', index=2,
      number=3, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos_y', full_name='ClientMoveResponse.pos_y', index=3,
      number=4, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=675,
  serialized_end=754,
)


_PLAYERLEAVEVIEWNOTF = _descriptor.Descriptor(
  name='PlayerLeaveViewNotf',
  full_name='PlayerLeaveViewNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='player_id', full_name='PlayerLeaveViewNotf.player_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=756,
  serialized_end=796,
)


_LEAVEPLAYERSVIEWNOTF = _descriptor.Descriptor(
  name='LeavePlayersViewNotf',
  full_name='LeavePlayersViewNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='player_id', full_name='LeavePlayersViewNotf.player_id', index=0,
      number=1, type=5, cpp_type=1, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=798,
  serialized_end=839,
)


_LEAVENPCVIEWNOTF = _descriptor.Descriptor(
  name='LeaveNpcViewNotf',
  full_name='LeaveNpcViewNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='npc_id', full_name='LeaveNpcViewNotf.npc_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=841,
  serialized_end=875,
)


_PLAYERENTERVIEWNOTF = _descriptor.Descriptor(
  name='PlayerEnterViewNotf',
  full_name='PlayerEnterViewNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='player_info', full_name='PlayerEnterViewNotf.player_info', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=877,
  serialized_end=932,
)


_ENTERPLAYERSVIEWNOTF = _descriptor.Descriptor(
  name='EnterPlayersViewNotf',
  full_name='EnterPlayersViewNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='player_info', full_name='EnterPlayersViewNotf.player_info', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=934,
  serialized_end=990,
)


_ENTERNPCSVIEWNOTF = _descriptor.Descriptor(
  name='EnterNpcsViewNotf',
  full_name='EnterNpcsViewNotf',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='npc_info', full_name='EnterNpcsViewNotf.npc_info', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=992,
  serialized_end=1039,
)


_PLAYERATTACKNPCREQUEST = _descriptor.Descriptor(
  name='PlayerAttackNpcRequest',
  full_name='PlayerAttackNpcRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='npc_id', full_name='PlayerAttackNpcRequest.npc_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='attack_type', full_name='PlayerAttackNpcRequest.attack_type', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=1041,
  serialized_end=1102,
)


_PLAYERATTACKNPCRESPONSE = _descriptor.Descriptor(
  name='PlayerAttackNpcResponse',
  full_name='PlayerAttackNpcResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ret', full_name='PlayerAttackNpcResponse.ret', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  serialized_start=1104,
  serialized_end=1142,
)

_PLAYERINFO.fields_by_name['pos'].message_type = _POSINFO
_NPCINFO.fields_by_name['pos'].message_type = _POSINFO
_CLIENTINITNOTF.fields_by_name['user_info'].message_type = tb_user_pb2._DB_TB_USER
_PLAYERENTERVIEWNOTF.fields_by_name['player_info'].message_type = _PLAYERINFO
_ENTERPLAYERSVIEWNOTF.fields_by_name['player_info'].message_type = _PLAYERINFO
_ENTERNPCSVIEWNOTF.fields_by_name['npc_info'].message_type = _NPCINFO
DESCRIPTOR.message_types_by_name['PosInfo'] = _POSINFO
DESCRIPTOR.message_types_by_name['PlayerInfo'] = _PLAYERINFO
DESCRIPTOR.message_types_by_name['NpcInfo'] = _NPCINFO
DESCRIPTOR.message_types_by_name['ClientHeartBeatRequest'] = _CLIENTHEARTBEATREQUEST
DESCRIPTOR.message_types_by_name['ClientHeartBeatResponse'] = _CLIENTHEARTBEATRESPONSE
DESCRIPTOR.message_types_by_name['ClientLoginRequest'] = _CLIENTLOGINREQUEST
DESCRIPTOR.message_types_by_name['ClientLoginResponse'] = _CLIENTLOGINRESPONSE
DESCRIPTOR.message_types_by_name['ClientInitNotf'] = _CLIENTINITNOTF
DESCRIPTOR.message_types_by_name['ClientMoveRequest'] = _CLIENTMOVEREQUEST
DESCRIPTOR.message_types_by_name['ClientMoveResponse'] = _CLIENTMOVERESPONSE
DESCRIPTOR.message_types_by_name['PlayerLeaveViewNotf'] = _PLAYERLEAVEVIEWNOTF
DESCRIPTOR.message_types_by_name['LeavePlayersViewNotf'] = _LEAVEPLAYERSVIEWNOTF
DESCRIPTOR.message_types_by_name['LeaveNpcViewNotf'] = _LEAVENPCVIEWNOTF
DESCRIPTOR.message_types_by_name['PlayerEnterViewNotf'] = _PLAYERENTERVIEWNOTF
DESCRIPTOR.message_types_by_name['EnterPlayersViewNotf'] = _ENTERPLAYERSVIEWNOTF
DESCRIPTOR.message_types_by_name['EnterNpcsViewNotf'] = _ENTERNPCSVIEWNOTF
DESCRIPTOR.message_types_by_name['PlayerAttackNpcRequest'] = _PLAYERATTACKNPCREQUEST
DESCRIPTOR.message_types_by_name['PlayerAttackNpcResponse'] = _PLAYERATTACKNPCRESPONSE

class PosInfo(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _POSINFO

  # @@protoc_insertion_point(class_scope:PosInfo)

class PlayerInfo(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _PLAYERINFO

  # @@protoc_insertion_point(class_scope:PlayerInfo)

class NpcInfo(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _NPCINFO

  # @@protoc_insertion_point(class_scope:NpcInfo)

class ClientHeartBeatRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTHEARTBEATREQUEST

  # @@protoc_insertion_point(class_scope:ClientHeartBeatRequest)

class ClientHeartBeatResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTHEARTBEATRESPONSE

  # @@protoc_insertion_point(class_scope:ClientHeartBeatResponse)

class ClientLoginRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTLOGINREQUEST

  # @@protoc_insertion_point(class_scope:ClientLoginRequest)

class ClientLoginResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTLOGINRESPONSE

  # @@protoc_insertion_point(class_scope:ClientLoginResponse)

class ClientInitNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTINITNOTF

  # @@protoc_insertion_point(class_scope:ClientInitNotf)

class ClientMoveRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTMOVEREQUEST

  # @@protoc_insertion_point(class_scope:ClientMoveRequest)

class ClientMoveResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _CLIENTMOVERESPONSE

  # @@protoc_insertion_point(class_scope:ClientMoveResponse)

class PlayerLeaveViewNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _PLAYERLEAVEVIEWNOTF

  # @@protoc_insertion_point(class_scope:PlayerLeaveViewNotf)

class LeavePlayersViewNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LEAVEPLAYERSVIEWNOTF

  # @@protoc_insertion_point(class_scope:LeavePlayersViewNotf)

class LeaveNpcViewNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _LEAVENPCVIEWNOTF

  # @@protoc_insertion_point(class_scope:LeaveNpcViewNotf)

class PlayerEnterViewNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _PLAYERENTERVIEWNOTF

  # @@protoc_insertion_point(class_scope:PlayerEnterViewNotf)

class EnterPlayersViewNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _ENTERPLAYERSVIEWNOTF

  # @@protoc_insertion_point(class_scope:EnterPlayersViewNotf)

class EnterNpcsViewNotf(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _ENTERNPCSVIEWNOTF

  # @@protoc_insertion_point(class_scope:EnterNpcsViewNotf)

class PlayerAttackNpcRequest(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _PLAYERATTACKNPCREQUEST

  # @@protoc_insertion_point(class_scope:PlayerAttackNpcRequest)

class PlayerAttackNpcResponse(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _PLAYERATTACKNPCRESPONSE

  # @@protoc_insertion_point(class_scope:PlayerAttackNpcResponse)


# @@protoc_insertion_point(module_scope)
