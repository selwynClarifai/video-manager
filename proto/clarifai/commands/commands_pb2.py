# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/clarifai/commands/commands.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from google.protobuf import timestamp_pb2 as google_dot_protobuf_dot_timestamp__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/clarifai/commands/commands.proto',
  package='clarifai.commands',
  syntax='proto3',
  serialized_options=b'\n\025com.clarifai.commandsP\001Z\010commands\242\002\004CAIP',
  serialized_pb=b'\n&proto/clarifai/commands/commands.proto\x12\x11\x63larifai.commands\x1a\x1fgoogle/protobuf/timestamp.proto\"\x88\x01\n\x08\x43ommands\x12;\n\x17\x64iscard_data_older_than\x18\x01 \x01(\x0b\x32\x1a.google.protobuf.Timestamp\x12\x15\n\rtimeout_delay\x18\x02 \x01(\r\x12\x17\n\x0fupload_interval\x18\x03 \x01(\r\x12\x0f\n\x07opt_out\x18\x04 \x01(\x08\x42*\n\x15\x63om.clarifai.commandsP\x01Z\x08\x63ommands\xa2\x02\x04\x43\x41IPb\x06proto3'
  ,
  dependencies=[google_dot_protobuf_dot_timestamp__pb2.DESCRIPTOR,])




_COMMANDS = _descriptor.Descriptor(
  name='Commands',
  full_name='clarifai.commands.Commands',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='discard_data_older_than', full_name='clarifai.commands.Commands.discard_data_older_than', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='timeout_delay', full_name='clarifai.commands.Commands.timeout_delay', index=1,
      number=2, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='upload_interval', full_name='clarifai.commands.Commands.upload_interval', index=2,
      number=3, type=13, cpp_type=3, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='opt_out', full_name='clarifai.commands.Commands.opt_out', index=3,
      number=4, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
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
  serialized_start=95,
  serialized_end=231,
)

_COMMANDS.fields_by_name['discard_data_older_than'].message_type = google_dot_protobuf_dot_timestamp__pb2._TIMESTAMP
DESCRIPTOR.message_types_by_name['Commands'] = _COMMANDS
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Commands = _reflection.GeneratedProtocolMessageType('Commands', (_message.Message,), {
  'DESCRIPTOR' : _COMMANDS,
  '__module__' : 'proto.clarifai.commands.commands_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.commands.Commands)
  })
_sym_db.RegisterMessage(Commands)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
