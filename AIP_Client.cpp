/*
* This code based on https://github.com/grpc/grpc/blob/master/examples/cpp/helloworld/greeter_client.cc
*/
#include "AIP_Client.h"
#include "Utils.h"
#include <sstream>

using namespace std;
using aip::processor::v2::Rgb888Image;
using aip::processor::v2::Image;
using aip::processor::v2::Frame;
using aip::processor::v2::RequestHeader;
using aip::processor::v2::InferenceRequest;

AIP_Client::AIP_Client(std::shared_ptr<ChannelInterface> channel)
    : _stub(ProcessingService::NewStub(channel)) {}

// Assembles the client's payload, sends it and presents the response back
// from the server.
std::string AIP_Client::infer(std::string& imageFileName, int width, int height) {
    // Data we are sending to the server.
    Rgb888Image rgb_image;
    rgb_image.set_allocated_path(&imageFileName);
    Image image;
    image.set_allocated_rgb_image(&rgb_image);
    Frame frame;
    frame.set_allocated_image(&image);
    RequestHeader header;
    InferenceRequest request;
    request.set_allocated_frame(&frame);
    request.set_allocated_header(&header);

    // Container for the data we expect from the server.
    InferenceResponse response;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = _stub->Infer(&context, request, &response);

    // Act upon its status.
    if (status.ok()) {
        //return reply.message();
        write_inferenceResponse(response, imageFileName, width, height);
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
        return "RPC failed";
    }
}

void AIP_Client::write_inferenceResponse(const InferenceResponse &inferenceResponse, const string &imageFileName,
                            int width, int height) const {
    if (inferenceResponse.has_inferences()) {
        FILE *fp = NULL;
        size_t pos = imageFileName.find_last_of(".");

        string outFile = "";
        if (pos != string::npos) {
            outFile = imageFileName.substr(0, pos) + ".txt";
        }

        // Parse JSON predict response
        string responseText;
        string sepString = ", ";    // separator string for CSV file
        stringstream ssRegion;
        // Write Alarm and detections header
        api.width = width;
        api.height = height;
        responseText.append(api.make_alarm_header(imageFileName));
        responseText.append(make_detections_header());
        Inferences inferences = inferenceResponse.inferences();
        for (int i = 0; i < inferences.inference_size(); i++) {
            Inference inference = inferences.inference(i);
            if (inference.has_box()) {
                // Write inference ID as box ID
                ssRegion << inference.inferenceid();

                BoundingBox box = inference.box();
                UnitCoordinate upperLeft = box.c0();
                UnitCoordinate lowerRight = box.c1();

                // Pixel coordinates: the top-left corner is (0,0)
                int topRowPixel = static_cast<int>(round(upperLeft.row() * imageHeight));
                int leftColPixel = static_cast<int>(round(upperLeft.col() * imageWidth));
                int bottomRowPixel = static_cast<int>(round(lowerRight.row() * imageHeight));
                int rightColPixel = static_cast<int>(round(lowerRight.col() * imageWidth));

                // Write bounding box as pixel coordinates.
                ssRegion << sepString << topRowPixel << sepString << leftColPixel;
                ssRegion << sepString << bottomRowPixel << sepString << rightColPixel;

                // Get classifications for the bounding box.
                int numClasses = box.classifications_size();
                if (numClasses > 0) {
                  for (int i = 0; i < numClasses; i++) {
                    // Write class name
                    ssRegion << sepString << box.classifications(i).type();
                    // Write class confidence
                    ssRegion << sepString << box.classifications(i).confidence();
                  }
                }
            }
            ssRegion << endl;
            responseText.append(ssRegion.str());
        }

        if (!outFile.empty()) {
          fp  = fopen(outFile.c_str(), "w");
          fwrite(responseText.c_str(), responseText.size(), 1, fp);
          fp.close();
        } else {
          logging("Write_InferenceResponse: could not write to output file.")
        }
    }
}

// Header for the detections part of the Alarm file.
string AIP_Client::make_detections_header()
{
  // Write CSV header
  string sepString = ", ";    // separator string for CSV file
  stringstream header;
  header << "Inference_ID" << sepString;
  header << "BB_top_row" << sepString;
  header << "BB_left_col" << sepString;
  header << "BB_bot_row" << sepString;
  header << "BB_right_col" << sepString;
  header << "Concept_Name_1" << sepString;
  header << "Concept_Prediction_1" << sepString;
  header << "Concept_Name_2" << sepString;
  header << "Concept_Prediction_2" << sepString;
  header << "...\n";

  return header.str();
}

int main(int argc, char** argv) {
  // Instantiate the client. It requires a channel, out of which the actual RPCs
  // are created. This channel models a connection to an endpoint specified by
  // the argument "--target=" which is the only expected argument.
  // We indicate that the channel isn't authenticated (use of
  // InsecureChannelCredentials()).
  std::string target_str;
  std::string arg_str("--target");
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target=" << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else {
    target_str = "localhost:50051";
  }
  GreeterClient greeter(grpc::CreateChannel(
      target_str, grpc::InsecureChannelCredentials()));
  std::string user("world");
  std::string reply = greeter.SayHello(user);
  std::cout << "Greeter received: " << reply << std::endl;

  return 0;
}