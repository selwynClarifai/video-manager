# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/model_converter/model_converter.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.clarifai.model_fetching import resources_pb2 as proto_dot_clarifai_dot_model__fetching_dot_resources__pb2
from proto.utils import request_meta_pb2 as proto_dot_utils_dot_request__meta__pb2
from proto.spire import spire_pb2 as proto_dot_spire_dot_spire__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/model_converter/model_converter.proto',
  package='',
  syntax='proto3',
  serialized_options=b'Z\017model_converter',
  serialized_pb=b'\n+proto/model_converter/model_converter.proto\x1a-proto/clarifai/model_fetching/resources.proto\x1a\x1eproto/utils/request_meta.proto\x1a\x17proto/spire/spire.proto\"w\n!ModelConverterConvertModelRequest\x12\x1a\n\x04meta\x18\x01 \x01(\x0b\x32\x0c.RequestMeta\x12\x36\n\nmodel_info\x18\x02 \x01(\x0b\x32\".clarifai.model_fetching.ModelInfo\"c\n\"ModelConverterConvertModelResponse\x12\x1f\n\x06status\x18\x01 \x01(\x0b\x32\x0f.ResponseStatus\x12\x1c\n\x06\x63onfig\x18\x02 \x01(\x0b\x32\x0c.SpireConfig2\x80\x01\n\x15ModelConverterService\x12g\n\x1aModelConverterConvertModel\x12\".ModelConverterConvertModelRequest\x1a#.ModelConverterConvertModelResponse\"\x00\x42\x11Z\x0fmodel_converterb\x06proto3'
  ,
  dependencies=[proto_dot_clarifai_dot_model__fetching_dot_resources__pb2.DESCRIPTOR,proto_dot_utils_dot_request__meta__pb2.DESCRIPTOR,proto_dot_spire_dot_spire__pb2.DESCRIPTOR,])




_MODELCONVERTERCONVERTMODELREQUEST = _descriptor.Descriptor(
  name='ModelConverterConvertModelRequest',
  full_name='ModelConverterConvertModelRequest',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='meta', full_name='ModelConverterConvertModelRequest.meta', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_info', full_name='ModelConverterConvertModelRequest.model_info', index=1,
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
  serialized_start=151,
  serialized_end=270,
)


_MODELCONVERTERCONVERTMODELRESPONSE = _descriptor.Descriptor(
  name='ModelConverterConvertModelResponse',
  full_name='ModelConverterConvertModelResponse',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='status', full_name='ModelConverterConvertModelResponse.status', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='config', full_name='ModelConverterConvertModelResponse.config', index=1,
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
  serialized_start=272,
  serialized_end=371,
)

_MODELCONVERTERCONVERTMODELREQUEST.fields_by_name['meta'].message_type = proto_dot_utils_dot_request__meta__pb2._REQUESTMETA
_MODELCONVERTERCONVERTMODELREQUEST.fields_by_name['model_info'].message_type = proto_dot_clarifai_dot_model__fetching_dot_resources__pb2._MODELINFO
_MODELCONVERTERCONVERTMODELRESPONSE.fields_by_name['status'].message_type = proto_dot_utils_dot_request__meta__pb2._RESPONSESTATUS
_MODELCONVERTERCONVERTMODELRESPONSE.fields_by_name['config'].message_type = proto_dot_spire_dot_spire__pb2._SPIRECONFIG
DESCRIPTOR.message_types_by_name['ModelConverterConvertModelRequest'] = _MODELCONVERTERCONVERTMODELREQUEST
DESCRIPTOR.message_types_by_name['ModelConverterConvertModelResponse'] = _MODELCONVERTERCONVERTMODELRESPONSE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ModelConverterConvertModelRequest = _reflection.GeneratedProtocolMessageType('ModelConverterConvertModelRequest', (_message.Message,), {
  'DESCRIPTOR' : _MODELCONVERTERCONVERTMODELREQUEST,
  '__module__' : 'proto.model_converter.model_converter_pb2'
  # @@protoc_insertion_point(class_scope:ModelConverterConvertModelRequest)
  })
_sym_db.RegisterMessage(ModelConverterConvertModelRequest)

ModelConverterConvertModelResponse = _reflection.GeneratedProtocolMessageType('ModelConverterConvertModelResponse', (_message.Message,), {
  'DESCRIPTOR' : _MODELCONVERTERCONVERTMODELRESPONSE,
  '__module__' : 'proto.model_converter.model_converter_pb2'
  # @@protoc_insertion_point(class_scope:ModelConverterConvertModelResponse)
  })
_sym_db.RegisterMessage(ModelConverterConvertModelResponse)


DESCRIPTOR._options = None

_MODELCONVERTERSERVICE = _descriptor.ServiceDescriptor(
  name='ModelConverterService',
  full_name='ModelConverterService',
  file=DESCRIPTOR,
  index=0,
  serialized_options=None,
  serialized_start=374,
  serialized_end=502,
  methods=[
  _descriptor.MethodDescriptor(
    name='ModelConverterConvertModel',
    full_name='ModelConverterService.ModelConverterConvertModel',
    index=0,
    containing_service=None,
    input_type=_MODELCONVERTERCONVERTMODELREQUEST,
    output_type=_MODELCONVERTERCONVERTMODELRESPONSE,
    serialized_options=None,
  ),
])
_sym_db.RegisterServiceDescriptor(_MODELCONVERTERSERVICE)

DESCRIPTOR.services_by_name['ModelConverterService'] = _MODELCONVERTERSERVICE

# @@protoc_insertion_point(module_scope)
