# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/clarifai/analytics/service.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.clarifai.analytics import resources_pb2 as proto_dot_clarifai_dot_analytics_dot_resources__pb2
from proto.clarifai.api.status import status_pb2 as proto_dot_clarifai_dot_api_dot_status_dot_status__pb2
from proto.clarifai.auth.scope import scope_pb2 as proto_dot_clarifai_dot_auth_dot_scope_dot_scope__pb2
from proto.clarifai.auth.util import extension_pb2 as proto_dot_clarifai_dot_auth_dot_util_dot_extension__pb2
from google.api import annotations_pb2 as google_dot_api_dot_annotations__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/clarifai/analytics/service.proto',
  package='clarifai.analytics',
  syntax='proto3',
  serialized_options=_b('\n\026com.clarifai.analyticsP\001Z\tanalytics\242\002\004CAIP'),
  serialized_pb=_b('\n&proto/clarifai/analytics/service.proto\x12\x12\x63larifai.analytics\x1a(proto/clarifai/analytics/resources.proto\x1a&proto/clarifai/api/status/status.proto\x1a%proto/clarifai/auth/scope/scope.proto\x1a(proto/clarifai/auth/util/extension.proto\x1a\x1cgoogle/api/annotations.proto\"D\n\x15PostAnalyticsResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\"\x13\n\x11GetHealthzRequest\"O\n\x12GetHealthzResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\x12\x0c\n\x04time\x18\x02 \x01(\t2\x89\x02\n\x10\x41nalyticsService\x12{\n\nGetHealthz\x12%.clarifai.analytics.GetHealthzRequest\x1a&.clarifai.analytics.GetHealthzResponse\"\x1e\x82\xd3\xe4\x93\x02\x14\x12\x12/analytics/healthz\x98\x9c\'\x01\x12x\n\rPostAnalytics\x12\x1d.clarifai.analytics.Analytics\x1a).clarifai.analytics.PostAnalyticsResponse\"\x1d\x82\xd3\xe4\x93\x02\x0f\"\n/analytics:\x01*\x98\x9c\'\x02\x90\x9c\'\x01\x42,\n\x16\x63om.clarifai.analyticsP\x01Z\tanalytics\xa2\x02\x04\x43\x41IPb\x06proto3')
  ,
  dependencies=[proto_dot_clarifai_dot_analytics_dot_resources__pb2.DESCRIPTOR,proto_dot_clarifai_dot_api_dot_status_dot_status__pb2.DESCRIPTOR,proto_dot_clarifai_dot_auth_dot_scope_dot_scope__pb2.DESCRIPTOR,proto_dot_clarifai_dot_auth_dot_util_dot_extension__pb2.DESCRIPTOR,google_dot_api_dot_annotations__pb2.DESCRIPTOR,])




_POSTANALYTICSRESPONSE = _descriptor.Descriptor(
  name='PostAnalyticsResponse',
  full_name='clarifai.analytics.PostAnalyticsResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.analytics.PostAnalyticsResponse.status', index=0,
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
  serialized_start=255,
  serialized_end=323,
)


_GETHEALTHZREQUEST = _descriptor.Descriptor(
  name='GetHealthzRequest',
  full_name='clarifai.analytics.GetHealthzRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
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
  serialized_start=325,
  serialized_end=344,
)


_GETHEALTHZRESPONSE = _descriptor.Descriptor(
  name='GetHealthzResponse',
  full_name='clarifai.analytics.GetHealthzResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.analytics.GetHealthzResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time', full_name='clarifai.analytics.GetHealthzResponse.time', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=_b("").decode('utf-8'),
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
  serialized_start=346,
  serialized_end=425,
)

_POSTANALYTICSRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
_GETHEALTHZRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
DESCRIPTOR.message_types_by_name['PostAnalyticsResponse'] = _POSTANALYTICSRESPONSE
DESCRIPTOR.message_types_by_name['GetHealthzRequest'] = _GETHEALTHZREQUEST
DESCRIPTOR.message_types_by_name['GetHealthzResponse'] = _GETHEALTHZRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

PostAnalyticsResponse = _reflection.GeneratedProtocolMessageType('PostAnalyticsResponse', (_message.Message,), {
  'DESCRIPTOR' : _POSTANALYTICSRESPONSE,
  '__module__' : 'proto.clarifai.analytics.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.analytics.PostAnalyticsResponse)
  })
_sym_db.RegisterMessage(PostAnalyticsResponse)

GetHealthzRequest = _reflection.GeneratedProtocolMessageType('GetHealthzRequest', (_message.Message,), {
  'DESCRIPTOR' : _GETHEALTHZREQUEST,
  '__module__' : 'proto.clarifai.analytics.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.analytics.GetHealthzRequest)
  })
_sym_db.RegisterMessage(GetHealthzRequest)

GetHealthzResponse = _reflection.GeneratedProtocolMessageType('GetHealthzResponse', (_message.Message,), {
  'DESCRIPTOR' : _GETHEALTHZRESPONSE,
  '__module__' : 'proto.clarifai.analytics.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.analytics.GetHealthzResponse)
  })
_sym_db.RegisterMessage(GetHealthzResponse)


DESCRIPTOR._options = None

_ANALYTICSSERVICE = _descriptor.ServiceDescriptor(
  name='AnalyticsService',
  full_name='clarifai.analytics.AnalyticsService',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=428,
  serialized_end=693,
  methods=[
  _descriptor.MethodDescriptor(
    name='GetHealthz',
    full_name='clarifai.analytics.AnalyticsService.GetHealthz',
    index=0,
    containing_service=None,
    input_type=_GETHEALTHZREQUEST,
    output_type=_GETHEALTHZRESPONSE,
    serialized_options=_b('\202\323\344\223\002\024\022\022/analytics/healthz\230\234\'\001'),
  ),
  _descriptor.MethodDescriptor(
    name='PostAnalytics',
    full_name='clarifai.analytics.AnalyticsService.PostAnalytics',
    index=1,
    containing_service=None,
    input_type=proto_dot_clarifai_dot_analytics_dot_resources__pb2._ANALYTICS,
    output_type=_POSTANALYTICSRESPONSE,
    serialized_options=_b('\202\323\344\223\002\017\"\n/analytics:\001*\230\234\'\002\220\234\'\001'),
  ),
])
_sym_db.RegisterServiceDescriptor(_ANALYTICSSERVICE)

DESCRIPTOR.services_by_name['AnalyticsService'] = _ANALYTICSSERVICE

# @@protoc_insertion_point(module_scope)