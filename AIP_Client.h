#include <grpcpp/grpcpp.h>
#include "Api.h"
#include "proto/palantir/processing-service-v2.pb.h"
#include "proto/palantir/processing-service-v2.grpc.pb.h"

#include <iostream>
#include <memory>
#include <string>

using grpc::ChannelInterface;
using grpc::ClientContext;
using grpc::Status;
using aip::processor::v2::InferenceResponse;
using aip::processor::v2::ProcessingService;

class AIP_Client {
 public:
  AIP_Client(std::shared_ptr<ChannelInterface> channel);
  ~AIP_Client();

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string infer(std::string& imageFileName, int width, int height);

  void write_inferenceResponse(const InferenceResponse &inferenceResponse, 
                                            const std::string &imageFileName, int width, int height) const;
  std::string make_detections_header();

 private:
  std::unique_ptr<ProcessingService::Stub> _stub;
  Api _api;
};