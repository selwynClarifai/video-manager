# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/image.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from proto.utils import ndarray_pb2 as proto_dot_utils_dot_ndarray__pb2


DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/image.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x17proto/utils/image.proto\x1a\x19proto/utils/ndarray.proto\"\xce\x02\n\x05Image\x12\x0c\n\x04name\x18\x01 \x01(\t\x12\x17\n\rencoded_bytes\x18\x02 \x01(\x0cH\x00\x12\x1b\n\x07ndarray\x18\x03 \x01(\x0b\x32\x08.NDArrayH\x00\x12\x17\n\rdecoded_bytes\x18\x05 \x01(\x0cH\x00\x12\x0b\n\x03url\x18\x04 \x01(\t\x12\x17\n\x0fhosted_orig_url\x18\x06 \x01(\t\x12\x18\n\x10hosted_small_url\x18\x07 \x01(\t\x12\x18\n\x10hosted_large_url\x18\x08 \x01(\t\x12\x17\n\x0fhosted_tiny_url\x18\t \x01(\t\x12\x0e\n\x05width\x18\xe8\x07 \x01(\x05\x12\x0f\n\x06height\x18\xe9\x07 \x01(\x05\x12\x0f\n\x06\x63olors\x18\xea\x07 \x01(\x05\x12\x13\n\nmean_value\x18\xeb\x07 \x01(\x02\x12\x12\n\tmin_value\x18\xec\x07 \x01(\x02\x12\x12\n\tmax_value\x18\xed\x07 \x01(\x02\x42\x06\n\x04\x64\x61taB\x0e\n\x05utilsZ\x05utilsb\x06proto3'
  ,
  dependencies=[proto_dot_utils_dot_ndarray__pb2.DESCRIPTOR,])




_IMAGE = _descriptor.Descriptor(
  name='Image',
  full_name='Image',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='name', full_name='Image.name', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='encoded_bytes', full_name='Image.encoded_bytes', index=1,
      number=2, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='ndarray', full_name='Image.ndarray', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='decoded_bytes', full_name='Image.decoded_bytes', index=3,
      number=5, type=12, cpp_type=9, label=1,
      has_default_value=False, default_value=b"",
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='url', full_name='Image.url', index=4,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hosted_orig_url', full_name='Image.hosted_orig_url', index=5,
      number=6, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hosted_small_url', full_name='Image.hosted_small_url', index=6,
      number=7, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hosted_large_url', full_name='Image.hosted_large_url', index=7,
      number=8, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hosted_tiny_url', full_name='Image.hosted_tiny_url', index=8,
      number=9, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='width', full_name='Image.width', index=9,
      number=1000, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='height', full_name='Image.height', index=10,
      number=1001, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='colors', full_name='Image.colors', index=11,
      number=1002, type=5, cpp_type=1, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='mean_value', full_name='Image.mean_value', index=12,
      number=1003, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='min_value', full_name='Image.min_value', index=13,
      number=1004, type=2, cpp_type=6, label=1,
      has_default_value=False, default_value=float(0),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='max_value', full_name='Image.max_value', index=14,
      number=1005, type=2, cpp_type=6, label=1,
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
    _descriptor.OneofDescriptor(
      name='data', full_name='Image.data',
      index=0, containing_type=None, fields=[]),
  ],
  serialized_start=55,
  serialized_end=389,
)

_IMAGE.fields_by_name['ndarray'].message_type = proto_dot_utils_dot_ndarray__pb2._NDARRAY
_IMAGE.oneofs_by_name['data'].fields.append(
  _IMAGE.fields_by_name['encoded_bytes'])
_IMAGE.fields_by_name['encoded_bytes'].containing_oneof = _IMAGE.oneofs_by_name['data']
_IMAGE.oneofs_by_name['data'].fields.append(
  _IMAGE.fields_by_name['ndarray'])
_IMAGE.fields_by_name['ndarray'].containing_oneof = _IMAGE.oneofs_by_name['data']
_IMAGE.oneofs_by_name['data'].fields.append(
  _IMAGE.fields_by_name['decoded_bytes'])
_IMAGE.fields_by_name['decoded_bytes'].containing_oneof = _IMAGE.oneofs_by_name['data']
DESCRIPTOR.message_types_by_name['Image'] = _IMAGE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

Image = _reflection.GeneratedProtocolMessageType('Image', (_message.Message,), {
  'DESCRIPTOR' : _IMAGE,
  '__module__' : 'proto.utils.image_pb2'
  # @@protoc_insertion_point(class_scope:Image)
  })
_sym_db.RegisterMessage(Image)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
