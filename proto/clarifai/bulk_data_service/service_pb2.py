# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/clarifai/bulk_data_service/service.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.clarifai.bulk_data_service import resources_pb2 as proto_dot_clarifai_dot_bulk__data__service_dot_resources__pb2
from proto.clarifai.api import resources_pb2 as proto_dot_clarifai_dot_api_dot_resources__pb2
from proto.clarifai.api.status import status_pb2 as proto_dot_clarifai_dot_api_dot_status_dot_status__pb2
from proto.clarifai.auth.scope import scope_pb2 as proto_dot_clarifai_dot_auth_dot_scope_dot_scope__pb2
from proto.clarifai.auth.util import extension_pb2 as proto_dot_clarifai_dot_auth_dot_util_dot_extension__pb2
from google.api import annotations_pb2 as google_dot_api_dot_annotations__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/clarifai/bulk_data_service/service.proto',
  package='clarifai.bulk_data_service',
  syntax='proto3',
  serialized_options=_b('\n\036com.clarifai.bulk_data_serviceP\001Z\021bulk_data_service\242\002\004CAIP'),
  serialized_pb=_b('\n.proto/clarifai/bulk_data_service/service.proto\x12\x1a\x63larifai.bulk_data_service\x1a\x30proto/clarifai/bulk_data_service/resources.proto\x1a\"proto/clarifai/api/resources.proto\x1a&proto/clarifai/api/status/status.proto\x1a%proto/clarifai/auth/scope/scope.proto\x1a(proto/clarifai/auth/util/extension.proto\x1a\x1cgoogle/api/annotations.proto\"[\n\x12GetDataDumpRequest\x12/\n\x0buser_app_id\x18\x01 \x01(\x0b\x32\x1a.clarifai.api.UserAppIDSet\x12\x14\n\x0c\x64\x61ta_dump_id\x18\x02 \x01(\t\"~\n\x16SingleDataDumpResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\x12\x37\n\tdata_dump\x18\x02 \x01(\x0b\x32$.clarifai.bulk_data_service.DataDump\"~\n\x15MultiDataDumpResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\x12\x38\n\ndata_dumps\x18\x02 \x03(\x0b\x32$.clarifai.bulk_data_service.DataDump\"\x13\n\x11GetHealthzRequest\"O\n\x12GetHealthzResponse\x12+\n\x06status\x18\x01 \x01(\x0b\x32\x1b.clarifai.api.status.Status\x12\x0c\n\x04time\x18\x02 \x01(\t2\x9f\x05\n\x12\x42ulkDataServiceAPI\x12\x8b\x01\n\nGetHealthz\x12-.clarifai.bulk_data_service.GetHealthzRequest\x1a..clarifai.bulk_data_service.GetHealthzResponse\"\x1e\x82\xd3\xe4\x93\x02\x14\x12\x12/bulk-data/healthz\x98\x9c\'\x01\x12\xf0\x01\n\rPostDataDumps\x12\x30.clarifai.bulk_data_service.PostDataDumpsRequest\x1a\x31.clarifai.bulk_data_service.MultiDataDumpResponse\"z\x82\xd3\xe4\x93\x02l\"K/bulk-data/users/{user_app_id.user_id}/apps/{user_app_id.app_id}/data_dumps:\x01*Z\x1a\"\x15/bulk-data/data_dumps:\x01*\x98\x9c\'\x02\x90\x9c\'\x01\x12\x87\x02\n\x0bGetDataDump\x12..clarifai.bulk_data_service.GetDataDumpRequest\x1a\x32.clarifai.bulk_data_service.SingleDataDumpResponse\"\x93\x01\x82\xd3\xe4\x93\x02\x84\x01\x12Z/bulk-data/users/{user_app_id.user_id}/apps/{user_app_id.app_id}/data_dumps/{data_dump_id}Z&\x12$/bulk-data/data_dumps/{data_dump_id}\x98\x9c\'\x02\x90\x9c\'\x01\x42<\n\x1e\x63om.clarifai.bulk_data_serviceP\x01Z\x11\x62ulk_data_service\xa2\x02\x04\x43\x41IPb\x06proto3')
  ,
  dependencies=[proto_dot_clarifai_dot_bulk__data__service_dot_resources__pb2.DESCRIPTOR,proto_dot_clarifai_dot_api_dot_resources__pb2.DESCRIPTOR,proto_dot_clarifai_dot_api_dot_status_dot_status__pb2.DESCRIPTOR,proto_dot_clarifai_dot_auth_dot_scope_dot_scope__pb2.DESCRIPTOR,proto_dot_clarifai_dot_auth_dot_util_dot_extension__pb2.DESCRIPTOR,google_dot_api_dot_annotations__pb2.DESCRIPTOR,])




_GETDATADUMPREQUEST = _descriptor.Descriptor(
  name='GetDataDumpRequest',
  full_name='clarifai.bulk_data_service.GetDataDumpRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='user_app_id', full_name='clarifai.bulk_data_service.GetDataDumpRequest.user_app_id', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='data_dump_id', full_name='clarifai.bulk_data_service.GetDataDumpRequest.data_dump_id', index=1,
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
  serialized_start=315,
  serialized_end=406,
)


_SINGLEDATADUMPRESPONSE = _descriptor.Descriptor(
  name='SingleDataDumpResponse',
  full_name='clarifai.bulk_data_service.SingleDataDumpResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.bulk_data_service.SingleDataDumpResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='data_dump', full_name='clarifai.bulk_data_service.SingleDataDumpResponse.data_dump', index=1,
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
  serialized_start=408,
  serialized_end=534,
)


_MULTIDATADUMPRESPONSE = _descriptor.Descriptor(
  name='MultiDataDumpResponse',
  full_name='clarifai.bulk_data_service.MultiDataDumpResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.bulk_data_service.MultiDataDumpResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='data_dumps', full_name='clarifai.bulk_data_service.MultiDataDumpResponse.data_dumps', index=1,
      number=2, type=11, cpp_type=10, label=3,
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
  serialized_start=536,
  serialized_end=662,
)


_GETHEALTHZREQUEST = _descriptor.Descriptor(
  name='GetHealthzRequest',
  full_name='clarifai.bulk_data_service.GetHealthzRequest',
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
  serialized_start=664,
  serialized_end=683,
)


_GETHEALTHZRESPONSE = _descriptor.Descriptor(
  name='GetHealthzResponse',
  full_name='clarifai.bulk_data_service.GetHealthzResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='clarifai.bulk_data_service.GetHealthzResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='time', full_name='clarifai.bulk_data_service.GetHealthzResponse.time', index=1,
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
  serialized_start=685,
  serialized_end=764,
)

_GETDATADUMPREQUEST.fields_by_name['user_app_id'].message_type = proto_dot_clarifai_dot_api_dot_resources__pb2._USERAPPIDSET
_SINGLEDATADUMPRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
_SINGLEDATADUMPRESPONSE.fields_by_name['data_dump'].message_type = proto_dot_clarifai_dot_bulk__data__service_dot_resources__pb2._DATADUMP
_MULTIDATADUMPRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
_MULTIDATADUMPRESPONSE.fields_by_name['data_dumps'].message_type = proto_dot_clarifai_dot_bulk__data__service_dot_resources__pb2._DATADUMP
_GETHEALTHZRESPONSE.fields_by_name['status'].message_type = proto_dot_clarifai_dot_api_dot_status_dot_status__pb2._STATUS
DESCRIPTOR.message_types_by_name['GetDataDumpRequest'] = _GETDATADUMPREQUEST
DESCRIPTOR.message_types_by_name['SingleDataDumpResponse'] = _SINGLEDATADUMPRESPONSE
DESCRIPTOR.message_types_by_name['MultiDataDumpResponse'] = _MULTIDATADUMPRESPONSE
DESCRIPTOR.message_types_by_name['GetHealthzRequest'] = _GETHEALTHZREQUEST
DESCRIPTOR.message_types_by_name['GetHealthzResponse'] = _GETHEALTHZRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

GetDataDumpRequest = _reflection.GeneratedProtocolMessageType('GetDataDumpRequest', (_message.Message,), {
  'DESCRIPTOR' : _GETDATADUMPREQUEST,
  '__module__' : 'proto.clarifai.bulk_data_service.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.bulk_data_service.GetDataDumpRequest)
  })
_sym_db.RegisterMessage(GetDataDumpRequest)

SingleDataDumpResponse = _reflection.GeneratedProtocolMessageType('SingleDataDumpResponse', (_message.Message,), {
  'DESCRIPTOR' : _SINGLEDATADUMPRESPONSE,
  '__module__' : 'proto.clarifai.bulk_data_service.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.bulk_data_service.SingleDataDumpResponse)
  })
_sym_db.RegisterMessage(SingleDataDumpResponse)

MultiDataDumpResponse = _reflection.GeneratedProtocolMessageType('MultiDataDumpResponse', (_message.Message,), {
  'DESCRIPTOR' : _MULTIDATADUMPRESPONSE,
  '__module__' : 'proto.clarifai.bulk_data_service.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.bulk_data_service.MultiDataDumpResponse)
  })
_sym_db.RegisterMessage(MultiDataDumpResponse)

GetHealthzRequest = _reflection.GeneratedProtocolMessageType('GetHealthzRequest', (_message.Message,), {
  'DESCRIPTOR' : _GETHEALTHZREQUEST,
  '__module__' : 'proto.clarifai.bulk_data_service.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.bulk_data_service.GetHealthzRequest)
  })
_sym_db.RegisterMessage(GetHealthzRequest)

GetHealthzResponse = _reflection.GeneratedProtocolMessageType('GetHealthzResponse', (_message.Message,), {
  'DESCRIPTOR' : _GETHEALTHZRESPONSE,
  '__module__' : 'proto.clarifai.bulk_data_service.service_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.bulk_data_service.GetHealthzResponse)
  })
_sym_db.RegisterMessage(GetHealthzResponse)


DESCRIPTOR._options = None

_BULKDATASERVICEAPI = _descriptor.ServiceDescriptor(
  name='BulkDataServiceAPI',
  full_name='clarifai.bulk_data_service.BulkDataServiceAPI',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=767,
  serialized_end=1438,
  methods=[
  _descriptor.MethodDescriptor(
    name='GetHealthz',
    full_name='clarifai.bulk_data_service.BulkDataServiceAPI.GetHealthz',
    index=0,
    containing_service=None,
    input_type=_GETHEALTHZREQUEST,
    output_type=_GETHEALTHZRESPONSE,
    serialized_options=_b('\202\323\344\223\002\024\022\022/bulk-data/healthz\230\234\'\001'),
  ),
  _descriptor.MethodDescriptor(
    name='PostDataDumps',
    full_name='clarifai.bulk_data_service.BulkDataServiceAPI.PostDataDumps',
    index=1,
    containing_service=None,
    input_type=proto_dot_clarifai_dot_bulk__data__service_dot_resources__pb2._POSTDATADUMPSREQUEST,
    output_type=_MULTIDATADUMPRESPONSE,
    serialized_options=_b('\202\323\344\223\002l\"K/bulk-data/users/{user_app_id.user_id}/apps/{user_app_id.app_id}/data_dumps:\001*Z\032\"\025/bulk-data/data_dumps:\001*\230\234\'\002\220\234\'\001'),
  ),
  _descriptor.MethodDescriptor(
    name='GetDataDump',
    full_name='clarifai.bulk_data_service.BulkDataServiceAPI.GetDataDump',
    index=2,
    containing_service=None,
    input_type=_GETDATADUMPREQUEST,
    output_type=_SINGLEDATADUMPRESPONSE,
    serialized_options=_b('\202\323\344\223\002\204\001\022Z/bulk-data/users/{user_app_id.user_id}/apps/{user_app_id.app_id}/data_dumps/{data_dump_id}Z&\022$/bulk-data/data_dumps/{data_dump_id}\230\234\'\002\220\234\'\001'),
  ),
])
_sym_db.RegisterServiceDescriptor(_BULKDATASERVICEAPI)

DESCRIPTOR.services_by_name['BulkDataServiceAPI'] = _BULKDATASERVICEAPI

# @@protoc_insertion_point(module_scope)
