""" Helper to import all the important protos and some nice convenience methods.

Great Python generated code docs:
https://developers.google.com/protocol-buffers/docs/reference/python-generated#embedded_message

"""
from __future__ import absolute_import, division, print_function, unicode_literals
#pylint: disable=no-name-in-module
#pylint: disable=import-error
from future import standard_library
from past.builtins import basestring

import collections
import faulthandler
import signal
import sys
import time
import traceback as tb
from builtins import object, range, str

import numpy as np
from google.protobuf import duration_pb2, json_format, timestamp_pb2
from google.protobuf.json_format import Parse, ParseDict
from PIL import Image as PILImage

import proto.clarifai.api.status.status_code_pb2 as status_code
from proto.spire import spire_pb2
from proto.utils import saved_output_pb2
from proto.utils.boundingbox_pb2 import BoundingBox
from proto.utils.checkpoint_pb2 import LoadCheckpointScope
from proto.utils.data_example_pb2 import DataExample, Region, TimeFrame, heavy
from proto.utils.data_provider_pb2 import DataProviderParams
from proto.utils.databatch_pb2 import DataBatch
from proto.utils.embedding import (FloatsEncoding, encoding_for_model, pack_embedding_proto,
                                   undo_unit_norm_embedding, unit_norm_embedding,
                                   unpack_embedding_proto, unpack_embedding_protos_batched)
from proto.utils.embedding_pb2 import Embedding
from proto.utils.image_pb2 import Image
from proto.utils.lopq_code_pb2 import LOPQCode
from proto.utils.lopq_service_pb2 import LOPQEvalResult
from proto.utils.ndarray_pb2 import NDArray
from proto.utils.request_meta_pb2 import RequestMeta, ResponseStatus
from proto.utils.tag_pb2 import Tag
from proto.utils.train_config_pb2 import LratePair, TrainConfig

# Note(zeiler): we avoid importing utils/ioutil.py here.
# TODO(zeiler): can remove this after python 3 upgrade is done.
if sys.version_info >= (3, 0):
  from io import BytesIO, StringIO  #pylint: disable=deprecated-module
  _ = BytesIO
else:
  from cStringIO import StringIO  #pylint: disable=deprecated-module
  BytesIO = StringIO

standard_library.install_aliases()

try:  # locust doesn't like this for some reason.
  faulthandler.register(signal.SIGUSR1)
except Exception as e:
  # Avoiding logger here to not import of utils package.
  print("faulthandle didn't register")

# This just makes sure we don't remove the unused imports.
_ = BoundingBox
_ = DataBatch
_ = DataExample
_ = DataProviderParams
_ = Embedding
_ = FloatsEncoding
_ = Image
_ = LOPQCode
_ = LOPQEvalResult
_ = LoadCheckpointScope
_ = LratePair
_ = NDArray
_ = Parse
_ = ParseDict
_ = RequestMeta
_ = Tag
_ = TrainConfig
_ = Region
_ = TimeFrame
_ = encoding_for_model
_ = heavy
_ = pack_embedding_proto
_ = saved_output_pb2
_ = spire_pb2
_ = undo_unit_norm_embedding
_ = unit_norm_embedding
_ = unpack_embedding_proto
_ = unpack_embedding_protos_batched
_ = status_code

# Simple usage example:
#   # Create a proto object and serialize it to a json format string.
#   message = my_proto_pb2.MyMessage(foo='bar')
#   json_string = json_format.MessageToJson(message)

#   # Parse a json format string to proto object.
#   message = json_format.Parse(json_string, my_proto_pb2.MyMessage())

# Usage to/from dicts:
#   message = my_proto_pb2.MyMessage(foo='bar')
#   dic = json_format.MessageToDict(message, preserving_proto_field_name=True)
#   # Parse a json format string to proto object.
#   message = json_format.ParseDict(dic, my_proto_pb2.MyMessage())


# Helpers so you don't need to import json_format
def MessageToDict(proto):
  return json_format.MessageToDict(proto, preserving_proto_field_name=True)


# Helpers so you don't need to import json_format
def MessageToJson(proto):
  return json_format.MessageToJson(proto, preserving_proto_field_name=True)


class StatusCodeException(Exception):
  """ Helper for raising a specific proto status code up through your code.
  Use this ALWAYS when creating a ResponseStatus where ok=False (ie. for any type of error) because
  it also gets a stack trace that is passed back to the caller.

  """
  status_code = 0
  trace = ""
  user_msg = ""

  def __init__(self, code, msg, user_msg=None, trace=None):
    self.status_code = code
    if trace is None:
      self.trace = ''.join(tb.format_stack()[:-1])
    else:
      self.trace = trace
    if user_msg is None:
      user_msg = "Backend service had unexpected error. Please contact support@clarifai.com with error code: %d." % self.status_code
    self.user_msg = user_msg
    super(StatusCodeException, self).__init__(msg)

  def to_response_status(self):
    """ This converts this exception to the ResponseStatus field.

    Example:
    try:
      # something
    except StatusCodeException, e:
      status = e.to_response_status()
      response = response.SomeResponseProto(status=status)
    """
    return ResponseStatus(
        ok=False,
        code=self.status_code,
        user_msg=self.user_msg,
        exception_msg=str(self),
        trace=self.trace,
    )

  @classmethod
  def from_response_status(cls, status):
    trace = status.trace
    if not trace:
      trace = ''.join(tb.format_stack()[:-1])
    return cls(status.code, msg=status.exception_msg, user_msg=status.user_msg, trace=trace)


def NowTimestamp():
  """ Get the current timestamp as a Timestamp proto. """
  now = time.time()
  seconds = int(now)
  nanos = int((now - seconds) * 10**9)
  created = timestamp_pb2.Timestamp(seconds=seconds, nanos=nanos)
  return created


def TimestampToTime(timestamp_proto):
  """ Convert Timestamp proto back to time.time() like float number """
  nanos = float(timestamp_proto.nanos) / 10**9
  seconds = float(timestamp_proto.seconds)
  return seconds + nanos


def Duration(start, end, duration_proto=None):
  """ Take in two start and end times from time.time() and makes them into Duration proto.
  If the duration_proto is passed in then it fills in the fields and returns it. """
  if duration_proto is None:
    duration_proto = duration_pb2.Duration()
  diff = end - start
  seconds = int(diff)
  nanos = int((diff - seconds) * 10**9)
  duration_proto.seconds = seconds
  duration_proto.nanos = nanos
  return duration_proto


def get_backing_pool(server):
  """ Returns the backing pool for the given GRPC server."""
  return server._state.thread_pool


def isheavy(field_descriptor):
  """ Use DataExample.ListFields() give a list of tuples (field_descriptor, proto) for all the set
  fields. Call this on that field descriptor. """
  opts = field_descriptor.GetOptions()
  return opts.Extensions[heavy]


def field_names(proto):
  '''
  List names of fields that are defined in the proto.
  '''
  return [field_desc.name for (field_desc, value) in proto.ListFields()]


def proto_is_empty(proto):
  '''
  Return whether the message has no fields filled in.
  '''
  return len(proto.ListFields()) == 0


def read_image(image_proto):
  '''
  Return a PIL image from an image protobuf.
  '''
  return PILImage.open(BytesIO(image_proto.encoded_bytes))


def write_image(image_proto, image, format='jpeg', **save_kwargs):  # pylint: disable=redefined-builtin
  '''
  Write a PIL image to an image_proto in the specified format.
  '''
  sio = BytesIO()
  image.save(sio, format=format, **save_kwargs)
  image_proto.encoded_bytes = sio.getvalue()
  return image_proto


def read_ndarray(ndarray_proto):
  '''
  Return a numpy array from an ndarray protobuf.
  '''
  array = np.frombuffer(ndarray_proto.data, dtype=ndarray_proto.dtype)
  array = array.reshape(tuple(ndarray_proto.shape))
  return array


def write_ndarray(ndarray_proto, array):
  '''
  Write a numpy array to an NDArray protobuf.
  '''
  ndarray_proto.data = array.tobytes()
  ndarray_proto.shape.extend(array.shape)
  ndarray_proto.dtype = str(array.dtype)
  return ndarray_proto


def numpy_to_proto(ndarray):
  return NDArray(data=ndarray.tobytes(), shape=ndarray.shape, dtype=str(ndarray.dtype))


def overwrite_field(dest_proto, field_name, source_field):
  """ Overwrites the field of name "field_name" in the dest_proto from the source field. This
  handles the 4 possible cases: repeated Message, repeated primitive, single Message,
  single primitive.

  Example:
    dest = DataExample()
    source = DataExample()
    source.image.encoded_bytes = "some data"
    overwrite_field(dest, "image", source.image)
    assert dest.image.encoded_bytes == "some data"
  Args:
    dest_proto: a proto message.
    field_name: a name of the field in the dest_proto.
    source_field: a field from a source proto. Must be same types of dest_proto."field_name"
  """
  # Get the destination field in the db
  dbfield = getattr(dest_proto, field_name)
  #pylint: disable=no-member
  if hasattr(dbfield, 'CopyFrom'):
    dbfield.CopyFrom(source_field)
  elif isinstance(dbfield, collections.Iterable) and \
          not isinstance(dbfield, (basestring, collections.Mapping)):
    dest_proto.ClearField(field_name)  # this leaves the dbfield reference around :(
    getattr(dest_proto, field_name).extend(source_field)
  elif isinstance(dbfield, collections.Mapping):
    dest_proto.ClearField(field_name)
    dest_field = getattr(dest_proto, field_name)
    for key, value in source_field.items():
      if hasattr(dest_field[key], 'CopyFrom'):
        dest_field[key].CopyFrom(value)
      else:
        dest_field[key] = value
  else:  # for string, int, float, etc. primitive types
    setattr(dest_proto, field_name, source_field)


def data_example_meta(data_example):
  """ Returns meta for 'labels' and 'bboxes' keys -> numpy array (-1) in shape as we had
  labels (np.float32) or bboxes numBoxes x 5 (top,left,bottom,right,positive) (np.float32). """
  meta = {}
  if len(data_example.tag) > 0:
    meta['labels'] = np.asarray([tag.label_num for tag in data_example.tag], np.float32)
  if len(data_example.region) > 0:
    bbox_list = []
    for region in data_example.region:
      assert len(region.data.tag) == 1, 'Data provider can only handle one tag per bbox currently'
      tag = region.data.tag[0]
      bbox = region.region_info.bounding_box
      bbox_list.append(
          [tag.label_num, bbox.top_row, bbox.left_col, bbox.bottom_row, bbox.right_col])
    meta['bboxes'] = np.asarray(bbox_list, np.float32).reshape(len(bbox_list), 5)
  elif len(data_example.bbox) > 0:
    # read bbox proto field (older format) only if there are no regions (newer format)
    # only take first of the tags for now.
    assert all([len(bbox.tag) == 1 for bbox in data_example.bbox]), \
      "Only one Tag allowed per BoundingBox in this code."
    bbox_list = [[
        bbox.tag[0].label_num, bbox.top_row, bbox.left_col, bbox.bottom_row, bbox.right_col
    ] for bbox in data_example.bbox if bbox.is_positive]
    meta['bboxes'] = np.asarray(bbox_list, np.float32).reshape(len(bbox_list), 5)
  return meta


def populate_label_nums_and_aiids(data_example,
                                  dataset_vocab,
                                  tag_field='user_unique_concept_id',
                                  filter_out_of_vocab_tags=False):
  '''
  Fills in all label_nums in tags, bboxes and regions, based on tag field and vocab
  filter_out_of_vocab_tags - if true, remove tags that are not part of the dataset vocab
  '''
  catid_to_labelnum = dataset_vocab.get_catids2labelnums()

  def _populate_tag(tag):
    tag.label_num = catid_to_labelnum[getattr(tag, tag_field)]
    if not tag.aiid:
      tag.aiid = getattr(tag, tag_field)

  populate_tags(data_example, _populate_tag, filter_out_of_vocab_tags)


def populate_concepts_from_labelnums(data_example, dataset_vocab, filter_out_of_vocab_tags=False):
  '''
  Fills in all user_unique_concept_id and aiid in tags, bboxes and regions, based on label_num
  filter_out_of_vocab_tags - if true, remove tags that are not part of the dataset vocab
  '''
  labelnum_to_catid = dataset_vocab.get_labelnums2catids()
  labelnum_to_cname = dataset_vocab.get_labelnums2names()

  def _populate_tag(tag):
    if not tag.user_unique_concept_id:
      tag.user_unique_concept_id = labelnum_to_catid[tag.label_num]
    if not tag.aiid:
      tag.aiid = labelnum_to_catid[tag.label_num]
    if not tag.cname:
      tag.cname = labelnum_to_cname[tag.label_num]

  populate_tags(data_example, _populate_tag, filter_out_of_vocab_tags)


def populate_tags(data_example, populate_tag_func, filter_out_of_vocab_tags=False):
  '''
  Recursively fills in tag fields in the data_example, in all tag, bbox.tag and
  region.data.tag, by calling populate_tag_func on each tag.  This can insert
  aiid or cname based on labelnum, or vice-versa, depending on usage.
  See populate_label_nums and populate_concepts_from_labelnums for uses.
  '''
  if filter_out_of_vocab_tags:
    bboxes_with_tags = []
    regions_with_tags = []

  _populate_and_maybe_filter_tags(data_example.tag, populate_tag_func, filter_out_of_vocab_tags)

  for bb in data_example.bbox:
    _populate_and_maybe_filter_tags(bb.tag, populate_tag_func, filter_out_of_vocab_tags)
    if filter_out_of_vocab_tags and len(bb.tag) > 0:
      bboxes_with_tags.append(bb)
  if filter_out_of_vocab_tags:
    _maybe_replace_proto_list(data_example.bbox, bboxes_with_tags)

  for region in data_example.region:
    populate_tags(region.data, populate_tag_func, filter_out_of_vocab_tags)
    if filter_out_of_vocab_tags and len(region.data.tag) > 0:
      regions_with_tags.append(region)
  if filter_out_of_vocab_tags:
    _maybe_replace_proto_list(data_example.region, regions_with_tags)


def _populate_and_maybe_filter_tags(tags, populate_tag_func, filter_out_of_vocab_tags=False):
  tags_in_model = []
  for tag in tags:
    try:
      populate_tag_func(tag)
      if filter_out_of_vocab_tags:
        tags_in_model.append(tag)
    except KeyError:
      if not filter_out_of_vocab_tags:
        raise
  if filter_out_of_vocab_tags:
    _maybe_replace_proto_list(tags, tags_in_model)


def _maybe_replace_proto_list(proto_list, new_list):
  if len(proto_list) != len(new_list):
    del proto_list[:]
    proto_list.extend(new_list)


def data_batch_to_labels(dbproto):
  """ Helper to get the old style labels matrix out of DataExample.tag
  Returns:
    labels: np.float32 array (len(dbproto.example), numLabels) with -1's for empty labels.
  """
  max_labels = 0
  for example in dbproto.example:
    tagsum = sum([1 for tag in example.tag if tag.label_num > -1])
    if tagsum > max_labels:
      max_labels = tagsum
  labels = np.zeros((len(dbproto.example), max_labels)) - 1
  for i, example in enumerate(dbproto.example):
    for j, tag in enumerate(example.tag):
      if tag.label_num > -1:
        labels[i, j] = tag.label_num
  return labels.astype(np.float32)


def labels_into_data_batch(labels, dbproto):
  """ Overwrites the Tag objects in each DataExample of the dbproto that is passed in.

  UPDATES INPLACE

  Args:
    labels: len(dbproto.example) x numLabels np.float32 array.
    dbproto: a already constructed DataBatch proto with labels.shape[0] examples in it.
  """
  assert labels.shape[0] == len(dbproto.example)
  for i in range(labels.shape[0]):
    example = dbproto.example[i]
    example.ClearField('tag')
    for j in range(labels.shape[1]):
      if labels[i, j] > -1:
        tag = example.tag.add()
        tag.label_num = int(labels[i, j])
        tag.label_value = 1.0


class DataExampleID(object):
  __slots__ = ('id', 'cfid', 'asset_id', 'asset_cfid', 'postfix')

  def __init__(self, docid, cfid=None, asset_id=None, asset_cfid=None, frame_index=None):
    self.id = docid
    self.cfid = cfid
    self.asset_id = asset_id
    self.asset_cfid = asset_cfid
    self.postfix = ''
    if frame_index is not None:
      self.postfix = '_frame%d' % frame_index

  @classmethod
  def from_data_example(cls, data_example, frame_index=None):
    return cls(data_example.id, data_example.cfid, data_example.asset_id, data_example.asset_cfid,
               frame_index)

  @classmethod
  def from_minibatch(cls, mb):
    return cls(mb.caseid, mb.cfid, mb.asset_id, mb.asset_cfid)

  @classmethod
  def from_docid(cls, docid):
    return cls(docid)

  def set_data_example_ids(self, data_example):
    data_example.id = self.id + self.postfix
    if self.cfid:
      data_example.cfid = self.cfid + self.postfix
    if self.asset_id:
      data_example.asset_id = self.asset_id + self.postfix
    if self.asset_cfid:
      data_example.asset_cfid = self.asset_cfid + self.postfix
