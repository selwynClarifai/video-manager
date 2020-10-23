from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library
from past.builtins import basestring

import unittest

from proto.utils import image_pb2

standard_library.install_aliases()


class TestImageProto(unittest.TestCase):

  def test_construct(self):
    im = image_pb2.Image()

    # If all required fields are set, then it is initialized.
    self.assertTrue(im.IsInitialized())

    # Messages don't HasField until set.
    with self.assertRaises(Exception):
      im.HasField('name')
    self.assertTrue(hasattr(im, 'name'))

    # Neither bytes or url have been set.
    self.assertIsNone(im.WhichOneof("data"))
    # Also not that oneof fields are not actual fields, the ones within them are the fields.
    self.assertFalse(im.HasField('data'))

    # You can set values with assignment.
    im.url = "http://example.com/blah.jpeg"

    # If you set another oneof field, then it always takes the most recent one.
    im.encoded_bytes = b'adfjakldjakfq4klasdad49adskaj'
    self.assertEqual(im.WhichOneof("data"), "encoded_bytes")

    # You can get the seriealized byte size.
    self.assertEqual(im.ByteSize(), 61)
    # And this is how you seriealize to a binary string.
    ser = im.SerializeToString()
    self.assertEqual(len(ser), 61)
    self.assertTrue(isinstance(ser, basestring))

    self.assertTrue(im.HasField('encoded_bytes'))
    im.ClearField('encoded_bytes')
    self.assertFalse(im.HasField('encoded_bytes'))

    # Clear all the fields
    im.Clear()
    # Which gets it back into the un-initialized state.
    self.assertTrue(im.IsInitialized())


if __name__ == '__main__':
  unittest.main()
