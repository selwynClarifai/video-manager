# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/clarifai/model_fetching/resources.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import checkpoint_pb2 as proto_dot_utils_dot_checkpoint__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/clarifai/model_fetching/resources.proto',
  package='clarifai.model_fetching',
  syntax='proto3',
  serialized_options=b'\n\033com.clarifai.model_fetchingP\001Z\016model_fetching\242\002\004CAIP',
  serialized_pb=b'\n-proto/clarifai/model_fetching/resources.proto\x12\x17\x63larifai.model_fetching\x1a\x1cproto/utils/checkpoint.proto\"[\n\tModelInfo\x12\x10\n\x08model_id\x18\x01 \x01(\t\x12\x18\n\x10model_version_id\x18\x02 \x01(\t\x12\"\n\x0cmodel_format\x18\x03 \x01(\x0e\x32\x0c.ModelFormatB6\n\x1b\x63om.clarifai.model_fetchingP\x01Z\x0emodel_fetching\xa2\x02\x04\x43\x41IPb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_checkpoint__pb2.DESCRIPTOR,])




_MODELINFO = _descriptor.Descriptor(
  name='ModelInfo',
  full_name='clarifai.model_fetching.ModelInfo',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='model_id', full_name='clarifai.model_fetching.ModelInfo.model_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_version_id', full_name='clarifai.model_fetching.ModelInfo.model_version_id', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_format', full_name='clarifai.model_fetching.ModelInfo.model_format', index=2,
      number=3, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
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
  serialized_start=104,
  serialized_end=195,
)

_MODELINFO.fields_by_name['model_format'].enum_type = proto_dot_utils_dot_checkpoint__pb2._MODELFORMAT
DESCRIPTOR.message_types_by_name['ModelInfo'] = _MODELINFO
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ModelInfo = _reflection.GeneratedProtocolMessageType('ModelInfo', (_message.Message,), {
  'DESCRIPTOR' : _MODELINFO,
  '__module__' : 'proto.clarifai.model_fetching.resources_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.model_fetching.ModelInfo)
  })
_sym_db.RegisterMessage(ModelInfo)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
