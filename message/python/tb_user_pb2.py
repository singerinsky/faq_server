# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: tb_user.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)




DESCRIPTOR = _descriptor.FileDescriptor(
  name='tb_user.proto',
  package='',
  serialized_pb='\n\rtb_user.proto\"h\n\ndb_tb_user\x12\n\n\x02id\x18\x01 \x02(\x05\x12\x11\n\tuser_name\x18\x02 \x02(\t\x12\r\n\x05level\x18\x03 \x02(\x05\x12\x0e\n\x06map_id\x18\x04 \x02(\x05\x12\r\n\x05pos_x\x18\x05 \x02(\x05\x12\r\n\x05pos_y\x18\x06 \x02(\x05')




_DB_TB_USER = _descriptor.Descriptor(
  name='db_tb_user',
  full_name='db_tb_user',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='db_tb_user.id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='user_name', full_name='db_tb_user.user_name', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=unicode("", "utf-8"),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='level', full_name='db_tb_user.level', index=2,
      number=3, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='map_id', full_name='db_tb_user.map_id', index=3,
      number=4, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos_x', full_name='db_tb_user.pos_x', index=4,
      number=5, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='pos_y', full_name='db_tb_user.pos_y', index=5,
      number=6, type=5, cpp_type=1, label=2,
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
  serialized_start=17,
  serialized_end=121,
)

DESCRIPTOR.message_types_by_name['db_tb_user'] = _DB_TB_USER

class db_tb_user(_message.Message):
  __metaclass__ = _reflection.GeneratedProtocolMessageType
  DESCRIPTOR = _DB_TB_USER

  # @@protoc_insertion_point(class_scope:db_tb_user)


# @@protoc_insertion_point(module_scope)
