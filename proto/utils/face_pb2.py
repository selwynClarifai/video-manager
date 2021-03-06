# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/face.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import tag_pb2 as proto_dot_utils_dot_tag__pb2
from proto.utils import boundingbox_pb2 as proto_dot_utils_dot_boundingbox__pb2
from proto.utils import embedding_pb2 as proto_dot_utils_dot_embedding__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/face.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x16proto/utils/face.proto\x1a\x15proto/utils/tag.proto\x1a\x1dproto/utils/boundingbox.proto\x1a\x1bproto/utils/embedding.proto\"`\n\x04\x46\x61\x63\x65\x12\x16\n\x08identity\x18\x01 \x03(\x0b\x32\x04.Tag\x12\x11\n\x03\x61ge\x18\x02 \x03(\x0b\x32\x04.Tag\x12\x14\n\x06gender\x18\x03 \x03(\x0b\x32\x04.Tag\x12\x17\n\tethnicity\x18\x04 \x03(\x0b\x32\x04.Tag\"^\n\rFaceDetection\x12\x19\n\x03\x62ox\x18\x01 \x01(\x0b\x32\x0c.BoundingBox\x12\x13\n\x04\x66\x61\x63\x65\x18\x02 \x01(\x0b\x32\x05.Face\x12\x1d\n\tembedding\x18\x03 \x01(\x0b\x32\n.EmbeddingB\x0e\n\x05utilsZ\x05utilsb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_tag__pb2.DESCRIPTOR,proto_dot_utils_dot_boundingbox__pb2.DESCRIPTOR,proto_dot_utils_dot_embedding__pb2.DESCRIPTOR,])




_FACE = _descriptor.Descriptor(
  name='Face',
  full_name='Face',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='identity', full_name='Face.identity', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='age', full_name='Face.age', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='gender', full_name='Face.gender', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ethnicity', full_name='Face.ethnicity', index=3,
      number=4, type=11, cpp_type=10, label=3,
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
  serialized_start=109,
  serialized_end=205,
)


_FACEDETECTION = _descriptor.Descriptor(
  name='FaceDetection',
  full_name='FaceDetection',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='box', full_name='FaceDetection.box', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='face', full_name='FaceDetection.face', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='embedding', full_name='FaceDetection.embedding', index=2,
      number=3, type=11, cpp_type=10, label=1,
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
  serialized_start=207,
  serialized_end=301,
)

_FACE.fields_by_name['identity'].message_type = proto_dot_utils_dot_tag__pb2._TAG
_FACE.fields_by_name['age'].message_type = proto_dot_utils_dot_tag__pb2._TAG
_FACE.fields_by_name['gender'].message_type = proto_dot_utils_dot_tag__pb2._TAG
_FACE.fields_by_name['ethnicity'].message_type = proto_dot_utils_dot_tag__pb2._TAG
_FACEDETECTION.fields_by_name['box'].message_type = proto_dot_utils_dot_boundingbox__pb2._BOUNDINGBOX
_FACEDETECTION.fields_by_name['face'].message_type = _FACE
_FACEDETECTION.fields_by_name['embedding'].message_type = proto_dot_utils_dot_embedding__pb2._EMBEDDING
DESCRIPTOR.message_types_by_name['Face'] = _FACE
DESCRIPTOR.message_types_by_name['FaceDetection'] = _FACEDETECTION
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Face = _reflection.GeneratedProtocolMessageType('Face', (_message.Message,), {
  'DESCRIPTOR' : _FACE,
  '__module__' : 'proto.utils.face_pb2'
  # @@protoc_insertion_point(class_scope:Face)
  })
_sym_db.RegisterMessage(Face)

FaceDetection = _reflection.GeneratedProtocolMessageType('FaceDetection', (_message.Message,), {
  'DESCRIPTOR' : _FACEDETECTION,
  '__module__' : 'proto.utils.face_pb2'
  # @@protoc_insertion_point(class_scope:FaceDetection)
  })
_sym_db.RegisterMessage(FaceDetection)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
