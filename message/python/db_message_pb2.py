# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: db_message.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)


import tb_user_pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='db_message.proto',
  package='',
  serialized_pb='\n\x10\x64\x62_message.proto\x1a\rtb_user.proto\"/\n\nDBUserItem\x12\x0f\n\x07item_id\x18\x01 \x02(\x05\x12\x10\n\x08item_num\x18\x02 \x02(\x05\"0\n\x0e\x44\x42UserItemList\x12\x1e\n\titem_list\x18\x01 \x03(\x0b\x32\x0b.DBUserItem\"H\n\x0b\x44\x42\x43ommonReq\x12\x0b\n\x03seq\x18\x01 \x02(\x05\x12\x14\n\x0coperate_type\x18\x02 \x02(\x05\x12\x16\n\x0eoperate_string\x18\x03 \x02(\t\"\x86\x01\n\x0b\x44\x42\x43ommonRep\x12\x0b\n\x03ret\x18\x01 \x02(\x05\x12\x0b\n\x03seq\x18\x02 \x02(\x05\x12\x14\n\x0coperate_type\x18\x03 \x02(\x05\x12\x1e\n\tuser_info\x18\x04 \x01(\x0b\x32\x0b.db_tb_user\x12\'\n\x0euser_item_list\x18\x05 \x01(\x0b\x32\x0f.DBUserItemList*R\n\rDbOperateType\x12\x13\n\x0e\x44\x42_WORK_UPDATE\x10\x90N\x12\x15\n\x10\x44\x42_GET_USER_INFO\x10\x91N\x12\x15\n\x10\x44\x42_GET_ITEM_LIST\x10\x92N')

_DBOPERATETYPE = _descriptor.EnumDescriptor(
  name='DbOperateType',
  full_name='DbOperateType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='DB_WORK_UPDATE', index=0, number=10000,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DB_GET_USER_INFO', index=1, number=10001,
      options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DB_GET_ITEM_LIST', index=2, number=10002,
      options=None,
      type=None),
  ],
  containing_type=None,
  options=None,
  serialized_start=345,
  serialized_end=427,
)

DbOperateType = enum_type_wrapper.EnumTypeWrapper(_DBOPERATETYPE)
DB_WORK_UPDATE = 10000
DB_GET_USER_INFO = 10001
DB_GET_ITEM_LIST = 10002



_DBUSERITEM = _descriptor.Descriptor(
  name='DBUserItem',
  full_name='DBUserItem',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='item_id', full_name='DBUserItem.item_id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='item_num', full_name='DBUserItem.item_num', index=1,
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
  serialized_start=35,
  serialized_end=82,
)


_DBUSERITEMLIST = _descriptor.Descriptor(
  name='DBUserItemList',
  full_name='DBUserItemList',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='item_list', full_name='DBUserItemList.item_list', index=0,
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
  serialized_start=84,
  serialized_end=132,
)


_DBCOMMONREQ = _descriptor.Descriptor(
  name='DBCommonReq',
  full_name='DBCommonReq',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='seq', full_name='DBCommonReq.seq', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='operate_type', full_name='DBCommonReq.operate_type', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='operate_string', full_name='DBCommonReq.operate_string', index=2,
      number=3, type=9, cpp_type=9, label=2,
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
  serialized_start=134,
  serialized_end=206,
)


_DBCOMMONREP = _descriptor.Descriptor(
  name='DBCommonRep',
  full_name='DBCommonRep',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ret', full_name='DBCommonRep.ret', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='seq', full_name='DBCommonRep.seq', index=1,
      number=2, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='operate_type', full_name='DBCommonRep.operate_type', index=2,
      number=3, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_info', full_name='DBCommonRep.user_info', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_item_list', full_name='DBCommonRep.user_item_list', index=4,
      number=5, type=11, cpp_type=10, label=1,
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
  serialized_start=209,
  serialized_end=343,
)

_DBUSERITEMLIST.fields_by_name['item_list'].message_type = _DBUSERITEM
_DBCOMMONREP.fields_by_name['user_info'].message_type = tb_user_pb2._DB_TB_USER
_DBCOMMONREP.fields_by_name['user_item_list'].message_type = _DBUSERITEMLIST
DESCRIPTOR.message_types_by_name['DBUserItem'] = _DBUSERITEM
DESCRIPTOR.message_types_by_name['DBUserItemList'] = _DBUSERITEMLIST
DESCRIPTOR.message_types_by_name['DBCommonReq'] = _DBCOMMONREQ
DESCRIPTOR.message_types_by_name['DBCommonRep'] = _DBCOMMONREP

class DBUserItem(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _DBUSERITEM

  # @@protoc_insertion_point(class_scope:DBUserItem)

class DBUserItemList(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _DBUSERITEMLIST

  # @@protoc_insertion_point(class_scope:DBUserItemList)

class DBCommonReq(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _DBCOMMONREQ

  # @@protoc_insertion_point(class_scope:DBCommonReq)

class DBCommonRep(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _DBCOMMONREP

  # @@protoc_insertion_point(class_scope:DBCommonRep)


# @@protoc_insertion_point(module_scope)
