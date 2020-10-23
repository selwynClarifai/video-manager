# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: proto/utils/workflow.proto

from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='proto/utils/workflow.proto',
  package='',
  syntax='proto3',
  serialized_options=b'\n\005utilsZ\005utils',
  serialized_pb=b'\n\x1aproto/utils/workflow.proto\"y\n\rWorkflowGraph\x12\x1b\n\x04node\x18\x01 \x03(\x0b\x32\r.WorkflowNode\x12#\n\x06recipe\x18\x02 \x03(\x0b\x32\x0f.WorkflowRecipeB\x02\x18\x01\x12&\n\x04hint\x18\x05 \x03(\x0b\x32\x18.WorkflowComputationHint\"4\n\x0cModelVersion\x12\x10\n\x08model_id\x18\x01 \x01(\t\x12\x12\n\nversion_id\x18\x02 \x01(\t\"\x97\x01\n\x0cWorkflowNode\x12\n\n\x02id\x18\x01 \x01(\t\x12$\n\rmodel_version\x18\x02 \x01(\x0b\x32\r.ModelVersion\x12\x1d\n\x05input\x18\x03 \x03(\x0b\x32\x0e.WorkflowInput\x12\x14\n\x0c\x64isplay_name\x18\x04 \x01(\t\x12\x10\n\x08group_id\x18\x05 \x01(\t\x12\x0e\n\x06hidden\x18\x06 \x01(\x08\"0\n\rWorkflowInput\x12\x0f\n\x07node_id\x18\x01 \x01(\t\x12\x0e\n\x06output\x18\x02 \x01(\t\"E\n\x17WorkflowComputationHint\x12\x0f\n\x07node_id\x18\x01 \x01(\t\x12\x19\n\x11\x61lready_predicted\x18\x02 \x01(\x08\"\x89\x01\n\x0eWorkflowRecipe\x12\n\n\x02id\x18\x01 \x01(\t\x12\n\n\x02op\x18\x02 \x01(\t\x12\x14\n\x0c\x64isplay_name\x18\x03 \x01(\t\x12\x10\n\x08node_ids\x18\x04 \x03(\t\x12&\n\x04hint\x18\x05 \x03(\x0b\x32\x18.WorkflowComputationHint\x12\x0f\n\x07\x64\x65\x66\x61ult\x18\x06 \x01(\x08\x42\x0e\n\x05utilsZ\x05utilsb\x06proto3'
)




_WORKFLOWGRAPH = _descriptor.Descriptor(
  name='WorkflowGraph',
  full_name='WorkflowGraph',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='node', full_name='WorkflowGraph.node', index=0,
      number=1, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='recipe', full_name='WorkflowGraph.recipe', index=1,
      number=2, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=b'\030\001', file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hint', full_name='WorkflowGraph.hint', index=2,
      number=5, type=11, cpp_type=10, label=3,
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
  serialized_start=30,
  serialized_end=151,
)


_MODELVERSION = _descriptor.Descriptor(
  name='ModelVersion',
  full_name='ModelVersion',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='model_id', full_name='ModelVersion.model_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='version_id', full_name='ModelVersion.version_id', index=1,
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
  serialized_start=153,
  serialized_end=205,
)


_WORKFLOWNODE = _descriptor.Descriptor(
  name='WorkflowNode',
  full_name='WorkflowNode',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='WorkflowNode.id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='model_version', full_name='WorkflowNode.model_version', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='input', full_name='WorkflowNode.input', index=2,
      number=3, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='display_name', full_name='WorkflowNode.display_name', index=3,
      number=4, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='group_id', full_name='WorkflowNode.group_id', index=4,
      number=5, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hidden', full_name='WorkflowNode.hidden', index=5,
      number=6, type=8, cpp_type=7, label=1,
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
  serialized_start=208,
  serialized_end=359,
)


_WORKFLOWINPUT = _descriptor.Descriptor(
  name='WorkflowInput',
  full_name='WorkflowInput',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='node_id', full_name='WorkflowInput.node_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='output', full_name='WorkflowInput.output', index=1,
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
  serialized_start=361,
  serialized_end=409,
)


_WORKFLOWCOMPUTATIONHINT = _descriptor.Descriptor(
  name='WorkflowComputationHint',
  full_name='WorkflowComputationHint',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='node_id', full_name='WorkflowComputationHint.node_id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='already_predicted', full_name='WorkflowComputationHint.already_predicted', index=1,
      number=2, type=8, cpp_type=7, label=1,
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
  serialized_start=411,
  serialized_end=480,
)


_WORKFLOWRECIPE = _descriptor.Descriptor(
  name='WorkflowRecipe',
  full_name='WorkflowRecipe',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='WorkflowRecipe.id', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='op', full_name='WorkflowRecipe.op', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='display_name', full_name='WorkflowRecipe.display_name', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='node_ids', full_name='WorkflowRecipe.node_ids', index=3,
      number=4, type=9, cpp_type=9, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='hint', full_name='WorkflowRecipe.hint', index=4,
      number=5, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
    _descriptor.FieldDescriptor(
      name='default', full_name='WorkflowRecipe.default', index=5,
      number=6, type=8, cpp_type=7, label=1,
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
  serialized_start=483,
  serialized_end=620,
)

_WORKFLOWGRAPH.fields_by_name['node'].message_type = _WORKFLOWNODE
_WORKFLOWGRAPH.fields_by_name['recipe'].message_type = _WORKFLOWRECIPE
_WORKFLOWGRAPH.fields_by_name['hint'].message_type = _WORKFLOWCOMPUTATIONHINT
_WORKFLOWNODE.fields_by_name['model_version'].message_type = _MODELVERSION
_WORKFLOWNODE.fields_by_name['input'].message_type = _WORKFLOWINPUT
_WORKFLOWRECIPE.fields_by_name['hint'].message_type = _WORKFLOWCOMPUTATIONHINT
DESCRIPTOR.message_types_by_name['WorkflowGraph'] = _WORKFLOWGRAPH
DESCRIPTOR.message_types_by_name['ModelVersion'] = _MODELVERSION
DESCRIPTOR.message_types_by_name['WorkflowNode'] = _WORKFLOWNODE
DESCRIPTOR.message_types_by_name['WorkflowInput'] = _WORKFLOWINPUT
DESCRIPTOR.message_types_by_name['WorkflowComputationHint'] = _WORKFLOWCOMPUTATIONHINT
DESCRIPTOR.message_types_by_name['WorkflowRecipe'] = _WORKFLOWRECIPE
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

WorkflowGraph = _reflection.GeneratedProtocolMessageType('WorkflowGraph', (_message.Message,), {
  'DESCRIPTOR' : _WORKFLOWGRAPH,
  '__module__' : 'proto.utils.workflow_pb2'
  # @@protoc_insertion_point(class_scope:WorkflowGraph)
  })
_sym_db.RegisterMessage(WorkflowGraph)

ModelVersion = _reflection.GeneratedProtocolMessageType('ModelVersion', (_message.Message,), {
  'DESCRIPTOR' : _MODELVERSION,
  '__module__' : 'proto.utils.workflow_pb2'
  # @@protoc_insertion_point(class_scope:ModelVersion)
  })
_sym_db.RegisterMessage(ModelVersion)

WorkflowNode = _reflection.GeneratedProtocolMessageType('WorkflowNode', (_message.Message,), {
  'DESCRIPTOR' : _WORKFLOWNODE,
  '__module__' : 'proto.utils.workflow_pb2'
  # @@protoc_insertion_point(class_scope:WorkflowNode)
  })
_sym_db.RegisterMessage(WorkflowNode)

WorkflowInput = _reflection.GeneratedProtocolMessageType('WorkflowInput', (_message.Message,), {
  'DESCRIPTOR' : _WORKFLOWINPUT,
  '__module__' : 'proto.utils.workflow_pb2'
  # @@protoc_insertion_point(class_scope:WorkflowInput)
  })
_sym_db.RegisterMessage(WorkflowInput)

WorkflowComputationHint = _reflection.GeneratedProtocolMessageType('WorkflowComputationHint', (_message.Message,), {
  'DESCRIPTOR' : _WORKFLOWCOMPUTATIONHINT,
  '__module__' : 'proto.utils.workflow_pb2'
  # @@protoc_insertion_point(class_scope:WorkflowComputationHint)
  })
_sym_db.RegisterMessage(WorkflowComputationHint)

WorkflowRecipe = _reflection.GeneratedProtocolMessageType('WorkflowRecipe', (_message.Message,), {
  'DESCRIPTOR' : _WORKFLOWRECIPE,
  '__module__' : 'proto.utils.workflow_pb2'
  # @@protoc_insertion_point(class_scope:WorkflowRecipe)
  })
_sym_db.RegisterMessage(WorkflowRecipe)


DESCRIPTOR._options = None
_WORKFLOWGRAPH.fields_by_name['recipe']._options = None
# @@protoc_insertion_point(module_scope)