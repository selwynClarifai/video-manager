# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/vocab.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import tag_pb2 as proto_dot_utils_dot_tag__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/vocab.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x17proto/utils/vocab.proto\x1a\x15proto/utils/tag.proto\"q\n\x05Vocab\x12\x1c\n\x14user_unique_vocab_id\x18\x01 \x01(\t\x12\x1a\n\x12user_unique_app_id\x18\x02 \x01(\t\x12\x1b\n\x13user_unique_user_id\x18\x03 \x01(\t\x12\x11\n\x03tag\x18\x05 \x03(\x0b\x32\x04.TagB\x0e\n\x05utilsZ\x05utilsb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_tag__pb2.DESCRIPTOR,])




_VOCAB = _descriptor.Descriptor(
  name='Vocab',
  full_name='Vocab',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_unique_vocab_id', full_name='Vocab.user_unique_vocab_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='user_unique_app_id', full_name='Vocab.user_unique_app_id', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='user_unique_user_id', full_name='Vocab.user_unique_user_id', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='tag', full_name='Vocab.tag', index=3,
      number=5, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=50,
  serialized_end=163,
)

_VOCAB.fields_by_name['tag'].message_type = proto_dot_utils_dot_tag__pb2._TAG
DESCRIPTOR.message_types_by_name['Vocab'] = _VOCAB
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Vocab = _reflection.GeneratedProtocolMessageType('Vocab', (_message.Message,), {
  'DESCRIPTOR' : _VOCAB,
  '__module__' : 'proto.utils.vocab_pb2'
  # @@protoc_insertion_point(class_scope:Vocab)
  })
_sym_db.RegisterMessage(Vocab)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)