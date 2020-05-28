
#ifndef API_H
#define API_H

#ifdef __cplusplus
extern "C" {
#endif  
  #include <curl/curl.h>
  #include "cJSON.h"
  //#include "base64.h"
#ifdef __cplusplus
}
#endif


#include <string>
#include <map>
#include <vector>

//#include "nlohmann/json.hpp"

// Local includes
#include "Configuration_File.h"

class Api {
  public:

  Api();
  ~Api();

  // libCurl API access
  bool upload_image(std::string &imageID, std::string &imageUrl, const std::string &imageFileName);
  bool verify_upload_complete(const std::string &imageID, std::string &imageURL);
  int predict_on_image(const std::string &imageFileName, const std::string &imageID = "", const std::string &imageURL = "");
  
  // JSON parsing
  static bool create_json_image_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, cJSON *base64, 
                          const std::string &imageFileName);
  static bool create_json_image_id_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, 
                            cJSON *idJson, cJSON *urlJson, const std::string &imageID, const std::string &imageURL);
  bool parse_json_predict_response(std::string &responseParsed, const std::string &responseJson);
  bool parse_json_workflow_predict_response(std::string &responseParsed, const std::string &responseJson);
  bool parse_json_inputs_response(std::string &imageID, std::string &imageUrl, bool &uploadComplete, const std::string &responseJson);
  bool parse_json_input_by_id_response(std::string &imageID, std::string &imageUrl, bool &uploadComplete, const std::string &responseJson);

  // Alarm file
  std::string make_alarm_header(const std::string &imageFilename);
  std::string make_detections_header();
  static size_t write_predict_response(char *ptr, size_t size, size_t nmemb, void *responseJson);

  // Base64 encode jpeg
  static void encode_jpeg_to_base64(cJSON **base64_string, const char *jpeg_file_name);
  static void encode_jpeg_to_base64_cpp(std::string &base64_string, const std::string &jpeg_file_name);

  int imageWidth, imageHeight;
 
  // variables copied from Configuration_File class
  bool print_debug;
  std::string authorizationHeader;
  std::string base_url;
  std::string model_id;
  std::string model_version;
  std::string output_dir;
  bool upload;

  // Base64.c code
  static std::string encoding_table;  
  static std::vector<int> mod_table;

  static char *base64_encode(const unsigned char *data, size_t input_length, size_t *output_length);

};

#endif // API_H