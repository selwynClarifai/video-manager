from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

import time
from builtins import range, str

import numpy as np

from proto.utils import image_pb2
from utils.ioutil import pickle

standard_library.install_aliases()

shape = (320, 240, 3)
dtype = np.uint8
iters = 100
print("For shape: %s" % str(shape))
print("For dtype: %s" % str(dtype))
a = np.random.randn(*shape).astype(dtype)

st = time.time()
for i in range(iters):
  pickle.loads(pickle.dumps(a))
pickle_time = (time.time() - st) / float(iters)
print("Pickle dump and load: %f ms" % (pickle_time * 1000))

st = time.time()
for i in range(iters):
  np.frombuffer(a.tobytes(), dtype=dtype).reshape(shape)
numpy_time = (time.time() - st) / float(iters)
print("Numpy tobytes frombuffer: %f ms" % (numpy_time * 1000))

st = time.time()
for i in range(iters):
  im = image_pb2.Image()
  im.encoded_bytes = a.tobytes()
  im.ParseFromString(im.SerializeToString())
proto_time = (time.time() - st) / float(iters)
print("Proto np.tobytes serialize deserialize: %f ms" % (proto_time * 1000))

st = time.time()
for i in range(iters):
  np.asarray(a.tolist(), dtype=dtype).reshape(shape)
numpy_time = (time.time() - st) / float(iters)
print("Numpy tolist asarray: %f ms" % (numpy_time * 1000))
