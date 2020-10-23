# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/pasting_data_provider.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import data_provider_pb2 as proto_dot_utils_dot_data__provider__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/pasting_data_provider.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\'proto/utils/pasting_data_provider.proto\x1a\x1fproto/utils/data_provider.proto\"\xdf\x02\n\x19PastingDataProviderParams\x12\x1a\n\x12\x62\x61\x63kground_dataset\x18\x01 \x01(\t\x12+\n\x0e\x62\x61\x63kground_dpp\x18\x02 \x01(\x0b\x32\x13.DataProviderParams\x12&\n\tlevel_dpp\x18\x03 \x03(\x0b\x32\x13.PastingLevelParams\x12\x16\n\x0eoutput_dataset\x18\x04 \x01(\t\x12)\n\x0cmbitem_stage\x18\x05 \x03(\x0b\x32\x13.MiniBatchItemStage\x12,\n\x11processing_params\x18\x06 \x01(\x0b\x32\x11.ProcessingParams\x12 \n\x18\x62\x61\x63kground_dataset_split\x18\x07 \x01(\t\x12\x1a\n\x12random_layer_order\x18\x08 \x01(\x08\x12\"\n\x1a\x63onstrain_boxes_to_visible\x18\t \x01(\x08\"\xb8\x02\n\x12PastingLevelParams\x12\'\n\ncommon_dpp\x18\x01 \x01(\x0b\x32\x13.DataProviderParams\x12\x14\n\x0c\x64\x61taset_name\x18\x02 \x01(\t\x12\r\n\x05min_x\x18\x03 \x01(\x02\x12\r\n\x05max_x\x18\x04 \x01(\x02\x12\r\n\x05min_y\x18\x05 \x01(\x02\x12\r\n\x05max_y\x18\x06 \x01(\x02\x12\x12\n\npaste_prob\x18\x07 \x01(\x02\x12\x12\n\nwrite_bbox\x18\x08 \x01(\x08\x12\x13\n\x0bmin_visible\x18\t \x01(\x02\x12\x13\n\x0bmax_visible\x18\n \x01(\x02\x12\x13\n\x0brepetitions\x18\x0b \x01(\x05\x12\x15\n\rdataset_split\x18\x0c \x01(\t\x12\x16\n\x0epasting_method\x18\r \x01(\t\x12\x11\n\tskip_prob\x18\x0e \x01(\x02\x42\x0e\n\x05utilsZ\x05utilsb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_data__provider__pb2.DESCRIPTOR,])




_PASTINGDATAPROVIDERPARAMS = _descriptor.Descriptor(
  name='PastingDataProviderParams',
  full_name='PastingDataProviderParams',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='background_dataset', full_name='PastingDataProviderParams.background_dataset', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='background_dpp', full_name='PastingDataProviderParams.background_dpp', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='level_dpp', full_name='PastingDataProviderParams.level_dpp', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='output_dataset', full_name='PastingDataProviderParams.output_dataset', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mbitem_stage', full_name='PastingDataProviderParams.mbitem_stage', index=4,
      number=5, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='processing_params', full_name='PastingDataProviderParams.processing_params', index=5,
      number=6, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='background_dataset_split', full_name='PastingDataProviderParams.background_dataset_split', index=6,
      number=7, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='random_layer_order', full_name='PastingDataProviderParams.random_layer_order', index=7,
      number=8, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='constrain_boxes_to_visible', full_name='PastingDataProviderParams.constrain_boxes_to_visible', index=8,
      number=9, type=8, cpp_type=7, label=1,
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
  serialized_start=77,
  serialized_end=428,
)


_PASTINGLEVELPARAMS = _descriptor.Descriptor(
  name='PastingLevelParams',
  full_name='PastingLevelParams',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='common_dpp', full_name='PastingLevelParams.common_dpp', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='dataset_name', full_name='PastingLevelParams.dataset_name', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='min_x', full_name='PastingLevelParams.min_x', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='max_x', full_name='PastingLevelParams.max_x', index=3,
      number=4, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='min_y', full_name='PastingLevelParams.min_y', index=4,
      number=5, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='max_y', full_name='PastingLevelParams.max_y', index=5,
      number=6, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='paste_prob', full_name='PastingLevelParams.paste_prob', index=6,
      number=7, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='write_bbox', full_name='PastingLevelParams.write_bbox', index=7,
      number=8, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='min_visible', full_name='PastingLevelParams.min_visible', index=8,
      number=9, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='max_visible', full_name='PastingLevelParams.max_visible', index=9,
      number=10, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='repetitions', full_name='PastingLevelParams.repetitions', index=10,
      number=11, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='dataset_split', full_name='PastingLevelParams.dataset_split', index=11,
      number=12, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='pasting_method', full_name='PastingLevelParams.pasting_method', index=12,
      number=13, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='skip_prob', full_name='PastingLevelParams.skip_prob', index=13,
      number=14, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
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
  serialized_start=431,
  serialized_end=743,
)

_PASTINGDATAPROVIDERPARAMS.fields_by_name['background_dpp'].message_type = proto_dot_utils_dot_data__provider__pb2._DATAPROVIDERPARAMS
_PASTINGDATAPROVIDERPARAMS.fields_by_name['level_dpp'].message_type = _PASTINGLEVELPARAMS
_PASTINGDATAPROVIDERPARAMS.fields_by_name['mbitem_stage'].message_type = proto_dot_utils_dot_data__provider__pb2._MINIBATCHITEMSTAGE
_PASTINGDATAPROVIDERPARAMS.fields_by_name['processing_params'].message_type = proto_dot_utils_dot_data__provider__pb2._PROCESSINGPARAMS
_PASTINGLEVELPARAMS.fields_by_name['common_dpp'].message_type = proto_dot_utils_dot_data__provider__pb2._DATAPROVIDERPARAMS
DESCRIPTOR.message_types_by_name['PastingDataProviderParams'] = _PASTINGDATAPROVIDERPARAMS
DESCRIPTOR.message_types_by_name['PastingLevelParams'] = _PASTINGLEVELPARAMS
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

PastingDataProviderParams = _reflection.GeneratedProtocolMessageType('PastingDataProviderParams', (_message.Message,), {
  'DESCRIPTOR' : _PASTINGDATAPROVIDERPARAMS,
  '__module__' : 'proto.utils.pasting_data_provider_pb2'
  # @@protoc_insertion_point(class_scope:PastingDataProviderParams)
  })
_sym_db.RegisterMessage(PastingDataProviderParams)

PastingLevelParams = _reflection.GeneratedProtocolMessageType('PastingLevelParams', (_message.Message,), {
  'DESCRIPTOR' : _PASTINGLEVELPARAMS,
  '__module__' : 'proto.utils.pasting_data_provider_pb2'
  # @@protoc_insertion_point(class_scope:PastingLevelParams)
  })
_sym_db.RegisterMessage(PastingLevelParams)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
