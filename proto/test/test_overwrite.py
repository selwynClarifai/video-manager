from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

import unittest

#pylint: disable=no-member
from proto.utils.common import overwrite_field
from proto.utils.proto_test_pb2 import ProtoTest

standard_library.install_aliases()


class TestOverwriteProto(unittest.TestCase):

  def test_overwrite_scalar(self):
    rm = ProtoTest(scalar="id1")
    rm2 = ProtoTest(scalar="id2")
    overwrite_field(rm, 'scalar', rm2.scalar)
    self.assertEqual(rm.SerializeToString(), rm2.SerializeToString())

  def test_overwrite_message(self):
    rm = ProtoTest()
    rm2 = ProtoTest()
    rm.msg.name = "hey"
    rm.msg.another_msg.id = "id1"
    rm2.msg.name = "hey2"
    rm2.msg.another_msg.id = "id2"
    overwrite_field(rm, 'msg', rm2.msg)
    self.assertEqual(rm.SerializeToString(), rm2.SerializeToString())

  def test_overwrite_repeated_scalar(self):
    rm = ProtoTest()
    rm2 = ProtoTest()
    rm.repeated_scalar.extend([1, 2, 3])
    rm2.repeated_scalar.extend([4, 5, 6])
    overwrite_field(rm, 'repeated_scalar', rm2.repeated_scalar)
    self.assertEqual(rm.SerializeToString(), rm2.SerializeToString())

  def test_overwrite_repeated_message(self):
    rm = ProtoTest()
    rm2 = ProtoTest()
    repeated_msg = rm.repeated_msg.add()
    repeated_msg.num = 1
    repeated_msg.another_msg.id = "id1"
    repeated_msg = rm2.repeated_msg.add()
    repeated_msg.num = 2
    repeated_msg.another_msg.id = "id2"
    overwrite_field(rm, 'repeated_msg', rm2.repeated_msg)
    self.assertEqual(rm.SerializeToString(), rm2.SerializeToString())

  def test_overwrite_scalar_map(self):
    rm = ProtoTest()
    rm2 = ProtoTest()
    rm.map_scalar['hey'] = 'yo'
    rm2.map_scalar['hey2'] = 'yo2'
    overwrite_field(rm, 'map_scalar', rm2.map_scalar)
    self.assertEqual(rm.SerializeToString(), rm2.SerializeToString())

  def test_overwrite_repeated_map(self):
    rm = ProtoTest()
    rm2 = ProtoTest()
    rm.map_msg['hey'].name = 'yo'
    rm.map_msg['hey'].another_msg.id = 'yo'
    rm2.map_msg['hey2'].name = 'yo2'
    rm2.map_msg['hey2'].another_msg.id = 'yo2'
    overwrite_field(rm, 'map_msg', rm2.map_msg)
    self.assertEqual(rm.SerializeToString(), rm2.SerializeToString())


if __name__ == '__main__':
  unittest.main()
