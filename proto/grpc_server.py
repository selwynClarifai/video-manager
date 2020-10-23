from __future__ import absolute_import, division, print_function, unicode_literals
from future import standard_library

from grpc._cython import cygrpc
from grpc._server import _Server

from proto.health_check import health_check_pb2_grpc
from utils.health_server import HealthCheckServicer

standard_library.install_aliases()


class GRPCServer(_Server):

  def __init__(self, thread_pool, max_msg_length=67108864, max_qsize=10, compression=None):
    """
    thread_pool: a futures.ThreadPoolExecutor object
    max_msg_length: the max size of a message. Have to set into cython.
    max_qsize: number of items we are willing to have in the queue beyond the
  thread_pool._max_workers that are already in flight at a time. Leave as None for no limit.
    liveliness_port: a port for liveliness probes.
    """

    # pylint: disable=no-member
    options = [(cygrpc.ChannelArgKey.max_receive_message_length, max_msg_length)]
    if compression:
      options.append(("grpc.default_compression_algorithm", compression))

    # We can set this new flag since grpc 1.2.1 where our implementation of max_qsize really meant
    # when all the worker threads were busy we could queue up max_qsize more tasks.
    if max_qsize is None:
      max_concurrent_rpcs = None
    else:
      max_concurrent_rpcs = thread_pool._max_workers + max_qsize
    super(GRPCServer, self).__init__(thread_pool, (), None, options, max_concurrent_rpcs,
                                     compression)

    servicer = HealthCheckServicer()
    health_check_pb2_grpc.add_HealthServicer_to_server(servicer, self)
