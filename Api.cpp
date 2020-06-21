// C++ includes
#include <stdexcept>
#include <sstream>

// C includes
#include <math.h>   // for round
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Local includes
#include "Api.h"
#include "Utils.h"

using namespace std;

// declare static variables
string Api::encoding_table;
vector<int> Api::mod_table;

Api::Api()  
{
  Api::encoding_table = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                              'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                              'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                              'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                              'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                              'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                              'w', 'x', 'y', 'z', '0', '1', '2', '3',
                              '4', '5', '6', '7', '8', '9', '+', '/'};  


  mod_table = {0, 2, 1};
}

Api::~Api()
{
}

bool Api::upload_image(string &imageID, string &imageUrl, const string &imageFileName)
{
  bool status = true;
  CURL *handle;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a handle handle */ 
  handle = curl_easy_init();
  if (handle) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    string uploadInputsURL = base_url + "/v2/inputs";
    logging("Upload URL = %s", uploadInputsURL.c_str());
    curl_easy_setopt(handle, CURLOPT_URL, uploadInputsURL.c_str());

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader.c_str());    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    /* Now specify the POST data */ 
    char *inputsJson = NULL;
    cJSON *inputs = NULL;
    cJSON *input = NULL;
    cJSON *data = NULL;
    cJSON *image = NULL;
    cJSON *base64 = NULL;
    cJSON *root = NULL;
    try {
      root = cJSON_CreateObject();
      if (!root) {
        fprintf(stderr, "Error: could not create root cJSON object\n");
        throw std::runtime_error("Error: could not create root cJSON object");
      }

      inputs = cJSON_CreateArray();
      if (!inputs) {
        //fprintf(stderr, "Error: could not create inputs cJSON object\n");
        throw std::runtime_error("Error: could not create inputs cJSON object");
      }
      cJSON_AddItemToObject(root, "inputs", inputs);

      if (!create_json_image_inputs(inputs, input, data, image, base64, imageFileName)) {
        throw std::runtime_error("Error: create_json_image_inputs failed.");
      }

      inputsJson = cJSON_PrintUnformatted(root);
      if(!inputsJson) {
        //fprintf(stderr, "Error: cJSON_PrintUnformatted failed.\n");
        throw std::runtime_error("Error: cJSON_PrintUnformatted failed.");
      }

      curl_easy_setopt(handle, CURLOPT_POSTFIELDS, inputsJson);

/*
      string base64_string;
      encode_jpeg_to_base64_cpp(base64_string, imageFileName);
      json requestJ;
      requestJ = {
        { "inputs", {
          { "data", 
            { "image", {
              { "url", "https://samples.clarifai.com/metro-north.jpg" },
            }
            }
          },
        }},
      };
      cout << "JSON request: " << requestJ.dump() << endl;  
      */
      string response;

      // https://stackoverflow.com/questions/5701587/can-someone-explain-the-arguments-to-write-function-used-for-the-curl-option-cur
      curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
      curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_predict_response);
  
      /* Perform the request, res will get the return code */ 
      res = curl_easy_perform(handle);
      /* Check for errors */ 
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      }

      // Parse JSON predict response
      bool uploadComplete = false;

      if (parse_json_inputs_response(imageID, imageUrl, uploadComplete, response)) {
        if (print_debug) {
          logging("parse_json_inputs_response: imageFileName = %s, imageID = %s, imageUrl = %s, uploadComplete = %d", 
                                              imageFileName.c_str(), imageID.c_str(), imageUrl.c_str(), uploadComplete);
        }
      } else {
        if (print_debug) {
          logging("parse_json_inputs_response: FAIL");
        }
      }
      status = uploadComplete;

  } catch(const std::exception& e) {
      if (print_debug) {
        logging(e.what());
        status = false;
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
      if (inputsJson) {
        free(inputsJson);
      }
  }
  curl_global_cleanup();
  return status;
}

bool Api::verify_upload_complete(const string &imageID, string &imageURL)
{
  CURL *handle;
  CURLcode res;
  bool uploadComplete = false;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a handle handle */ 
  handle = curl_easy_init();
  if (handle) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    string uploadInputsURL = base_url + "/v2/inputs/" + imageID;
    curl_easy_setopt(handle, CURLOPT_URL, uploadInputsURL.c_str());

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader.c_str());    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    string response;

    // https://stackoverflow.com/questions/5701587/can-someone-explain-the-arguments-to-write-function-used-for-the-curl-option-cur
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_predict_response);

    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(handle);
    /* Check for errors */ 
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    // Parse JSON predict response
    string imageID;
    if (parse_json_input_by_id_response(imageID, imageURL, uploadComplete, response)) {
      if (print_debug) {
        logging("parse_json_inputs_response: imageID = %s, uploadComplete = %d", imageID.c_str(), uploadComplete);
      }
    } else {
      if (print_debug) {
        logging("parse_json_inputs_response: FAIL");
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
  }
  curl_global_cleanup();
  return uploadComplete;
}

int Api::predict_on_image(const string &imageFileName, const string &imageID, const string &imageURL)
{
  CURL *handle;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a handle handle */ 
  handle = curl_easy_init();
  if (handle) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    //string workflowDetectConceptURL = base_url + "/v2/workflows/Detect-Concept/results";
    string predictURL = base_url + "/v2/models/" + 
                  model_id + "/versions/" + model_version + "/outputs";
    curl_easy_setopt(handle, CURLOPT_URL, predictURL.c_str());

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader.c_str());    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    /* Now specify the POST data */ 
    char *inputsJson = NULL;
    cJSON *inputs = NULL;
    cJSON *input = NULL;
    cJSON *data = NULL;
    cJSON *image = NULL;
    cJSON *base64 = NULL;
    cJSON *idJson = NULL;
    cJSON *urlJson = NULL;
    cJSON *root = NULL;
    try {
      root = cJSON_CreateObject();
      if (!root) {
        fprintf(stderr, "Error: could not create root cJSON object\n");
        throw std::runtime_error("Error: could not create root cJSON object");
      }

      inputs = cJSON_CreateArray();
      if (!inputs) {
        throw std::runtime_error("Error: could not create inputs cJSON object");
      }
      cJSON_AddItemToObject(root, "inputs", inputs);

      if (!imageID.empty() && !imageURL.empty()) {
        if (!create_json_image_id_inputs(inputs, input, data, image, idJson, urlJson, imageID, imageURL)) {
          throw std::runtime_error("Error: create_json_image_inputs failed.");
        }
      } else if (!create_json_image_inputs(inputs, input, data, image, base64, imageFileName)) {
        throw std::runtime_error("Error: create_json_image_inputs failed.");
      }

      inputsJson = cJSON_PrintUnformatted(root);
      if(!inputsJson) {
        throw std::runtime_error("Error: cJSON_PrintUnformatted failed.");
      }
      
      curl_easy_setopt(handle, CURLOPT_POSTFIELDS, inputsJson);

      // Write response to output file
      string response;
      FILE *fp = NULL;
      size_t pos = imageFileName.find_last_of(".");

      if (pos != string::npos) {
        string outFile = imageFileName.substr(0, pos) + ".txt";
        fp  = fopen(outFile.c_str(), "w");

        // https://stackoverflow.com/questions/5701587/can-someone-explain-the-arguments-to-write-function-used-for-the-curl-option-cur
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_predict_response);
      } else {
        //fprintf(stderr, "Error: image file name %s does not have extension.\n", imageFileName);
        throw std::runtime_error("Error: image file name " + imageFileName  + " does not have extension.");
      }
  
      /* Perform the request, res will get the return code */ 
      res = curl_easy_perform(handle);
      /* Check for errors */ 
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      }

      // Parse JSON predict response
      string responseParsed;
      // Write Alarm and detections header
      responseParsed.append(make_alarm_header(imageFileName));
      responseParsed.append(make_detections_header());

      if (parse_json_predict_response(responseParsed, response)) {
        if (print_debug) {
          logging("parse_json_predict_response: SUCCESS");
        }
      } else {
        if (print_debug) {
          logging("parse_json_predict_response: FAIL");
        }
        responseParsed.append("parse_json_predict_response: FAIL\n");
      }
      if (pos != string::npos) {
        fwrite(responseParsed.c_str(), responseParsed.size(), 1, fp);
        fclose(fp);
      }
  } catch(const std::exception& e) {
      if (print_debug) {
        logging(e.what());
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
      if (inputsJson) {
        free(inputsJson);
      }
  }
  curl_global_cleanup();
  return 0;
}


// Header for the top part of the Alarm file.
string Api::make_alarm_header(const string &imageFilename)
{
  string sepString = ", ";    // separator string for CSV file
  stringstream header;
  header << "Frame_Num" << sepString;
  header << "PTS" << sepString;
  header << "Epoch_Timestamp" << sepString;
  header << "Image_Width" << sepString;
  header << "Image_Height" << sepString;
  header << endl;

  /*
  * Parse frame number and epoch timestamp (ms since Jan 1, 1970) from imageFilename.
  * imageFilename looks like: frame-68-1589507779583.jpg
  * Where 68 is frame number, and 1589507779583 is epoch timestamp.
  */
  size_t dash1 = imageFilename.find_first_of('-', 0);
  if (dash1 == string::npos) {
    return "";
  }
  size_t dash2 = imageFilename.find_first_of('-', dash1+1);
  if (dash2 == string::npos) {
    return "";
  }
  string frameString = imageFilename.substr(dash1+1, dash2-dash1-1);
  int frameNum = stoi(frameString);

  size_t dot = imageFilename.find_last_of('.');
  if (dot == string::npos) {
    return "";
  }
  string epochTimestampString = imageFilename.substr(dash2+1, dot-dash2-1);

  int64_t pts = ptsMap[frameNum];

  header << frameString << ", " << pts << ", " << epochTimestampString <<
            ", " << imageWidth << ", " << imageHeight << endl;

  return header.str();
}

// Header for the detections part of the Alarm file.
string Api::make_detections_header()
{
  // Write CSV header
  string sepString = ", ";    // separator string for CSV file
  stringstream header;
  header << "BB_ID" << sepString;
  header << "BB_top_row" << sepString;
  header << "BB_left_col" << sepString;
  header << "BB_bot_row" << sepString;
  header << "BB_right_col" << sepString;
  header << "Concept_ID_1" << sepString;
  header << "Concept_Name_1" << sepString;
  header << "Concept_Prediction_1" << sepString;
  header << "Concept_ID_2" << sepString;
  header << "Concept_Name_2" << sepString;
  header << "Concept_Prediction_2" << sepString;
  header << "...\n";

  return header.str();
}

// Parse JSON predict response
bool Api::parse_json_predict_response(string &responseParsed, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *outputs = NULL;

  string sepString = ", ";    // separator string for CSV file

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw std::runtime_error(errString);
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: Predict response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw std::runtime_error(errString);
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_predict_response: Predict response failed. Response description = ";
        errString.append(description->valuestring);
        throw std::runtime_error(errString);
      }
    }

    /*
    * outputs
    */
    outputs = cJSON_GetObjectItemCaseSensitive(root, "outputs");
    cJSON * output = NULL;
    if (!outputs) {
      errString = "Error: parse_json_predict_response: Predict response failed. No outputs found.";
      throw std::runtime_error(errString);
    }
    
    /*
    * outputs->status
    */
    cJSON_ArrayForEach(output, outputs) {
      cJSON *status = NULL;
      status = cJSON_GetObjectItemCaseSensitive(output, "status");
      if (!status) {
        errString = "Error: parse_json_predict_response: Predict outputs status not found";
        throw std::runtime_error(errString);
      }

      cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: parse_json_predict_response: Predict outputs response failed. Outputs response Code = " + std::to_string(code->valueint);
        throw std::runtime_error(errString);
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_predict_response: Predict outputs response failed. Outputs response description = ";
        errString.append(description->valuestring);
        throw std::runtime_error(errString);
      }

      /*
      * outputs->data
      */
      cJSON *outputs_data = NULL;
      outputs_data = cJSON_GetObjectItemCaseSensitive(output, "data");
      if (!outputs_data) {
        errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data found.";
        throw std::runtime_error(errString);
      }

      /*
      * outputs->data->regions
      */
      cJSON *regions = NULL;
      regions = cJSON_GetObjectItemCaseSensitive(outputs_data, "regions");
      if (!regions) {
        errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions found.";
        throw std::runtime_error(errString);
      } 

      stringstream ssRegion;
      cJSON *region = NULL;
      cJSON_ArrayForEach(region, regions) {
        cJSON *id = cJSON_GetObjectItemCaseSensitive(region, "id");
        cJSON *region_info = cJSON_GetObjectItemCaseSensitive(region, "region_info");
        cJSON *bbox = NULL;
        bbox = cJSON_GetObjectItemCaseSensitive(region_info, "bounding_box");
        if (!cJSON_IsString(id)) {
          errString = "Error: parse_json_predict_response: Predict outputs response failed. No outputs->data->regions->bounding_box.";
          throw std::runtime_error(errString);
        }
        ssRegion << id->valuestring;
        if (bbox) {
          cJSON *top_row = cJSON_GetObjectItemCaseSensitive(bbox, "top_row");
          cJSON *left_col = cJSON_GetObjectItemCaseSensitive(bbox, "left_col");
          cJSON *bottom_row = cJSON_GetObjectItemCaseSensitive(bbox, "bottom_row");
          cJSON *right_col = cJSON_GetObjectItemCaseSensitive(bbox, "right_col");
          if ( !cJSON_IsNumber(top_row) || !cJSON_IsNumber(left_col) ||
              !cJSON_IsNumber(bottom_row) || !cJSON_IsNumber(right_col) ) {
            errString = "Error: parse_json_predict_response: Predict regions response failed. Could not parse bounding box";
            throw std::runtime_error(errString);
          }

          // Pixel coordinates: the top-left corner is (0,0)
          int topRowPixel = static_cast<int>(round(top_row->valuedouble * imageHeight));
          int leftColPixel = static_cast<int>(round(left_col->valuedouble * imageWidth));
          int bottomRowPixel = static_cast<int>(round(bottom_row->valuedouble * imageHeight));
          int rightColPixel = static_cast<int>(round(right_col->valuedouble * imageWidth));

          ssRegion << sepString << topRowPixel << sepString << leftColPixel;
          ssRegion << sepString << bottomRowPixel << sepString << rightColPixel;
        }

        /*
        * outputs->data->regions->data
        */
        cJSON *regions_data = NULL;
        regions_data = cJSON_GetObjectItemCaseSensitive(region, "data");
        if (!regions_data) {
          errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data found.";
          throw std::runtime_error(errString);
        }

        /*
        * outputs->data->regions->data->concepts
        */
        cJSON *concepts = NULL;
        concepts = cJSON_GetObjectItemCaseSensitive(regions_data, "concepts");
        if (!concepts) {
          errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts found.";
          throw std::runtime_error(errString);
        }

        cJSON *concept = NULL;
        cJSON_ArrayForEach(concept, concepts) {
          cJSON *id = NULL;
          id = cJSON_GetObjectItemCaseSensitive(concept, "id");
          if (!cJSON_IsString(id)) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts->id found.";
            throw std::runtime_error(errString);
          }

          ssRegion << sepString << id->valuestring;

          cJSON *name = NULL;
          name = cJSON_GetObjectItemCaseSensitive(concept, "name");
          if (!cJSON_IsString(name)) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts->name found.";
            throw std::runtime_error(errString);
          }

          ssRegion << sepString << name->valuestring;

          cJSON *value = NULL;
          value = cJSON_GetObjectItemCaseSensitive(concept, "value");
          if (!cJSON_IsNumber(value)) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts->value found.";
            throw std::runtime_error(errString);
          }

          ssRegion << sepString << value->valuedouble;
        }   // concepts

        responseParsed.append(ssRegion.str());
        responseParsed.append("\n");

        // reset to empty string
        ssRegion.str("");
        ssRegion.clear();
      }   // regions
    }   // outputs

  } catch(const std::exception& e) {
    logging(e.what());
    responseParsed.append(e.what());
    responseParsed.append("\n");
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

// Parse JSON workflow predict response
bool Api::parse_json_workflow_predict_response(string &responseParsed, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *outputs = NULL;

  // Write CSV header
  string sepString = ", ";    // separator string for CSV file
  responseParsed.append(make_detections_header());

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw std::runtime_error(errString);
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: Predict response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw std::runtime_error(errString);
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_workflow_predict_response: Predict response failed. Response description = ";
        errString.append(description->valuestring);
        throw std::runtime_error(errString);
      }
    }

    /*
    * results
    */
    results = cJSON_GetObjectItemCaseSensitive(root, "results");
    if (!results) {
      errString = "Error: parse_json_workflow_predict_response: Predict response failed. No results found.";
      throw std::runtime_error(errString);
    }

    cJSON * result = NULL;
    cJSON_ArrayForEach(result, results) {
      /*
      * results->outputs
      */
      outputs = cJSON_GetObjectItemCaseSensitive(result, "outputs");
      cJSON * output = NULL;
      if (!outputs) {
        errString = "Error: parse_json_workflow_predict_response: Predict response failed. No results->outputs found.";
        throw std::runtime_error(errString);
      }
      
      /*
      * results->outputs->status
      */
      cJSON_ArrayForEach(output, outputs) {
        cJSON *status = NULL;
        status = cJSON_GetObjectItemCaseSensitive(output, "status");
        if (!status) {
          errString = "Error: parse_json_workflow_predict_response: Predict outputs status not found";
          throw std::runtime_error(errString);
        }

        cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
        cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
        if (!cJSON_IsNumber(code) || code->valueint != 10000) {
          errString = "Error: parse_json_workflow_predict_response: Predict outputs response failed. Outputs response Code = " + std::to_string(code->valueint);
          throw std::runtime_error(errString);
        }

        if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
          errString = "Error: parse_json_workflow_predict_response: Predict outputs response failed. Outputs response description = ";
          errString.append(description->valuestring);
          throw std::runtime_error(errString);
        }

        /*
        * results->outputs->data
        */
        cJSON *outputs_data = NULL;
        outputs_data = cJSON_GetObjectItemCaseSensitive(output, "data");
        if (!outputs_data) {
          errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data found.";
          throw std::runtime_error(errString);
        }

        /*
        * results->outputs->data->regions
        */
        cJSON *regions = NULL;
        regions = cJSON_GetObjectItemCaseSensitive(outputs_data, "regions");
        if (!regions) {
          errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions found.";
          throw std::runtime_error(errString);
        } 

        stringstream ssRegion;
        cJSON *region = NULL;
        cJSON_ArrayForEach(region, regions) {
          cJSON *id = cJSON_GetObjectItemCaseSensitive(region, "id");
          cJSON *region_info = cJSON_GetObjectItemCaseSensitive(region, "region_info");
          cJSON *bbox = NULL;
          bbox = cJSON_GetObjectItemCaseSensitive(region_info, "bounding_box");
          if (!cJSON_IsString(id)) {
            errString = "Error: parse_json_workflow_predict_response: Predict outputs response failed. No outputs->data->regions->bounding_box.";
            throw std::runtime_error(errString);
          }
          ssRegion << id->valuestring;
          if (bbox) {
            cJSON *top_row = cJSON_GetObjectItemCaseSensitive(bbox, "top_row");
            cJSON *left_col = cJSON_GetObjectItemCaseSensitive(bbox, "left_col");
            cJSON *bottom_row = cJSON_GetObjectItemCaseSensitive(bbox, "bottom_row");
            cJSON *right_col = cJSON_GetObjectItemCaseSensitive(bbox, "right_col");
            if ( !cJSON_IsNumber(top_row) || !cJSON_IsNumber(left_col) ||
                !cJSON_IsNumber(bottom_row) || !cJSON_IsNumber(right_col) ) {
              errString = "Error: parse_json_workflow_predict_response: Predict regions response failed. Could not parse bounding box";
              throw std::runtime_error(errString);
            }

            ssRegion << sepString << top_row->valuedouble << sepString << left_col->valuedouble;
            ssRegion << sepString << bottom_row->valuedouble << sepString << right_col->valuedouble;
          }

          /*
          * results->outputs->data->regions->data
          */
          cJSON *regions_data = NULL;
          regions_data = cJSON_GetObjectItemCaseSensitive(region, "data");
          if (!regions_data) {
            errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data found.";
            throw std::runtime_error(errString);
          }

          /*
          * results->outputs->data->regions->data->concepts
          */
          cJSON *concepts = NULL;
          concepts = cJSON_GetObjectItemCaseSensitive(regions_data, "concepts");
          if (!concepts) {
            errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts found.";
            throw std::runtime_error(errString);
          }

          cJSON *concept = NULL;
          cJSON_ArrayForEach(concept, concepts) {
            cJSON *id = NULL;
            id = cJSON_GetObjectItemCaseSensitive(concept, "id");
            if (!cJSON_IsString(id)) {
              errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts->id found.";
              throw std::runtime_error(errString);
            }

            ssRegion << sepString << id->valuestring;

            cJSON *name = NULL;
            name = cJSON_GetObjectItemCaseSensitive(concept, "name");
            if (!cJSON_IsString(name)) {
              errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts->name found.";
              throw std::runtime_error(errString);
            }

            ssRegion << sepString << name->valuestring;

            cJSON *value = NULL;
            value = cJSON_GetObjectItemCaseSensitive(concept, "value");
            if (!cJSON_IsNumber(value)) {
              errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts->value found.";
              throw std::runtime_error(errString);
            }

            ssRegion << sepString << value->valuedouble;
          }   // concepts

          responseParsed.append(ssRegion.str());
          responseParsed.append("\n");

          // reset to empty string
          ssRegion.str("");
          ssRegion.clear();
        }   // regions
      }   // outputs
    }   // results



  } catch(const std::exception& e) {
    logging(e.what());
    responseParsed.append(e.what());
    responseParsed.append("\n");
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

// Parse JSON inputs response
bool Api::parse_json_inputs_response(string &imageID, string &imageUrl, bool &uploadComplete, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *inputs = NULL;

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw std::runtime_error(errString);
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: Predict response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw std::runtime_error(errString);
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_inputs_response: response failed. Response description = ";
        errString.append(description->valuestring);
        throw std::runtime_error(errString);
      }
    }

    /*
    * inputs
    */
    inputs = cJSON_GetObjectItemCaseSensitive(root, "inputs");
    cJSON * input = NULL;
    if (!inputs) {
      errString = "Error: parse_json_inputs_response: response failed. No inputs found.";
      throw std::runtime_error(errString);
    }
    
    /*
    * inputs->id
    */
    cJSON_ArrayForEach(input, inputs) {
      cJSON *id = NULL;
      id = cJSON_GetObjectItemCaseSensitive(input, "id");
      if (!id) {
        errString = "Error: parse_json_inputs_response: inputs id not found";
        throw std::runtime_error(errString);
      }
      imageID.assign(id->valuestring);

    /*
    * inputs->data
    */
      cJSON *data = NULL;
      data = cJSON_GetObjectItemCaseSensitive(input, "data");
      if (!id) {
        errString = "Error: parse_json_inputs_response: inputs data not found";
        throw std::runtime_error(errString);
      }
      cJSON *image = NULL;
      image = cJSON_GetObjectItemCaseSensitive(data, "image");
      if (!image) {
        errString = "Error: parse_json_inputs_response: inputs image not found";
        throw std::runtime_error(errString);
      }
      cJSON *url = NULL;
      url = cJSON_GetObjectItemCaseSensitive(image, "url");
      if (!image) {
        errString = "Error: parse_json_inputs_response: inputs url not found";
        throw std::runtime_error(errString);
      }
      imageUrl.assign(url->valuestring);

    /*
    * inputs->status
    */
      cJSON *status = NULL;
      status = cJSON_GetObjectItemCaseSensitive(input, "status");
      if (!status) {
        errString = "Error: parse_json_inputs_response: inputs status not found";
        throw std::runtime_error(errString);
      }

      cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
      if (!cJSON_IsNumber(code)) {
        errString = "Error: parse_json_inputs_response: inputs response failed.";
        throw std::runtime_error(errString);
      }
      uploadComplete = true;
      if (code->valueint != 30000) {
        uploadComplete = false;
      }
    }   // inputs

  } catch(const std::exception& e) {
    logging(e.what());
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

// Parse JSON Get input by ID response: https://docs.clarifai.com/api-guide/data-management/inputs#get-input-by-id
bool Api::parse_json_input_by_id_response(string &imageID, string &imageUrl, bool &uploadComplete, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *input = NULL;

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw std::runtime_error(errString);
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: parse_json_input_by_id_response: response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw std::runtime_error(errString);
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_input_by_id_response: response failed. Response description = ";
        errString.append(description->valuestring);
        throw std::runtime_error(errString);
      }
    }

    /*
    * input
    */
    input = cJSON_GetObjectItemCaseSensitive(root, "input");
    if (!input) {
      errString = "Error: parse_json_input_by_id_response: response failed. No input found.";
      throw std::runtime_error(errString);
    }

    /*
    * input->data
    */
    cJSON *data = NULL;
    data = cJSON_GetObjectItemCaseSensitive(input, "data");
    if (!data) {
      errString = "Error: parse_json_input_by_id_response: input data not found";
      throw std::runtime_error(errString);
    }
    cJSON *image = NULL;
    image = cJSON_GetObjectItemCaseSensitive(data, "image");
    if (!image) {
      errString = "Error: parse_json_input_by_id_response: input image not found";
      throw std::runtime_error(errString);
    }
    cJSON *url = NULL;
    url = cJSON_GetObjectItemCaseSensitive(image, "url");
    if (!image) {
      errString = "Error: parse_json_input_by_id_response: input url not found";
      throw std::runtime_error(errString);
    }
    imageUrl.assign(url->valuestring);
  
    /*
    * input->status
    */
    cJSON *id = NULL;
    id = cJSON_GetObjectItemCaseSensitive(input, "id");
    if (!id) {
      errString = "Error: parse_json_input_by_id_response: input id not found";
      throw std::runtime_error(errString);
    }
    imageID.assign(id->valuestring);

    cJSON *status = NULL;
    status = cJSON_GetObjectItemCaseSensitive(input, "status");
    if (!status) {
      errString = "Error: parse_json_input_by_id_response: inputs status not found";
      throw std::runtime_error(errString);
    }

    cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
    cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
    if (!cJSON_IsNumber(code)) {
      errString = "Error: parse_json_input_by_id_response: inputs response failed.";
      throw std::runtime_error(errString);
    }
    uploadComplete = true;
    if (code->valueint != 30000) {
      uploadComplete = false;
    }

  } catch(const std::exception& e) {
    logging(e.what());
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

bool Api::create_json_image_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, cJSON *base64, 
                        const string &imageFileName)
{
    /*
    * Add input images
    */
    input = cJSON_CreateObject();
    if (!input) {
      fprintf(stderr, "Error: could not create input cJSON object\n");
      return false;
    }
    cJSON_AddItemToArray(inputs, input);

    data = cJSON_CreateObject();
    if (!data) {
      fprintf(stderr, "Error: could not create data cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(input, "data", data);

    image = cJSON_CreateObject();
    if (!image) {
      fprintf(stderr, "Error: could not create image cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(data, "image", image);

    // assign encoded jpg string to base64 object
    encode_jpeg_to_base64(&base64, imageFileName.c_str());
    if (!base64) {
      fprintf(stderr, "Error: could not create base64 cJSON object\n");
      return false;
    }
    
    cJSON_AddItemToObject(image, "base64", base64);

    return true;
}

bool Api::create_json_image_id_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, 
                          cJSON *idJson, cJSON *urlJson, const string &imageID, const string &imageURL)
{
    /*
    * Add input images
    */
    input = cJSON_CreateObject();
    if (!input) {
      fprintf(stderr, "Error: could not create input cJSON object\n");
      return false;
    }
    cJSON_AddItemToArray(inputs, input);

    // add imageID to request.
    idJson = cJSON_CreateObject();
    if (!idJson) {
      throw std::runtime_error("Error: could not create idJson cJSON object");
    }
    idJson = cJSON_CreateString(imageID.c_str());
    cJSON_AddItemToObject(input, "id", idJson);

    data = cJSON_CreateObject();
    if (!data) {
      fprintf(stderr, "Error: could not create data cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(input, "data", data);

    image = cJSON_CreateObject();
    if (!image) {
      fprintf(stderr, "Error: could not create image cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(data, "image", image);

    urlJson = cJSON_CreateString(imageURL.c_str());
    if (!urlJson) {
      fprintf(stderr, "Error: could not create urlJson cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(image, "url", urlJson);

    return true;
}

// Callback function to handle response from workflow predict request.
// https://stackoverflow.com/questions/9786150/save-curl-content-result-into-a-string-in-c
size_t Api::write_predict_response(char *ptr, size_t size, size_t nmemb, void *responseJson)
{
  size_t realSize = size * nmemb;
  ((std::string*)responseJson)->append((char*)ptr, realSize);

  return realSize;
}

// https://stackoverflow.com/questions/26175293/how-to-convert-image-to-base64-in-c
void Api::encode_jpeg_to_base64(cJSON **base64_string, const char *jpeg_file_name)
{
  FILE *file;
  unsigned char *jpeg64_buf = NULL;
  char *jpeg64_string = NULL;

  //Open file                                                                                                                                                                                                
  file = fopen(jpeg_file_name , "rb");
  if (!file) {
    {
      fprintf(stderr, "Unable to open file %s\n", jpeg_file_name);
      return;
    }
  }
 
  // Get file length                                                               
  fseek(file, 0, SEEK_END);
  long fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory
  jpeg64_buf=(unsigned char *)malloc(fileLen+1);
  if (!jpeg64_buf)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return;
    }

  //Read file contents into buffer                                                                                                                                                                           
  fread(jpeg64_buf, fileLen, 1, file);
  size_t output_length = 0;
  jpeg64_string = base64_encode(jpeg64_buf, (size_t)fileLen, &output_length);

  // Null-terminate jpeg64_string. Else cJSON_CreateString reads beyond the end.
  //jpeg64_string[output_length] = '\0';
  *base64_string = cJSON_CreateString(jpeg64_string);

  fclose(file);
  //insert_blob(jpeg64_buf);
  if (jpeg64_buf) {
    free(jpeg64_buf);
  }
  if (jpeg64_string) {
    free(jpeg64_string);
  }
}

// https://stackoverflow.com/questions/26175293/how-to-convert-image-to-base64-in-c
void Api::encode_jpeg_to_base64_cpp(string &base64_string, const string &jpeg_file_name)
{
  FILE *file;
  unsigned char *jpeg64_buf = NULL;
  char *jpeg64_string = NULL;

  //Open file                                                                                                                                                                                                
  file = fopen(jpeg_file_name.c_str() , "rb");
  if (!file) {
    {
      fprintf(stderr, "Unable to open file %s", jpeg_file_name.c_str());
      return;
    }
  }
 
  // Get file length                                                               
  fseek(file, 0, SEEK_END);
  long fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory
  jpeg64_buf=(unsigned char *)malloc(fileLen+1);
  if (!jpeg64_buf)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return;
    }

  //Read file contents into buffer                                                                                                                                                                           
  fread(jpeg64_buf, fileLen, 1, file);
  size_t output_length = 0;
  jpeg64_string = base64_encode(jpeg64_buf, (size_t)fileLen, &output_length);

  base64_string.assign(jpeg64_string);

  fclose(file);
  //insert_blob(jpeg64_buf);
  if (jpeg64_buf) {
    free(jpeg64_buf);
  }
  if (jpeg64_string) {
    free(jpeg64_string);
  }
}

// Base64.c functions
char* Api::base64_encode(const unsigned char *data,
                    size_t input_length,
                    size_t *output_length) {

  *output_length = 4 * ((input_length + 2) / 3);
  // Selwyn - add one to the length for NULL termination
  *output_length += 1;

  char *encoded_data = (char *)malloc(*output_length);
  if (encoded_data == NULL) return NULL;

  for (int i = 0, j = 0; i < input_length;) {

    uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

    uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

    encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
  }

  for (int i = 0; i < mod_table[input_length % 3]; i++)
    encoded_data[*output_length - 1 - i] = '=';

  // Selwyn - NULL terminate
  encoded_data[*output_length-1] = '\0';
  return encoded_data;
}