# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/text.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/text.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x16proto/utils/text.proto\"\x13\n\x04Text\x12\x0b\n\x03raw\x18\x01 \x01(\tB\x0e\n\x05utilsZ\x05utilsb\x06proto3'
)




_TEXT = _descriptor.Descriptor(
  name='Text',
  full_name='Text',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='raw', full_name='Text.raw', index=0,
      number=1, type=9, cpp_type=9, label=1,
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
  serialized_end=45,
)

DESCRIPTOR.message_types_by_name['Text'] = _TEXT
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Text = _reflection.GeneratedProtocolMessageType('Text', (_message.Message,), {
  'DESCRIPTOR' : _TEXT,
  '__module__' : 'proto.utils.text_pb2'
  # @@protoc_insertion_point(class_scope:Text)
  })
_sym_db.RegisterMessage(Text)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
