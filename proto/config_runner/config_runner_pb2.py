# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/config_runner/config_runner.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import request_meta_pb2 as proto_dot_utils_dot_request__meta__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/config_runner/config_runner.proto',
  package='',
  syntax='proto3',
  serialized_options=None,
  serialized_pb=b'\n\'proto/config_runner/config_runner.proto\x1a\x1eproto/utils/request_meta.proto\"P\n\x10\x43onfigRunRequest\x12\x1a\n\x04meta\x18\x01 \x01(\x0b\x32\x0c.RequestMeta\x12\x0b\n\x03\x65id\x18\x02 \x01(\x03\x12\x13\n\x0b\x63onfig_json\x18\x03 \x01(\t\"\x94\x01\n\x11\x43onfigRunResponse\x12\x1f\n\x06status\x18\x01 \x01(\x0b\x32\x0f.ResponseStatus\x12\r\n\x05retry\x18\x04 \x01(\x08\x12\x17\n\x0f\x65xception_class\x18\x05 \x01(\t\x12\x19\n\x11\x65xception_message\x18\x06 \x01(\t\x12\x1b\n\x13\x65xception_traceback\x18\x07 \x01(\t\"-\n\x0fShutdownRequest\x12\x1a\n\x04meta\x18\x01 \x01(\x0b\x32\x0c.RequestMeta\"3\n\x10ShutdownResponse\x12\x1f\n\x06status\x18\x01 \x01(\x0b\x32\x0f.ResponseStatus2w\n\x0c\x43onfigRunner\x12\x34\n\tConfigRun\x12\x11.ConfigRunRequest\x1a\x12.ConfigRunResponse\"\x00\x12\x31\n\x08Shutdown\x12\x10.ShutdownRequest\x1a\x11.ShutdownResponse\"\x00\x62\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_request__meta__pb2.DESCRIPTOR,])




_CONFIGRUNREQUEST = _descriptor.Descriptor(
  name='ConfigRunRequest',
  full_name='ConfigRunRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='meta', full_name='ConfigRunRequest.meta', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='eid', full_name='ConfigRunRequest.eid', index=1,
      number=2, type=3, cpp_type=2, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='config_json', full_name='ConfigRunRequest.config_json', index=2,
      number=3, type=9, cpp_type=9, label=1,
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
  serialized_start=75,
  serialized_end=155,
)


_CONFIGRUNRESPONSE = _descriptor.Descriptor(
  name='ConfigRunResponse',
  full_name='ConfigRunResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='ConfigRunResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='retry', full_name='ConfigRunResponse.retry', index=1,
      number=4, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='exception_class', full_name='ConfigRunResponse.exception_class', index=2,
      number=5, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='exception_message', full_name='ConfigRunResponse.exception_message', index=3,
      number=6, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='exception_traceback', full_name='ConfigRunResponse.exception_traceback', index=4,
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
  serialized_start=158,
  serialized_end=306,
)


_SHUTDOWNREQUEST = _descriptor.Descriptor(
  name='ShutdownRequest',
  full_name='ShutdownRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='meta', full_name='ShutdownRequest.meta', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
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
  serialized_start=308,
  serialized_end=353,
)


_SHUTDOWNRESPONSE = _descriptor.Descriptor(
  name='ShutdownResponse',
  full_name='ShutdownResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='ShutdownResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
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
  serialized_start=355,
  serialized_end=406,
)

_CONFIGRUNREQUEST.fields_by_name['meta'].message_type = proto_dot_utils_dot_request__meta__pb2._REQUESTMETA
_CONFIGRUNRESPONSE.fields_by_name['status'].message_type = proto_dot_utils_dot_request__meta__pb2._RESPONSESTATUS
_SHUTDOWNREQUEST.fields_by_name['meta'].message_type = proto_dot_utils_dot_request__meta__pb2._REQUESTMETA
_SHUTDOWNRESPONSE.fields_by_name['status'].message_type = proto_dot_utils_dot_request__meta__pb2._RESPONSESTATUS
DESCRIPTOR.message_types_by_name['ConfigRunRequest'] = _CONFIGRUNREQUEST
DESCRIPTOR.message_types_by_name['ConfigRunResponse'] = _CONFIGRUNRESPONSE
DESCRIPTOR.message_types_by_name['ShutdownRequest'] = _SHUTDOWNREQUEST
DESCRIPTOR.message_types_by_name['ShutdownResponse'] = _SHUTDOWNRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ConfigRunRequest = _reflection.GeneratedProtocolMessageType('ConfigRunRequest', (_message.Message,), {
  'DESCRIPTOR' : _CONFIGRUNREQUEST,
  '__module__' : 'proto.config_runner.config_runner_pb2'
  # @@protoc_insertion_point(class_scope:ConfigRunRequest)
  })
_sym_db.RegisterMessage(ConfigRunRequest)

ConfigRunResponse = _reflection.GeneratedProtocolMessageType('ConfigRunResponse', (_message.Message,), {
  'DESCRIPTOR' : _CONFIGRUNRESPONSE,
  '__module__' : 'proto.config_runner.config_runner_pb2'
  # @@protoc_insertion_point(class_scope:ConfigRunResponse)
  })
_sym_db.RegisterMessage(ConfigRunResponse)

ShutdownRequest = _reflection.GeneratedProtocolMessageType('ShutdownRequest', (_message.Message,), {
  'DESCRIPTOR' : _SHUTDOWNREQUEST,
  '__module__' : 'proto.config_runner.config_runner_pb2'
  # @@protoc_insertion_point(class_scope:ShutdownRequest)
  })
_sym_db.RegisterMessage(ShutdownRequest)

ShutdownResponse = _reflection.GeneratedProtocolMessageType('ShutdownResponse', (_message.Message,), {
  'DESCRIPTOR' : _SHUTDOWNRESPONSE,
  '__module__' : 'proto.config_runner.config_runner_pb2'
  # @@protoc_insertion_point(class_scope:ShutdownResponse)
  })
_sym_db.RegisterMessage(ShutdownResponse)



_CONFIGRUNNER = _descriptor.ServiceDescriptor(
  name='ConfigRunner',
  full_name='ConfigRunner',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=408,
  serialized_end=527,
  methods=[
  _descriptor.MethodDescriptor(
    name='ConfigRun',
    full_name='ConfigRunner.ConfigRun',
    index=0,
    containing_service=None,
    input_type=_CONFIGRUNREQUEST,
    output_type=_CONFIGRUNRESPONSE,
    serialized_options=None,
  ),
  _descriptor.MethodDescriptor(
    name='Shutdown',
    full_name='ConfigRunner.Shutdown',
    index=1,
    containing_service=None,
    input_type=_SHUTDOWNREQUEST,
    output_type=_SHUTDOWNRESPONSE,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_CONFIGRUNNER)

DESCRIPTOR.services_by_name['ConfigRunner'] = _CONFIGRUNNER

# @@protoc_insertion_point(module_scope)