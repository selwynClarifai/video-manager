#!/usr/bin/env python
"""
This is used to fix the json and proto3 go struct tags so that you can serialize protobufs to jsonb
and back even when they are nested inside other go structs or protobufs. It changes the golang
protobuf tag json= field from camelCase to snake_case.

We also check that the protobuf:name=* name is snake_case for all our public .proto files. This
is the convention we use in our v2 APIs so we check it here at proto build time!

This can take in a list of filenames such as using the {} + command in find:
find "$GOSOURCEDIR/proto" -name "*.pb.go" -print -exec $CLARIFAI_ROOT/proto/go_proto_clean.py {} +
"""
from __future__ import absolute_import, division, print_function
from future import standard_library

import re
import sys
from builtins import range

standard_library.install_aliases()

GOPROTOPATH = "go/src/clarifai/proto/clarifai"


def to_snake_case(name):
  s1 = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
  return re.sub('([a-z0-9])([A-Z])', r'\1_\2', s1).lower()


def processFile(filename):
  if not filename.endswith('.pb.go'):
    raise Exception("Need to specify a .pb.go filename")
  # If these are public protos, they will be in this directory.
  public = filename.find(GOPROTOPATH) >= 0
  print('X' * 100)
  print("X Working on .pb.go file: %s" % filename)
  print('X' * 100)
  f = open(filename).read()

  # Get all the tags that match int he compiled proto file.
  lines = re.findall(r'`protobuf:.*`', f)

  def cleanLine(line, public):
    """
    Examples:
    `protobuf:"bytes,4,opt,name=image_bytes,json=imageBytes,proto3" json:"image_bytes,omitempty"` ->
    `protobuf:"bytes,4,opt,name=image_bytes,json=image_bytes,proto3" json:"image_bytes,omitempty"`

    For oneof fields we append the json tag so that encoding/json in go works as well as the logic
    below to replace the json= part of the protobuf: field also gets changed to snakecase like:
    '`protobuf:"varint,6,opt,name=bool_oneof,json=boolOneof,proto3,oneof"`' ->
    '`protobuf:"varint,6,opt,name=bool_oneof,json=bool_oneof,proto3,oneof" json:"bool_oneof,omitempty"`'
    """
    is_oneof = False
    if line.count('oneof') > 0:
      is_oneof = True
    # We have to match the two cases, either a oneof field at the end or a space after quote since
    # there is a json field afterwards.
    proto_field = re.findall(r'protobuf:"(.*oneof"|.*" )', line)[0]
    # Could look like: 'bytes,4,opt,name=image_bytes,json=imageBytes,proto3" '
    # Or: 'varint,6,opt,name=bool_oneof,json=boolOneof,proto3,oneof"'
    # So cut off the " at onwards.
    proto_field = proto_field.split('"')[0]
    json_proto_fields = [
        field.replace('json=', '') for field in proto_field.split(',') if field.startswith('json=')
    ]
    # If one of the public protos, we check that all fields are snake case.
    proto_name_fields = [
        field.replace('name=', '') for field in proto_field.split(',') if field.startswith('name=')
    ]
    assert len(proto_name_fields) > 0, 'proto_name_fields was not longer than 0: %s. line: %s' % (
        proto_name_fields, line)
    if public:
      if len(proto_name_fields) > 0:
        for name in proto_name_fields:
          snake_name = to_snake_case(name)
          if snake_name != name:
            raise Exception(
                "The name %s on line %s of %s is not snake case. Please make sure all the proto field names are snake_case."
                % (name, line, filename))

    if len(json_proto_fields) > 0:
      # Fix the issue with oneof field not having the following json field.
      if is_oneof:
        proto_name = proto_name_fields[0]
        assert proto_name == to_snake_case(json_proto_fields[0])
        # Make sure the json:"..." wasn't already added
        if ' json:"%s,omitempty"`' % proto_name not in line:
          # For some reason the oneof fields don't have the json:"..."  part after the `protobuf:"..."`
          # part of the line. So we append it here so that the bottom is can process.
          # Ex:
          # original: TimesTotal  map[string]float64 `protobuf:"bytes,10,rep,name=times_total,json=times_total" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"fixed64,2,opt,name=value,proto3"`
          # new :     TimesTotal  map[string]float64 `protobuf:"bytes,10,rep,name=times_total,json=times_total" json:"times_total,omitempty" protobuf_key:"bytes,1,opt,name=key,proto3" protobuf_val:"fixed64,2,opt,name=value,proto3"`
          line = line[:-1] + ' json:"%s,omitempty"`' % proto_name
      # This is the proto name (usually in snake_case).
      # This json: fields is what encoding/json uses with go. It's always the right snake case.
      try:
        snakeName = re.findall(r'json:"(.*?),', line)[0]
      except Exception:
        print("Skipping proto field '%s' as it is a map type." % json_proto_fields[0])
        return line
      if json_proto_fields[0] != snakeName:
        # the current proto go tag (which is not snake case)
        protoTagName = 'json=%s' % json_proto_fields[0]
        # the new proto go tag to put in (which will now be snake case)
        protoTagNewName = 'json=%s' % snakeName
        print("Replacing '%s' with '%s' in line: \n%s" % (protoTagName, protoTagNewName, line))
        line = line.replace(protoTagName, protoTagNewName)
        print("New line is: \n%s" % line)

    return line

  for i, line in enumerate(lines):
    f = f.replace(line, cleanLine(line, public))
  open(filename, 'w').write(f)


if __name__ == '__main__':
  for i in range(len(sys.argv)):
    if i == 0:
      continue
    processFile(sys.argv[i])
