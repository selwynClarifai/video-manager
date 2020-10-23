from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

import unittest
from builtins import range

import numpy as np

from proto.utils.embedding import (FloatsEncoding, QuantizedEncoding, pack_embedding_proto,
                                   unit_norm_embedding, unpack_embedding_proto)

standard_library.install_aliases()

NUM_DIMENSIONS = 1024


class EmbeddingTests(unittest.TestCase):

  # Embedding error strings can be long, increase limit on error message length:
  maxDiff = 4096

  def _random_vec(self, ndim=NUM_DIMENSIONS, rectify=True, normalize=True):
    x = np.random.rand(ndim).astype(np.float32)
    if rectify:
      x = np.maximum(0, x)
    if normalize:
      x /= np.sqrt(np.sum(x**2))
    return x

  def test_convert_encoded_quantize(self):
    vec = self._random_vec()
    vec, norm = unit_norm_embedding(vec)
    pb = pack_embedding_proto(
        vec, embedding_norm=norm, encoding=QuantizedEncoding(0, 0.1, nbits=4))
    unpacked_vec = unpack_embedding_proto(pb)
    self.assertTrue(np.all(np.abs(vec - unpacked_vec) <= 0.05))

  def test_pack_floats(self):
    vec = self._random_vec(rectify=False, normalize=False)
    vec2 = FloatsEncoding.decode_proto(FloatsEncoding().encode_proto(vec))
    self.assertTrue(np.all(vec == vec2))

  def test_pack_quantized(self):
    for nbits in (4, 8):
      vec = self._random_vec(rectify=True, normalize=True)
      vec2 = QuantizedEncoding.decode_proto(
          QuantizedEncoding(0, 0.25, nbits=nbits).encode_proto(vec))
      self.assertTrue(np.all(np.abs(vec - vec2) <= 0.05))

  def test_pack_quantized_with_min(self):
    for nbits in (4, 8):
      vec = self._random_vec(rectify=False, normalize=True)
      vec2 = QuantizedEncoding.decode_proto(
          QuantizedEncoding(-0.2, 0.25, nbits=nbits).encode_proto(vec))
      self.assertTrue(np.all(np.abs(vec - vec2) <= 0.05))

  def _test_reapply_encoding(self, get_encoding, rectify_vectors):
    ntotal = 100
    nequal = 0
    for it in range(ntotal):
      vec = self._random_vec(rectify=rectify_vectors, normalize=True)
      encoding = get_encoding(vec)
      vec2 = encoding.decode_proto(encoding.encode_proto(vec))
      vec3 = encoding.decode_proto(encoding.encode_proto(vec2))
      nequal += np.all(vec2 == vec3)
      self.assertTrue(np.all(vec2 == vec3))
    #print "Vectors equal after reapplication: %d/%d (%.4f)" % (
    #       nequal, ntotal, nequal/float(ntotal))

  def test_reapply_floats(self):
    self._test_reapply_encoding(lambda vec: FloatsEncoding(), rectify_vectors=False)

  def test_reapply_quantized(self):
    for nbits in (4, 8):
      self._test_reapply_encoding(
          lambda vec: QuantizedEncoding(0, np.percentile(vec[vec > 0], 80), nbits=nbits),
          rectify_vectors=True)

  def test_reapply_quantized_norectify(self):
    for nbits in (4, 8):
      self._test_reapply_encoding(
        lambda vec: QuantizedEncoding(np.percentile(vec, 15), np.percentile(vec, 85), nbits=nbits),
        rectify_vectors=False)

  def test_encode_2d(self):
    for encoding in (FloatsEncoding(), QuantizedEncoding(-0.2, 0.25, nbits=4),
                     QuantizedEncoding(-0.2, 0.25, nbits=8)):
      vec = self._random_vec(rectify=False, normalize=True)
      vec2d = vec[np.newaxis, :]
      assert len(vec.shape) == 1
      assert vec2d.shape == (1, vec.shape[0])
      vec2 = encoding.decode_proto(encoding.encode_proto(vec2d))
      self.assertTrue(np.all(np.abs(vec - vec2) <= 0.05))


if __name__ == '__main__':
  unittest.main()
