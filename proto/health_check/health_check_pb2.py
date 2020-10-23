# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/health_check/health_check.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import request_meta_pb2 as proto_dot_utils_dot_request__meta__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/health_check/health_check.proto',
  package='',
  syntax='proto3',
  serialized_options=b'Z\014health_check',
  serialized_pb=b'\n%proto/health_check/health_check.proto\x1a\x1eproto/utils/request_meta.proto\"A\n\x12HealthCheckRequest\x12\x1a\n\x04meta\x18\x01 \x01(\x0b\x32\x0c.RequestMeta\x12\x0f\n\x07service\x18\x02 \x01(\t\"\xae\x01\n\x13HealthCheckResponse\x12\x1f\n\x06status\x18\x01 \x01(\x0b\x32\x0f.ResponseStatus\x12:\n\x0eserving_status\x18\x02 \x01(\x0e\x32\".HealthCheckResponse.ServingStatus\":\n\rServingStatus\x12\x0b\n\x07UNKNOWN\x10\x00\x12\x0b\n\x07SERVING\x10\x01\x12\x0f\n\x0bNOT_SERVING\x10\x02\x32<\n\x06Health\x12\x32\n\x05\x43heck\x12\x13.HealthCheckRequest\x1a\x14.HealthCheckResponseB\x0eZ\x0chealth_checkb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_request__meta__pb2.DESCRIPTOR,])



_HEALTHCHECKRESPONSE_SERVINGSTATUS = _descriptor.EnumDescriptor(
  name='ServingStatus',
  full_name='HealthCheckResponse.ServingStatus',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='UNKNOWN', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='SERVING', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='NOT_SERVING', index=2, number=2,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=257,
  serialized_end=315,
)
_sym_db.RegisterEnumDescriptor(_HEALTHCHECKRESPONSE_SERVINGSTATUS)


_HEALTHCHECKREQUEST = _descriptor.Descriptor(
  name='HealthCheckRequest',
  full_name='HealthCheckRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='meta', full_name='HealthCheckRequest.meta', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='service', full_name='HealthCheckRequest.service', index=1,
      number=2, type=9, cpp_type=9, label=1,
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
  serialized_start=73,
  serialized_end=138,
)


_HEALTHCHECKRESPONSE = _descriptor.Descriptor(
  name='HealthCheckResponse',
  full_name='HealthCheckResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='HealthCheckResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='serving_status', full_name='HealthCheckResponse.serving_status', index=1,
      number=2, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _HEALTHCHECKRESPONSE_SERVINGSTATUS,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=141,
  serialized_end=315,
)

_HEALTHCHECKREQUEST.fields_by_name['meta'].message_type = proto_dot_utils_dot_request__meta__pb2._REQUESTMETA
_HEALTHCHECKRESPONSE.fields_by_name['status'].message_type = proto_dot_utils_dot_request__meta__pb2._RESPONSESTATUS
_HEALTHCHECKRESPONSE.fields_by_name['serving_status'].enum_type = _HEALTHCHECKRESPONSE_SERVINGSTATUS
_HEALTHCHECKRESPONSE_SERVINGSTATUS.containing_type = _HEALTHCHECKRESPONSE
DESCRIPTOR.message_types_by_name['HealthCheckRequest'] = _HEALTHCHECKREQUEST
DESCRIPTOR.message_types_by_name['HealthCheckResponse'] = _HEALTHCHECKRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

HealthCheckRequest = _reflection.GeneratedProtocolMessageType('HealthCheckRequest', (_message.Message,), {
  'DESCRIPTOR' : _HEALTHCHECKREQUEST,
  '__module__' : 'proto.health_check.health_check_pb2'
  # @@protoc_insertion_point(class_scope:HealthCheckRequest)
  })
_sym_db.RegisterMessage(HealthCheckRequest)

HealthCheckResponse = _reflection.GeneratedProtocolMessageType('HealthCheckResponse', (_message.Message,), {
  'DESCRIPTOR' : _HEALTHCHECKRESPONSE,
  '__module__' : 'proto.health_check.health_check_pb2'
  # @@protoc_insertion_point(class_scope:HealthCheckResponse)
  })
_sym_db.RegisterMessage(HealthCheckResponse)


DESCRIPTOR._options = None

_HEALTH = _descriptor.ServiceDescriptor(
  name='Health',
  full_name='Health',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=317,
  serialized_end=377,
  methods=[
  _descriptor.MethodDescriptor(
    name='Check',
    full_name='Health.Check',
    index=0,
    containing_service=None,
    input_type=_HEALTHCHECKREQUEST,
    output_type=_HEALTHCHECKRESPONSE,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_HEALTH)

DESCRIPTOR.services_by_name['Health'] = _HEALTH

# @@protoc_insertion_point(module_scope)
