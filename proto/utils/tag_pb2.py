# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/tag.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/tag.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x15proto/utils/tag.proto\"\xa3\x01\n\x03Tag\x12\x11\n\tlabel_num\x18\x01 \x01(\x05\x12\x13\n\x0blabel_value\x18\x02 \x01(\x02\x12\x0c\n\x04\x61iid\x18\x03 \x01(\t\x12\r\n\x05\x63name\x18\x04 \x01(\t\x12\x1e\n\x16user_unique_concept_id\x18\x05 \x01(\t\x12\x1a\n\x12user_unique_app_id\x18\x06 \x01(\t\x12\x1b\n\x13user_unique_user_id\x18\x07 \x01(\tB\x0e\n\x05utilsZ\x05utilsb\x06proto3'
)




_TAG = _descriptor.Descriptor(
  name='Tag',
  full_name='Tag',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='label_num', full_name='Tag.label_num', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='label_value', full_name='Tag.label_value', index=1,
      number=2, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='aiid', full_name='Tag.aiid', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='cname', full_name='Tag.cname', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='user_unique_concept_id', full_name='Tag.user_unique_concept_id', index=4,
      number=5, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='user_unique_app_id', full_name='Tag.user_unique_app_id', index=5,
      number=6, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='user_unique_user_id', full_name='Tag.user_unique_user_id', index=6,
      number=7, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=26,
  serialized_end=189,
)

DESCRIPTOR.message_types_by_name['Tag'] = _TAG
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Tag = _reflection.GeneratedProtocolMessageType('Tag', (_message.Message,), {
  'DESCRIPTOR' : _TAG,
  '__module__' : 'proto.utils.tag_pb2'
  # @@protoc_insertion_point(class_scope:Tag)
  })
_sym_db.RegisterMessage(Tag)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
