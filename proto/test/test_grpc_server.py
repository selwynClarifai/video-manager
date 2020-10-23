from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

import threading
import time
import unittest
from builtins import range
from concurrent import futures

import grpc

from proto.grpc_server import GRPCServer
from proto.utils import proto_test_pb2, proto_test_pb2_grpc
from proto.utils.common import ResponseStatus
from utils.runtime import get_random_port

standard_library.install_aliases()

SERVICE = "proto_test"

POOL_SIZE = 5

# Use a pointer to a boolean to know if the rpc handlers should keep running.
SHOULD_RUN = [True]
# This keeps track of things already requested.
RUNNING = [-1]

LOCK = threading.RLock()


class ProtoTestServer(proto_test_pb2_grpc.ProtoTestServiceServicer):
  # @catch_rpc_errors(SERVICE, proto_test_pb2.ProtoTestResponse)
  def ProtoTestPredict(self, request, context):
    print('Inside grpc server method.')
    total = 0
    with LOCK:
      RUNNING[0] += 1  # just checking length of this below.
    while SHOULD_RUN[0] and total < request.sleep_time:
      time.sleep(0.1)
      total += 0.1

    # print request.sleep_time
    status = ResponseStatus(ok=True)
    return proto_test_pb2.ProtoTestResponse(status=status)


class TestProtoTest(unittest.TestCase):

  def test_exhausted(self):
    # Number over the limit of POOL_SIZE
    max_qsize = 2

    server = GRPCServer(
        futures.ThreadPoolExecutor(max_workers=POOL_SIZE),
        max_msg_length=10000,
        max_qsize=max_qsize)
    port = get_random_port()
    server.add_insecure_port('[::]:%s' % port)
    servicer = ProtoTestServer()
    proto_test_pb2_grpc.add_ProtoTestServiceServicer_to_server(servicer, server)
    server.start()

    # this much work will exceed max_workers + max_qsizse
    channel = grpc.insecure_channel('%s:%s' % ('localhost', port))
    stub = proto_test_pb2_grpc.ProtoTestServiceStub(channel)

    # Get lots in flight and wait for a long time.
    sleep = 60
    fs = []
    # queue up two extra compared to number of workers (POOL_SIZE).
    for i in range(POOL_SIZE + max_qsize):
      print("Sent rpc: %d" % i)
      future = stub.ProtoTestPredict.future(proto_test_pb2.ProtoTestRequest(sleep_time=sleep))
      fs.append(future)
      # Without this sleep then the futures pile up on each other and not all POOL_SIZE requests get
      # to the grpc server...yuck.
      while True:
        with LOCK:
          if RUNNING[0] == i or i >= POOL_SIZE:
            if i >= POOL_SIZE:
              time.sleep(0.1)
            break
        time.sleep(0.1)

    try:
      res = stub.ProtoTestPredict(proto_test_pb2.ProtoTestRequest(sleep_time=sleep))
      # Should not ever get her.
      self.fail()
    except Exception as e:
      #pylint: disable=no-member
      self.assertEqual(grpc.StatusCode.RESOURCE_EXHAUSTED, e.code())

    future = stub.ProtoTestPredict.future(proto_test_pb2.ProtoTestRequest(sleep_time=sleep))
    try:
      future.result()
      # Should not ever get her.
      self.fail()
    except Exception as e:
      #pylint: disable=no-member
      self.assertEqual(grpc.StatusCode.RESOURCE_EXHAUSTED, e.code())

      SHOULD_RUN[0] = False
      for f in fs:
        f.cancel()


if __name__ == '__main__':
  unittest.main()
