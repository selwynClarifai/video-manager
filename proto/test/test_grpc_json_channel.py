#!/usr/bin/env python
# -*- coding: utf-8 -*-
from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

import unittest

from proto.clarifai.api.service_pb2 import _V2, ListInputsRequest
from proto.clarifai.api.service_pb2_grpc import V2Stub
from proto.utils.grpc_json_channel import GRPCJSONChannel

standard_library.install_aliases()


class TestGRPCJSONChannel(unittest.TestCase):

  def setUp(self):
    self.channel = GRPCJSONChannel(key="something", service_descriptor=_V2)
    self.stub = V2Stub(self.channel)

  def test_request_check(self):
    """ Make sure that passing the wrong proto type raises and exception. """

    with self.assertRaises(Exception):
      self.stub.PostModels(ListInputsRequest())

  def test_url_params(self):
    """ Check that url arg work. """
    request_dict = {'blah': "something"}
    with self.assertRaises(Exception) as e:
      self.stub.GetModel._url_params(request_dict)
      self.assertIn('model_id', e.exception.msg)
    request_dict = {'model_id': "something"}
    url = self.stub.GetModel._url_params(request_dict)
    self.assertEqual(url, "https://api.clarifai.com/v2/models/something")

  def test_unicode_url_params(self):
    """ Try a unicode url. """
    request_dict = {'model_id': u"my_model人"}
    url = self.stub.GetModel._url_params(request_dict)
    self.assertEqual(url, u"https://api.clarifai.com/v2/models/my_model%E4%BA%BA")

  def test_nested_url_params(self):
    """ What happens when there are two args. """
    request_dict = {'model_id': u"my_model人", "version_id": "something"}
    url = self.stub.GetModelVersion._url_params(request_dict)
    self.assertEqual(url,
                     u"https://api.clarifai.com/v2/models/my_model%E4%BA%BA/versions/something")


if __name__ == '__main__':
  unittest.main()
