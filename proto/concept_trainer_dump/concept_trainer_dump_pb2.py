# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/concept_trainer_dump/concept_trainer_dump.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from google.protobuf import timestamp_pb2 as google_dot_protobuf_dot_timestamp__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/concept_trainer_dump/concept_trainer_dump.proto',
  package='',
  syntax='proto3',
  serialized_options=b'Z\024concept_trainer_dump',
  serialized_pb=b'\n5proto/concept_trainer_dump/concept_trainer_dump.proto\x1a\x1fgoogle/protobuf/timestamp.proto\"\x92\x04\n\x12\x43onceptTrainerDump\x12\x0f\n\x07version\x18\x01 \x01(\x05\x12/\n\x0bupdate_time\x18\x02 \x01(\x0b\x32\x1a.google.protobuf.Timestamp\x12\x39\n\x0b\x63lassifiers\x18\x03 \x03(\x0b\x32$.ConceptTrainerDump.ClassifiersEntry\x12\x18\n\x10\x65mbeddings_model\x18\x04 \x01(\t\x12$\n\rtraining_type\x18\x05 \x01(\x0e\x32\r.TrainingType\x12\x1d\n\x15\x66\x65\x61ture_normalization\x18\x06 \x01(\x08\x12\x16\n\x0etf_graph_proto\x18\x07 \x01(\x0c\x12\x1c\n\x14tf_frozen_meta_graph\x18\x08 \x01(\x0c\x12\r\n\x05\x61iids\x18\t \x03(\t\x12\x32\n\x14training_environment\x18\n \x01(\x0e\x32\x14.TrainingEnvironment\x12\x13\n\x0b\x63oncept_ids\x18\x0b \x03(\t\x12\x46\n\x1fmissing_positive_example_policy\x18\x0c \x01(\x0e\x32\x1d.MissingPositiveExamplePolicy\x1aJ\n\x10\x43lassifiersEntry\x12\x0b\n\x03key\x18\x01 \x01(\t\x12%\n\x05value\x18\x02 \x01(\x0b\x32\x16.ConceptClassifierDump:\x02\x38\x01\"{\n\x15\x43onceptClassifierDump\x12\x17\n\x0f\x63lassifier_type\x18\x01 \x01(\t\x12\x12\n\x06weight\x18\x02 \x03(\x02\x42\x02\x10\x01\x12\x0c\n\x04\x62ias\x18\x03 \x01(\x02\x12\x10\n\x04norm\x18\x04 \x01(\x02\x42\x02\x18\x01\x12\x15\n\rlogistic_temp\x18\x05 \x01(\x02*(\n\x0cTrainingType\x12\n\n\x06M_VS_N\x10\x00\x12\x0c\n\x08ONE_VS_N\x10\x01*+\n\x13TrainingEnvironment\x12\x08\n\x04OPEN\x10\x00\x12\n\n\x06\x43LOSED\x10\x01*L\n\x1cMissingPositiveExamplePolicy\x12\x1e\n\x1aSAMPLE_NEGATIVE_EMBEDDINGS\x10\x00\x12\x0c\n\x08\x44ISALLOW\x10\x01\x42\x16Z\x14\x63oncept_trainer_dumpb\x06proto3'
  ,
  dependencies=[google_dot_protobuf_dot_timestamp__pb2.DESCRIPTOR,])

_TRAININGTYPE = _descriptor.EnumDescriptor(
  name='TrainingType',
  full_name='TrainingType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='M_VS_N', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='ONE_VS_N', index=1, number=1,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=748,
  serialized_end=788,
)
_sym_db.RegisterEnumDescriptor(_TRAININGTYPE)

TrainingType = enum_type_wrapper.EnumTypeWrapper(_TRAININGTYPE)
_TRAININGENVIRONMENT = _descriptor.EnumDescriptor(
  name='TrainingEnvironment',
  full_name='TrainingEnvironment',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='OPEN', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='CLOSED', index=1, number=1,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=790,
  serialized_end=833,
)
_sym_db.RegisterEnumDescriptor(_TRAININGENVIRONMENT)

TrainingEnvironment = enum_type_wrapper.EnumTypeWrapper(_TRAININGENVIRONMENT)
_MISSINGPOSITIVEEXAMPLEPOLICY = _descriptor.EnumDescriptor(
  name='MissingPositiveExamplePolicy',
  full_name='MissingPositiveExamplePolicy',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='SAMPLE_NEGATIVE_EMBEDDINGS', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='DISALLOW', index=1, number=1,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=835,
  serialized_end=911,
)
_sym_db.RegisterEnumDescriptor(_MISSINGPOSITIVEEXAMPLEPOLICY)

MissingPositiveExamplePolicy = enum_type_wrapper.EnumTypeWrapper(_MISSINGPOSITIVEEXAMPLEPOLICY)
M_VS_N = 0
ONE_VS_N = 1
OPEN = 0
CLOSED = 1
SAMPLE_NEGATIVE_EMBEDDINGS = 0
DISALLOW = 1



_CONCEPTTRAINERDUMP_CLASSIFIERSENTRY = _descriptor.Descriptor(
  name='ClassifiersEntry',
  full_name='ConceptTrainerDump.ClassifiersEntry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='key', full_name='ConceptTrainerDump.ClassifiersEntry.key', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='value', full_name='ConceptTrainerDump.ClassifiersEntry.value', index=1,
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
  serialized_options=b'8\001',
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=547,
  serialized_end=621,
)

_CONCEPTTRAINERDUMP = _descriptor.Descriptor(
  name='ConceptTrainerDump',
  full_name='ConceptTrainerDump',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='version', full_name='ConceptTrainerDump.version', index=0,
      number=1, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='update_time', full_name='ConceptTrainerDump.update_time', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='classifiers', full_name='ConceptTrainerDump.classifiers', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='embeddings_model', full_name='ConceptTrainerDump.embeddings_model', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='training_type', full_name='ConceptTrainerDump.training_type', index=4,
      number=5, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='feature_normalization', full_name='ConceptTrainerDump.feature_normalization', index=5,
      number=6, type=8, cpp_type=7, label=1,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='tf_graph_proto', full_name='ConceptTrainerDump.tf_graph_proto', index=6,
      number=7, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='tf_frozen_meta_graph', full_name='ConceptTrainerDump.tf_frozen_meta_graph', index=7,
      number=8, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='aiids', full_name='ConceptTrainerDump.aiids', index=8,
      number=9, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='training_environment', full_name='ConceptTrainerDump.training_environment', index=9,
      number=10, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='concept_ids', full_name='ConceptTrainerDump.concept_ids', index=10,
      number=11, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='missing_positive_example_policy', full_name='ConceptTrainerDump.missing_positive_example_policy', index=11,
      number=12, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[_CONCEPTTRAINERDUMP_CLASSIFIERSENTRY, ],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=91,
  serialized_end=621,
)


_CONCEPTCLASSIFIERDUMP = _descriptor.Descriptor(
  name='ConceptClassifierDump',
  full_name='ConceptClassifierDump',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='classifier_type', full_name='ConceptClassifierDump.classifier_type', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='weight', full_name='ConceptClassifierDump.weight', index=1,
      number=2, type=2, cpp_type=6, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\020\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='bias', full_name='ConceptClassifierDump.bias', index=2,
      number=3, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='norm', full_name='ConceptClassifierDump.norm', index=3,
      number=4, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\030\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='logistic_temp', full_name='ConceptClassifierDump.logistic_temp', index=4,
      number=5, type=2, cpp_type=6, label=1,
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
  serialized_start=623,
  serialized_end=746,
)

_CONCEPTTRAINERDUMP_CLASSIFIERSENTRY.fields_by_name['value'].message_type = _CONCEPTCLASSIFIERDUMP
_CONCEPTTRAINERDUMP_CLASSIFIERSENTRY.containing_type = _CONCEPTTRAINERDUMP
_CONCEPTTRAINERDUMP.fields_by_name['update_time'].message_type = google_dot_protobuf_dot_timestamp__pb2._TIMESTAMP
_CONCEPTTRAINERDUMP.fields_by_name['classifiers'].message_type = _CONCEPTTRAINERDUMP_CLASSIFIERSENTRY
_CONCEPTTRAINERDUMP.fields_by_name['training_type'].enum_type = _TRAININGTYPE
_CONCEPTTRAINERDUMP.fields_by_name['training_environment'].enum_type = _TRAININGENVIRONMENT
_CONCEPTTRAINERDUMP.fields_by_name['missing_positive_example_policy'].enum_type = _MISSINGPOSITIVEEXAMPLEPOLICY
DESCRIPTOR.message_types_by_name['ConceptTrainerDump'] = _CONCEPTTRAINERDUMP
DESCRIPTOR.message_types_by_name['ConceptClassifierDump'] = _CONCEPTCLASSIFIERDUMP
DESCRIPTOR.enum_types_by_name['TrainingType'] = _TRAININGTYPE
DESCRIPTOR.enum_types_by_name['TrainingEnvironment'] = _TRAININGENVIRONMENT
DESCRIPTOR.enum_types_by_name['MissingPositiveExamplePolicy'] = _MISSINGPOSITIVEEXAMPLEPOLICY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

ConceptTrainerDump = _reflection.GeneratedProtocolMessageType('ConceptTrainerDump', (_message.Message,), {

  'ClassifiersEntry' : _reflection.GeneratedProtocolMessageType('ClassifiersEntry', (_message.Message,), {
    'DESCRIPTOR' : _CONCEPTTRAINERDUMP_CLASSIFIERSENTRY,
    '__module__' : 'proto.concept_trainer_dump.concept_trainer_dump_pb2'
    # @@protoc_insertion_point(class_scope:ConceptTrainerDump.ClassifiersEntry)
    })
  ,
  'DESCRIPTOR' : _CONCEPTTRAINERDUMP,
  '__module__' : 'proto.concept_trainer_dump.concept_trainer_dump_pb2'
  # @@protoc_insertion_point(class_scope:ConceptTrainerDump)
  })
_sym_db.RegisterMessage(ConceptTrainerDump)
_sym_db.RegisterMessage(ConceptTrainerDump.ClassifiersEntry)

ConceptClassifierDump = _reflection.GeneratedProtocolMessageType('ConceptClassifierDump', (_message.Message,), {
  'DESCRIPTOR' : _CONCEPTCLASSIFIERDUMP,
  '__module__' : 'proto.concept_trainer_dump.concept_trainer_dump_pb2'
  # @@protoc_insertion_point(class_scope:ConceptClassifierDump)
  })
_sym_db.RegisterMessage(ConceptClassifierDump)


DESCRIPTOR._options = None
_CONCEPTTRAINERDUMP_CLASSIFIERSENTRY._options = None
_CONCEPTCLASSIFIERDUMP.fields_by_name['weight']._options = None
_CONCEPTCLASSIFIERDUMP.fields_by_name['norm']._options = None
# @@protoc_insertion_point(module_scope)
