# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/clarifai/sdk_billing/service.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.clarifai.sdk_billing import resources_pb2 as proto_dot_clarifai_dot_sdk__billing_dot_resources__pb2
from proto.clarifai.api.status import status_pb2 as proto_dot_clarifai_dot_api_dot_status_dot_status__pb2
from proto.clarifai.auth.scope import scope_pb2 as proto_dot_clarifai_dot_auth_dot_scope_dot_scope__pb2
from proto.clarifai.auth.util import extension_pb2 as proto_dot_clarifai_dot_auth_dot_util_dot_extension__pb2
from proto.clarifai.commands import commands_pb2 as proto_dot_clarifai_dot_commands_dot_commands__pb2
from google.api import annotations_pb2 as google_dot_api_dot_annotations__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/clarifai/sdk_billing/service.proto',
  package='clarifai.sdk_billing',
  syntax='proto3',
  serialized_options=_b('\n\030com.clarifai.sdk_billingP\001Z\013sdk_billing\242\002\004CAIP'),
  serialized_pb=_b('\n(proto/clarifai/sdk_billing/service.proto\x12\x14\x63larifai.sdk_billing\x1a*proto/clarifai/sdk_billing/resources.proto\x1a&proto/clarifai/api/status/status.proto\x1a%proto/clarifai/auth/scope/scope.proto\x1a(proto/clarifai/auth/util/extension.proto\x1a&proto/clarifai/commands/commands.proto\x1a\x1cgoogle/api/annotations.proto\"\x13\n\x11GetHealthzRequest\"O\n\x12GetHealthzResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\x12\x0c\n\x04time\x18\x02 \x01(\t\"p\n\x12SDKBillingResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\x12-\n\x08\x63ommands\x18\x02 \x01(\x0b\x32\x1b.clarifai.commands.Commands2\x90\x02\n\x11SDKBillingService\x12\x80\x01\n\nGetHealthz\x12\'.clarifai.sdk_billing.GetHealthzRequest\x1a(.clarifai.sdk_billing.GetHealthzResponse\"\x1f\x82\xd3\xe4\x93\x02\x15\x12\x13/sdkbilling/healthz\x98\x9c\'\x01\x12x\n\x0ePostSDKBilling\x12 .clarifai.sdk_billing.SDKBilling\x1a(.clarifai.sdk_billing.SDKBillingResponse\"\x1a\x82\xd3\xe4\x93\x02\x10\"\x0b/sdkbilling:\x01*\x98\x9c\'\x01\x42\x30\n\x18\x63om.clarifai.sdk_billingP\x01Z\x0bsdk_billing\xa2\x02\x04\x43\x41IPb\x06proto3')
  ,
  dependencies=[proto_dot_clarifai_dot_sdk__billing_dot_resources__pb2.DESCRIPTOR,proto_dot_clarifai_dot_api_dot_status_dot_status__pb2.DESCRIPTOR,proto_dot_clarifai_dot_auth_dot_scope_dot_scope__pb2.DESCRIPTOR,proto_dot_clarifai_dot_auth_dot_util_dot_extension__pb2.DESCRIPTOR,proto_dot_clarifai_dot_commands_dot_commands__pb2.DESCRIPTOR,google_dot_api_dot_annotations__pb2.DESCRIPTOR,])




_GETHEALTHZREQUEST = _descriptor.Descriptor(
  name='GetHealthzRequest',
  full_name='clarifai.sdk_billing.GetHealthzRequest',
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
  serialized_start=301,
  serialized_end=320,
)


_GETHEALTHZRESPONSE = _descriptor.Descriptor(
  name='GetHealthzResponse',
  full_name='clarifai.sdk_billing.GetHealthzResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.sdk_billing.GetHealthzResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time', full_name='clarifai.sdk_billing.GetHealthzResponse.time', index=1,
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
  serialized_start=322,
  serialized_end=401,
)


_SDKBILLINGRESPONSE = _descriptor.Descriptor(
  name='SDKBillingResponse',
  full_name='clarifai.sdk_billing.SDKBillingResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.sdk_billing.SDKBillingResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='commands', full_name='clarifai.sdk_billing.SDKBillingResponse.commands', index=1,
      number=2, type=11, cpp_type=10, label=1,
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
  serialized_start=403,
  serialized_end=515,
)

_GETHEALTHZRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
_SDKBILLINGRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
_SDKBILLINGRESPONSE.fields_by_name['commands'].message_type = proto_dot_clarifai_dot_commands_dot_commands__pb2._COMMANDS
DESCRIPTOR.message_types_by_name['GetHealthzRequest'] = _GETHEALTHZREQUEST
DESCRIPTOR.message_types_by_name['GetHealthzResponse'] = _GETHEALTHZRESPONSE
DESCRIPTOR.message_types_by_name['SDKBillingResponse'] = _SDKBILLINGRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

GetHealthzRequest = _reflection.GeneratedProtocolMessageType('GetHealthzRequest', (_message.Message,), {
  'DESCRIPTOR' : _GETHEALTHZREQUEST,
  '__module__' : 'proto.clarifai.sdk_billing.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.sdk_billing.GetHealthzRequest)
  })
_sym_db.RegisterMessage(GetHealthzRequest)

GetHealthzResponse = _reflection.GeneratedProtocolMessageType('GetHealthzResponse', (_message.Message,), {
  'DESCRIPTOR' : _GETHEALTHZRESPONSE,
  '__module__' : 'proto.clarifai.sdk_billing.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.sdk_billing.GetHealthzResponse)
  })
_sym_db.RegisterMessage(GetHealthzResponse)

SDKBillingResponse = _reflection.GeneratedProtocolMessageType('SDKBillingResponse', (_message.Message,), {
  'DESCRIPTOR' : _SDKBILLINGRESPONSE,
  '__module__' : 'proto.clarifai.sdk_billing.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.sdk_billing.SDKBillingResponse)
  })
_sym_db.RegisterMessage(SDKBillingResponse)


DESCRIPTOR._options = None

_SDKBILLINGSERVICE = _descriptor.ServiceDescriptor(
  name='SDKBillingService',
  full_name='clarifai.sdk_billing.SDKBillingService',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=518,
  serialized_end=790,
  methods=[
  _descriptor.MethodDescriptor(
    name='GetHealthz',
    full_name='clarifai.sdk_billing.SDKBillingService.GetHealthz',
    index=0,
    containing_service=None,
    input_type=_GETHEALTHZREQUEST,
    output_type=_GETHEALTHZRESPONSE,
    serialized_options=_b('\202\323\344\223\002\025\022\023/sdkbilling/healthz\230\234\'\001'),
  ),
  _descriptor.MethodDescriptor(
    name='PostSDKBilling',
    full_name='clarifai.sdk_billing.SDKBillingService.PostSDKBilling',
    index=1,
    containing_service=None,
    input_type=proto_dot_clarifai_dot_sdk__billing_dot_resources__pb2._SDKBILLING,
    output_type=_SDKBILLINGRESPONSE,
    serialized_options=_b('\202\323\344\223\002\020\"\013/sdkbilling:\001*\230\234\'\001'),
  ),
])
_sym_db.RegisterServiceDescriptor(_SDKBILLINGSERVICE)

DESCRIPTOR.services_by_name['SDKBillingService'] = _SDKBILLINGSERVICE

# @@protoc_insertion_point(module_scope)