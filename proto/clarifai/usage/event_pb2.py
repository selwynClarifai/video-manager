# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/clarifai/usage/event.proto

from google.protobuf.internal import enum_type_wrapper
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/clarifai/usage/event.proto',
  package='clarifai.usage',
  syntax='proto3',
  serialized_options=b'\n\022com.clarifai.usageP\001Z\005usage\242\002\004CAIP',
  serialized_pb=b'\n proto/clarifai/usage/event.proto\x12\x0e\x63larifai.usage\"\x99\x02\n\nEventParam\x12\x36\n\x07predict\x18\x01 \x01(\x0b\x32#.clarifai.usage.RegularPredictEventH\x00\x12<\n\x0e\x63ustom_predict\x18\x02 \x01(\x0b\x32\".clarifai.usage.CustomPredictEventH\x00\x12-\n\x06search\x18\x03 \x01(\x0b\x32\x1b.clarifai.usage.SearchEventH\x00\x12\x30\n\x05train\x18\x04 \x01(\x0b\x32\x1f.clarifai.usage.TrainModelEventH\x00\x12+\n\x05other\x18\x05 \x01(\x0b\x32\x1a.clarifai.usage.OtherEventH\x00\x42\x07\n\x05\x65vent\"_\n\x05Model\x12\x10\n\x08model_id\x18\x01 \x01(\t\x12\x12\n\nmodel_type\x18\x02 \x01(\t\x12\x16\n\x0emodel_owner_id\x18\x03 \x01(\t\x12\x18\n\x10model_version_id\x18\x04 \x01(\t\"U\n\x13RegularPredictEvent\x12$\n\x05model\x18\x01 \x01(\x0b\x32\x15.clarifai.usage.Model\x12\x18\n\x10input_media_type\x18\x02 \x01(\t\"T\n\x12\x43ustomPredictEvent\x12$\n\x05model\x18\x01 \x01(\x0b\x32\x15.clarifai.usage.Model\x12\x18\n\x10input_media_type\x18\x02 \x01(\t\"\"\n\x0bSearchEvent\x12\x13\n\x0bsearch_type\x18\x01 \x01(\t\"7\n\x0fTrainModelEvent\x12$\n\x05model\x18\x01 \x01(\x0b\x32\x15.clarifai.usage.Model\"\x0c\n\nOtherEvent*h\n\tEventType\x12\x10\n\x0cTYPE_NOT_SET\x10\x00\x12\x13\n\x0fREGULAR_PREDICT\x10\x01\x12\x12\n\x0e\x43USTOM_PREDICT\x10\x02\x12\n\n\x06SEARCH\x10\x03\x12\t\n\x05TRAIN\x10\x04\x12\t\n\x05OTHER\x10\x05\x42$\n\x12\x63om.clarifai.usageP\x01Z\x05usage\xa2\x02\x04\x43\x41IPb\x06proto3'
)

_EVENTTYPE = _descriptor.EnumDescriptor(
  name='EventType',
  full_name='clarifai.usage.EventType',
  filename=None,
  file=DESCRIPTOR,
  values=[
    _descriptor.EnumValueDescriptor(
      name='TYPE_NOT_SET', index=0, number=0,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='REGULAR_PREDICT', index=1, number=1,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='CUSTOM_PREDICT', index=2, number=2,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='SEARCH', index=3, number=3,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='TRAIN', index=4, number=4,
      serialized_options=None,
      type=None),
    _descriptor.EnumValueDescriptor(
      name='OTHER', index=5, number=5,
      serialized_options=None,
      type=None),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=713,
  serialized_end=817,
)
_sym_db.RegisterEnumDescriptor(_EVENTTYPE)

EventType = enum_type_wrapper.EnumTypeWrapper(_EVENTTYPE)
TYPE_NOT_SET = 0
REGULAR_PREDICT = 1
CUSTOM_PREDICT = 2
SEARCH = 3
TRAIN = 4
OTHER = 5



_EVENTPARAM = _descriptor.Descriptor(
  name='EventParam',
  full_name='clarifai.usage.EventParam',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='predict', full_name='clarifai.usage.EventParam.predict', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='custom_predict', full_name='clarifai.usage.EventParam.custom_predict', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='search', full_name='clarifai.usage.EventParam.search', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='train', full_name='clarifai.usage.EventParam.train', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='other', full_name='clarifai.usage.EventParam.other', index=4,
      number=5, type=11, cpp_type=10, label=1,
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
    _descriptor.OneofDescriptor(
      name='event', full_name='clarifai.usage.EventParam.event',
      index=0, containing_type=None, fields=[]),
  ],
  serialized_start=53,
  serialized_end=334,
)


_MODEL = _descriptor.Descriptor(
  name='Model',
  full_name='clarifai.usage.Model',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='model_id', full_name='clarifai.usage.Model.model_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_type', full_name='clarifai.usage.Model.model_type', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_owner_id', full_name='clarifai.usage.Model.model_owner_id', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_version_id', full_name='clarifai.usage.Model.model_version_id', index=3,
      number=4, type=9, cpp_type=9, label=1,
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
  serialized_start=336,
  serialized_end=431,
)


_REGULARPREDICTEVENT = _descriptor.Descriptor(
  name='RegularPredictEvent',
  full_name='clarifai.usage.RegularPredictEvent',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='model', full_name='clarifai.usage.RegularPredictEvent.model', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='input_media_type', full_name='clarifai.usage.RegularPredictEvent.input_media_type', index=1,
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
  serialized_start=433,
  serialized_end=518,
)


_CUSTOMPREDICTEVENT = _descriptor.Descriptor(
  name='CustomPredictEvent',
  full_name='clarifai.usage.CustomPredictEvent',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='model', full_name='clarifai.usage.CustomPredictEvent.model', index=0,
      number=1, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='input_media_type', full_name='clarifai.usage.CustomPredictEvent.input_media_type', index=1,
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
  serialized_start=520,
  serialized_end=604,
)


_SEARCHEVENT = _descriptor.Descriptor(
  name='SearchEvent',
  full_name='clarifai.usage.SearchEvent',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='search_type', full_name='clarifai.usage.SearchEvent.search_type', index=0,
      number=1, type=9, cpp_type=9, label=1,
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
  serialized_start=606,
  serialized_end=640,
)


_TRAINMODELEVENT = _descriptor.Descriptor(
  name='TrainModelEvent',
  full_name='clarifai.usage.TrainModelEvent',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='model', full_name='clarifai.usage.TrainModelEvent.model', index=0,
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
  serialized_start=642,
  serialized_end=697,
)


_OTHEREVENT = _descriptor.Descriptor(
  name='OtherEvent',
  full_name='clarifai.usage.OtherEvent',
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
  serialized_start=699,
  serialized_end=711,
)

_EVENTPARAM.fields_by_name['predict'].message_type = _REGULARPREDICTEVENT
_EVENTPARAM.fields_by_name['custom_predict'].message_type = _CUSTOMPREDICTEVENT
_EVENTPARAM.fields_by_name['search'].message_type = _SEARCHEVENT
_EVENTPARAM.fields_by_name['train'].message_type = _TRAINMODELEVENT
_EVENTPARAM.fields_by_name['other'].message_type = _OTHEREVENT
_EVENTPARAM.oneofs_by_name['event'].fields.append(
  _EVENTPARAM.fields_by_name['predict'])
_EVENTPARAM.fields_by_name['predict'].containing_oneof = _EVENTPARAM.oneofs_by_name['event']
_EVENTPARAM.oneofs_by_name['event'].fields.append(
  _EVENTPARAM.fields_by_name['custom_predict'])
_EVENTPARAM.fields_by_name['custom_predict'].containing_oneof = _EVENTPARAM.oneofs_by_name['event']
_EVENTPARAM.oneofs_by_name['event'].fields.append(
  _EVENTPARAM.fields_by_name['search'])
_EVENTPARAM.fields_by_name['search'].containing_oneof = _EVENTPARAM.oneofs_by_name['event']
_EVENTPARAM.oneofs_by_name['event'].fields.append(
  _EVENTPARAM.fields_by_name['train'])
_EVENTPARAM.fields_by_name['train'].containing_oneof = _EVENTPARAM.oneofs_by_name['event']
_EVENTPARAM.oneofs_by_name['event'].fields.append(
  _EVENTPARAM.fields_by_name['other'])
_EVENTPARAM.fields_by_name['other'].containing_oneof = _EVENTPARAM.oneofs_by_name['event']
_REGULARPREDICTEVENT.fields_by_name['model'].message_type = _MODEL
_CUSTOMPREDICTEVENT.fields_by_name['model'].message_type = _MODEL
_TRAINMODELEVENT.fields_by_name['model'].message_type = _MODEL
DESCRIPTOR.message_types_by_name['EventParam'] = _EVENTPARAM
DESCRIPTOR.message_types_by_name['Model'] = _MODEL
DESCRIPTOR.message_types_by_name['RegularPredictEvent'] = _REGULARPREDICTEVENT
DESCRIPTOR.message_types_by_name['CustomPredictEvent'] = _CUSTOMPREDICTEVENT
DESCRIPTOR.message_types_by_name['SearchEvent'] = _SEARCHEVENT
DESCRIPTOR.message_types_by_name['TrainModelEvent'] = _TRAINMODELEVENT
DESCRIPTOR.message_types_by_name['OtherEvent'] = _OTHEREVENT
DESCRIPTOR.enum_types_by_name['EventType'] = _EVENTTYPE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

EventParam = _reflection.GeneratedProtocolMessageType('EventParam', (_message.Message,), {
  'DESCRIPTOR' : _EVENTPARAM,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.EventParam)
  })
_sym_db.RegisterMessage(EventParam)

Model = _reflection.GeneratedProtocolMessageType('Model', (_message.Message,), {
  'DESCRIPTOR' : _MODEL,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.Model)
  })
_sym_db.RegisterMessage(Model)

RegularPredictEvent = _reflection.GeneratedProtocolMessageType('RegularPredictEvent', (_message.Message,), {
  'DESCRIPTOR' : _REGULARPREDICTEVENT,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.RegularPredictEvent)
  })
_sym_db.RegisterMessage(RegularPredictEvent)

CustomPredictEvent = _reflection.GeneratedProtocolMessageType('CustomPredictEvent', (_message.Message,), {
  'DESCRIPTOR' : _CUSTOMPREDICTEVENT,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.CustomPredictEvent)
  })
_sym_db.RegisterMessage(CustomPredictEvent)

SearchEvent = _reflection.GeneratedProtocolMessageType('SearchEvent', (_message.Message,), {
  'DESCRIPTOR' : _SEARCHEVENT,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.SearchEvent)
  })
_sym_db.RegisterMessage(SearchEvent)

TrainModelEvent = _reflection.GeneratedProtocolMessageType('TrainModelEvent', (_message.Message,), {
  'DESCRIPTOR' : _TRAINMODELEVENT,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.TrainModelEvent)
  })
_sym_db.RegisterMessage(TrainModelEvent)

OtherEvent = _reflection.GeneratedProtocolMessageType('OtherEvent', (_message.Message,), {
  'DESCRIPTOR' : _OTHEREVENT,
  '__module__' : 'proto.clarifai.usage.event_pb2'
  # @@protoc_insertion_point(class_scope:clarifai.usage.OtherEvent)
  })
_sym_db.RegisterMessage(OtherEvent)


DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)