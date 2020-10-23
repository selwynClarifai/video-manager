# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/boundingbox.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import embedding_pb2 as proto_dot_utils_dot_embedding__pb2
from proto.utils import tag_pb2 as proto_dot_utils_dot_tag__pb2
from proto.clarifai.api.utils import extensions_pb2 as proto_dot_clarifai_dot_api_dot_utils_dot_extensions__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/boundingbox.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x1dproto/utils/boundingbox.proto\x1a\x1bproto/utils/embedding.proto\x1a\x15proto/utils/tag.proto\x1a)proto/clarifai/api/utils/extensions.proto\"\xc8\x01\n\x0b\x42oundingBox\x12\x11\n\x03tag\x18\x01 \x03(\x0b\x32\x04.Tag\x12\x15\n\x07top_row\x18\x03 \x01(\x02\x42\x04\x80\xb5\x18\x01\x12\x16\n\x08left_col\x18\x04 \x01(\x02\x42\x04\x80\xb5\x18\x01\x12\x18\n\nbottom_row\x18\x05 \x01(\x02\x42\x04\x80\xb5\x18\x01\x12\x17\n\tright_col\x18\x06 \x01(\x02\x42\x04\x80\xb5\x18\x01\x12\x13\n\x0bis_positive\x18\x07 \x01(\x08\x12\x1d\n\tembedding\x18\x08 \x03(\x0b\x32\n.Embedding\x12\x10\n\x08track_id\x18\t \x01(\x05\x42\x0e\n\x05utilsZ\x05utilsb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_embedding__pb2.DESCRIPTOR,proto_dot_utils_dot_tag__pb2.DESCRIPTOR,proto_dot_clarifai_dot_api_dot_utils_dot_extensions__pb2.DESCRIPTOR,])




_BOUNDINGBOX = _descriptor.Descriptor(
  name='BoundingBox',
  full_name='BoundingBox',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='tag', full_name='BoundingBox.tag', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='top_row', full_name='BoundingBox.top_row', index=1,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\200\265\030\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='left_col', full_name='BoundingBox.left_col', index=2,
      number=4, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\200\265\030\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='bottom_row', full_name='BoundingBox.bottom_row', index=3,
      number=5, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\200\265\030\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='right_col', full_name='BoundingBox.right_col', index=4,
      number=6, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\200\265\030\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='is_positive', full_name='BoundingBox.is_positive', index=5,
      number=7, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='embedding', full_name='BoundingBox.embedding', index=6,
      number=8, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='track_id', full_name='BoundingBox.track_id', index=7,
      number=9, type=5, cpp_type=1, label=1,
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
  serialized_start=129,
  serialized_end=329,
)

_BOUNDINGBOX.fields_by_name['tag'].message_type = proto_dot_utils_dot_tag__pb2._TAG
_BOUNDINGBOX.fields_by_name['embedding'].message_type = proto_dot_utils_dot_embedding__pb2._EMBEDDING
DESCRIPTOR.message_types_by_name['BoundingBox'] = _BOUNDINGBOX
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

BoundingBox = _reflection.GeneratedProtocolMessageType('BoundingBox', (_message.Message,), {
  'DESCRIPTOR' : _BOUNDINGBOX,
  '__module__' : 'proto.utils.boundingbox_pb2'
  # @@protoc_insertion_point(class_scope:BoundingBox)
  })
_sym_db.RegisterMessage(BoundingBox)


DESCRIPTOR._options = None
_BOUNDINGBOX.fields_by_name['top_row']._options = None
_BOUNDINGBOX.fields_by_name['left_col']._options = None
_BOUNDINGBOX.fields_by_name['bottom_row']._options = None
_BOUNDINGBOX.fields_by_name['right_col']._options = None
# @@protoc_insertion_point(module_scope)
