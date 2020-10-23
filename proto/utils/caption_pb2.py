# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/caption.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import ndarray_pb2 as proto_dot_utils_dot_ndarray__pb2
from proto.utils import tag_pb2 as proto_dot_utils_dot_tag__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/caption.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x19proto/utils/caption.proto\x1a\x19proto/utils/ndarray.proto\x1a\x15proto/utils/tag.proto\"d\n\x07\x43\x61ption\x12#\n\x11tokenized_caption\x18\x01 \x01(\x0b\x32\x08.NDArray\x12\x11\n\x03tag\x18\x02 \x03(\x0b\x32\x04.Tag\x12\x13\n\x0braw_caption\x18\x03 \x03(\t\x12\x0c\n\x04text\x18\x04 \x01(\tB\x0e\n\x05utilsZ\x05utilsb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_ndarray__pb2.DESCRIPTOR,proto_dot_utils_dot_tag__pb2.DESCRIPTOR,])




_CAPTION = _descriptor.Descriptor(
  name='Caption',
  full_name='Caption',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='tokenized_caption', full_name='Caption.tokenized_caption', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='tag', full_name='Caption.tag', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='raw_caption', full_name='Caption.raw_caption', index=2,
      number=3, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='text', full_name='Caption.text', index=3,
      number=4, type=9, cpp_type=9, label=1,
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
  serialized_start=79,
  serialized_end=179,
)

_CAPTION.fields_by_name['tokenized_caption'].message_type = proto_dot_utils_dot_ndarray__pb2._NDARRAY
_CAPTION.fields_by_name['tag'].message_type = proto_dot_utils_dot_tag__pb2._TAG
DESCRIPTOR.message_types_by_name['Caption'] = _CAPTION
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Caption = _reflection.GeneratedProtocolMessageType('Caption', (_message.Message,), {
  'DESCRIPTOR' : _CAPTION,
  '__module__' : 'proto.utils.caption_pb2'
  # @@protoc_insertion_point(class_scope:Caption)
  })
_sym_db.RegisterMessage(Caption)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)