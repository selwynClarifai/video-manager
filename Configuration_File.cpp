// C includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h> // for getopt
#include <dirent.h> // for directory access

// C++ includes
#include <iostream>
#include <sstream>
#include <fstream>

// Local includes
#include "Configuration_File.h"
#include "Utils.h"

using namespace std;

Configuration_File::Configuration_File(const string &conf_file) :
    config_filename(conf_file)
{
    base_url = "https://api.clarifai.com";
    api_key = "4a5f25ecc48047ad8fb1d33ca687082e";
    model_id = "cb649131aa72f86911815b0fe98dee55"; // General Detection
    model_version = "13c11ec702854e97a695ca2a0f809a95"; // General Detection
    frames_to_skip = 1;
    jpeg_quality = 75;
    output_dir = "/files/images";
    imageSizeWritten = false;
    save_I_frames = false;
    save_video_file = true;
    print_debug = false;
    upload = false;
    video_max_seconds = 3600;   // max number of seconds for video before creating new file

    // Streams to capture / predict on
    stream_url = "";
    stream_name = "mwir";

    metadata_structure = "{ \
        \"my interesting thing 1\": \"value\", \
        \"key2\": \"value2\" \
        }";    

    authorizationHeader = "Authorization: Key " + api_key;

  // Configuration file
  if (!found_config_file()) {
    cout << "configuration file not found. Writing a default one." << endl;
    write_json_config_file();
  } else {
    cout << "configuration file found. Reading..." << endl;
    read_json_config_file();
  }

  write_metadata_from_config();
}

Configuration_File::~Configuration_File()
{
}

// Looks for config.json in exe directory 
bool Configuration_File::found_config_file()
{
  /*
  DIR *dpdf;
  struct dirent *epdf;
  bool found = false;

  dpdf = opendir("..");
  if (dpdf != NULL){
    while (epdf = readdir(dpdf)){
      if (strcmp(epdf->d_name, "config.json") == 0) {
        found = true;
        break;
      }
    }
  }
  closedir(dpdf);
  */

  ifstream infile(config_filename.c_str());
  return infile.good();
} 

/*
* Writes metadata_structure from config file into a separate time-stamped file.
* Time is represented as seconds from the epoch (1970).
*/
void Configuration_File::write_metadata_from_config()
{
  // Get number of ms from epoch
  chrono::milliseconds msSinceEpoch = millisecs_since_epoch();

  // Insert epochTime before metadata_structure.
  size_t pos = metadata_structure.find("{");  // opening brace of the json object
  if (pos == string::npos) {
    pos = 0;
  } else {
    // "{" found. Insert after it.
    pos += 1;
  }
  metadata_structure.insert(pos, "\"time_ms_since_epoch\": " + 
            std::to_string(chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count()) + ", ");

  // Convert metadata_structure string to JSON, and add timestamp.
  cJSON *metaJson = cJSON_Parse(metadata_structure.c_str());
  if (!metaJson) {
    logging("Error: failed to parse metadata_structure to JSON.");
  }
  //cJSON_AddNumberToObject(metaJson, "time", epochSeconds);
  char *metaJsonChars = cJSON_Print(metaJson);

  stringstream metadataFilename;
  metadataFilename << output_dir << "/metadata_" << 
            chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count() << ".json";
  FILE *fp = fopen(metadataFilename.str().c_str(), "w");
  fwrite(metaJsonChars, sizeof(char), strlen(metaJsonChars), fp);
  fclose(fp);

  // Cleanup JSON objects
  cJSON_Delete(metaJson);
  free(metaJsonChars);
}

bool Configuration_File::read_json_config_file()
{
  bool status = true;
  
  cJSON *j_base_url = NULL;
  cJSON *j_api_key = NULL;
  cJSON *j_model_id = NULL;
  cJSON *j_model_version = NULL;
  cJSON *j_frames_to_skip = NULL;
  cJSON *j_jpeg_quality = NULL;
  cJSON *j_save_I_frames = NULL;
  cJSON *j_output_dir = NULL;
  cJSON *j_print_debug = NULL;
  cJSON *j_save_video_file = NULL;
  cJSON *j_upload = NULL;
  cJSON *j_video_max_seconds = NULL;
  cJSON *j_metadata_structure = NULL;
  cJSON *j_stream_url = NULL;
  cJSON *j_stream_name = NULL;
  cJSON *j_stream_predict = NULL;
  cJSON *config = NULL;

  try {

    // read config file
    FILE *fp = std::fopen(config_filename.c_str(), "r");
    string contents;
    if (fp)
    {
      std::fseek(fp, 0, SEEK_END);
      contents.resize(std::ftell(fp));
      std::rewind(fp);
      std::fread(&contents[0], 1, contents.size(), fp);
      std::fclose(fp);
    } else {
      throw std::runtime_error("Error: could not open " + config_filename + " for reading.");
    }

    config = cJSON_Parse(contents.c_str());
    if (!config) {
      fprintf(stderr, "Error: could not create config cJSON object\n");
      throw std::runtime_error("Error: could not create config cJSON object");
    }

    j_base_url = cJSON_GetObjectItemCaseSensitive(config, "base_url");
    if (cJSON_IsString(j_base_url) && (j_base_url->valuestring != NULL))
    {
        base_url = j_base_url->valuestring;
        cout << "read_json_config_file: base_url = " << base_url << endl;
    } else {
      throw std::runtime_error("Error: could not parse base_url from " + config_filename);
    }

    j_api_key = cJSON_GetObjectItemCaseSensitive(config, "api_key");
    if (cJSON_IsString(j_api_key) && (j_api_key->valuestring != NULL))
    {
        api_key = j_api_key->valuestring;
        cout << "read_json_config_file: api_key = " << api_key << endl;
    } else {
      throw std::runtime_error("Error: could not parse api_key from " + config_filename);
    }

    j_model_id = cJSON_GetObjectItemCaseSensitive(config, "model_id");
    if (cJSON_IsString(j_model_id) && (j_model_id->valuestring != NULL))
    {
        model_id = j_model_id->valuestring;
        cout << "read_json_config_file: model_id = " << model_id << endl;
    } else {
      throw std::runtime_error("Error: could not parse model_id from " + config_filename);
    }

    j_model_version = cJSON_GetObjectItemCaseSensitive(config, "model_version");
    if (cJSON_IsString(j_model_version) && (j_model_version->valuestring != NULL))
    {
        model_version = j_model_version->valuestring;
        cout << "read_json_config_file: model_version = " << model_version << endl;
    } else {
      throw std::runtime_error("Error: could not parse model_version from " + config_filename);
    }

    j_output_dir = cJSON_GetObjectItemCaseSensitive(config, "output_dir");
    if (cJSON_IsString(j_output_dir) && (j_output_dir->valuestring != NULL))
    {
        output_dir = j_output_dir->valuestring;
        cout << "read_json_config_file: output_dir = " << output_dir << endl;
    } else {
      throw std::runtime_error("Error: could not parse output_dir from " + config_filename);
    }

    j_print_debug = cJSON_GetObjectItemCaseSensitive(config, "print_debug");
    if (cJSON_IsBool(j_print_debug))
    {
      if (cJSON_IsTrue(j_print_debug)) {
        print_debug = true;
      } else {
        print_debug = false;
      }
      cout << "read_json_config_file: print_debug = " << print_debug << endl;
    } else {
      throw std::runtime_error("Error: could not parse print_debug from " + config_filename);
    }

    j_save_video_file = cJSON_GetObjectItemCaseSensitive(config, "save_video_file");
    if (cJSON_IsBool(j_save_video_file))
    {
      if (cJSON_IsTrue(j_save_video_file)) {
        save_video_file = true;
      } else {
        save_video_file = false;
      }
      cout << "read_json_config_file: save_video_file = " << save_video_file << endl;
    } else {
      throw std::runtime_error("Error: could not parse save_video_file from " + config_filename);
    }

    j_video_max_seconds = cJSON_GetObjectItemCaseSensitive(config, "video_max_seconds");
    if (cJSON_IsNumber(j_video_max_seconds))
    {
        video_max_seconds = j_video_max_seconds->valueint;
        cout << "read_json_config_file: video_max_seconds = " << video_max_seconds << endl;
    } else {
      throw std::runtime_error("Error: could not parse video_max_seconds from " + config_filename);
    }

    j_frames_to_skip = cJSON_GetObjectItemCaseSensitive(config, "frames_to_skip");
    if (cJSON_IsNumber(j_frames_to_skip))
    {
        frames_to_skip = j_frames_to_skip->valueint;
        cout << "read_json_config_file: frames_to_skip = " << frames_to_skip << endl;
    } else {
      throw std::runtime_error("Error: could not parse frames_to_skip from " + config_filename);
    }

    j_save_I_frames = cJSON_GetObjectItemCaseSensitive(config, "save_I_frames");
    if (cJSON_IsBool(j_save_I_frames))
    {
      if (cJSON_IsTrue(j_save_I_frames)) {
        save_I_frames = true;
      } else {
        save_I_frames = false;
      }
      cout << "read_json_config_file: save_I_frames = " << save_I_frames << endl;
    } else {
      throw std::runtime_error("Error: could not parse save_I_frames from " + config_filename);
    }

    j_jpeg_quality = cJSON_GetObjectItemCaseSensitive(config, "jpeg_quality");
    if (cJSON_IsNumber(j_jpeg_quality))
    {
        jpeg_quality = j_jpeg_quality->valueint;
        cout << "read_json_config_file: jpeg_quality = " << jpeg_quality << endl;
    } else {
      throw std::runtime_error("Error: could not parse jpeg_quality from " + config_filename);
    }

    j_upload = cJSON_GetObjectItemCaseSensitive(config, "upload");
    if (cJSON_IsBool(j_upload))
    {
      if (cJSON_IsTrue(j_upload)) {
        upload = true;
      } else {
        upload = false;
      }
      cout << "read_json_config_file: upload = " << upload << endl;
    } else {
      throw std::runtime_error("Error: could not parse upload from " + config_filename);
    }

    j_stream_url = cJSON_GetObjectItemCaseSensitive(config, "stream_url");
    if (cJSON_IsString(j_stream_url) && (j_stream_url->valuestring != NULL))
    {
        stream_url = j_stream_url->valuestring;
        cout << "read_json_config_file: stream_url = " << stream_url << endl;
    } else {
      throw std::runtime_error("Error: could not parse stream_url from " + config_filename);
    }

    j_stream_name = cJSON_GetObjectItemCaseSensitive(config, "stream_name");
    if (cJSON_IsString(j_stream_name) && (j_stream_name->valuestring != NULL))
    {
        stream_name = j_stream_name->valuestring;
        cout << "read_json_config_file: stream_name = " << stream_name << endl;
    } else {
      throw std::runtime_error("Error: could not parse stream_url from " + config_filename);
    }

    j_stream_predict = cJSON_GetObjectItemCaseSensitive(config, "stream_predict");
    if (cJSON_IsBool(j_stream_predict))
    {
      if (cJSON_IsTrue(j_stream_predict)) {
        stream_predict = true;
      } else {
        stream_predict = false;
      }
      cout << "read_json_config_file: stream_predict = " << stream_predict << endl;
    } else {
      throw std::runtime_error("Error: could not parse stream_predict from " + config_filename);
    }

    j_metadata_structure = cJSON_GetObjectItemCaseSensitive(config, "metadata_structure");
    if (cJSON_IsString(j_metadata_structure) && (j_metadata_structure->valuestring != NULL))
    {
        metadata_structure = j_metadata_structure->valuestring;
        cout << "read_json_config_file: metadata_structure = " << metadata_structure << endl;
    } else {
      throw std::runtime_error("Error: could not parse metadata_structure from " + config_filename);
    }

    char *configJson = cJSON_Print(config);
    if(!configJson) {
      throw std::runtime_error("Error: cJSON_Print failed.");
    }
  } catch(const std::exception& e) {
    logging(e.what());
    status = false;
  } 
  return status;
}

/*
* JSON configuration file format

{
   "api_key": "4a5f25ecc48047ad8fb1d33ca687082e",
   "frames_to_skip": 1,
   "jpeg_quality": 75,
   "save_I_frames", false,
   "output_dir": "/my/output/dir",
   "print_debug": false,
   "save_video_file": true,
   "video_max_seconds": 3600,
   "upload": false,
   "metadata_structure": {
      "my interesting thing 1": "value",
      "key2": "value2"
    }
}
*/
bool Configuration_File::write_json_config_file()
{
  bool status = true;
  
  cJSON *j_base_url = NULL;
  cJSON *j_api_key = NULL;
  cJSON *j_model_id = NULL;
  cJSON *j_model_version = NULL;
  cJSON *j_frames_to_skip = NULL;
  cJSON *j_jpeg_quality = NULL;
  cJSON *j_save_I_frames = NULL;
  cJSON *j_output_dir = NULL;
  cJSON *j_print_debug = NULL;
  cJSON *j_save_video_file = NULL;    
  cJSON *j_upload = NULL;
  cJSON *j_video_max_seconds = NULL;
  cJSON *j_stream_url = NULL;
  cJSON *j_stream_name = NULL;
  cJSON *j_stream_predict = NULL;
  cJSON *j_metadata_structure = NULL;
  cJSON *config = NULL;

  try {
    config = cJSON_CreateObject();
    if (!config) {
      fprintf(stderr, "Error: could not create config cJSON object\n");
      throw std::runtime_error("Error: could not create config cJSON object");
    }

    j_base_url = cJSON_CreateObject();
    if (!j_base_url) {
      throw std::runtime_error("Error: could not create j_api_key cJSON object");
    }
    j_base_url = cJSON_CreateString(base_url.c_str());
    cJSON_AddItemToObject(config, "base_url", j_base_url);

    j_api_key = cJSON_CreateObject();
    if (!j_api_key) {
      throw std::runtime_error("Error: could not create j_api_key cJSON object");
    }
    j_api_key = cJSON_CreateString(api_key.c_str());
    cJSON_AddItemToObject(config, "api_key", j_api_key);

    j_model_id = cJSON_CreateObject();
    if (!j_model_id) {
      throw std::runtime_error("Error: could not create j_model_id cJSON object");
    }
    j_model_id = cJSON_CreateString(model_id.c_str());
    cJSON_AddItemToObject(config, "model_id", j_model_id);

    j_model_version = cJSON_CreateObject();
    if (!j_model_version) {
      throw std::runtime_error("Error: could not create j_model_version cJSON object");
    }
    j_model_version = cJSON_CreateString(model_version.c_str());
    cJSON_AddItemToObject(config, "model_version", j_model_version);

    j_output_dir = cJSON_CreateObject();
    if (!j_output_dir) {
      throw std::runtime_error("Error: could not create j_output_dir cJSON object");
    }
    j_output_dir = cJSON_CreateString(output_dir.c_str());
    cJSON_AddItemToObject(config, "output_dir", j_output_dir);

    j_print_debug = cJSON_CreateObject();
    if (!j_print_debug) {
      throw std::runtime_error("Error: could not create j_print_debug cJSON object");
    }
    j_print_debug = cJSON_CreateBool(print_debug);
    cJSON_AddItemToObject(config, "print_debug", j_print_debug);

    j_save_video_file = cJSON_CreateObject();
    if (!j_save_video_file) {
      throw std::runtime_error("Error: could not create j_save_video_file cJSON object");
    }
    j_save_video_file = cJSON_CreateBool(save_video_file);
    cJSON_AddItemToObject(config, "save_video_file", j_save_video_file);

    j_video_max_seconds = cJSON_CreateObject();
    if (!j_video_max_seconds) {
      throw std::runtime_error("Error: could not create j_video_max_seconds cJSON object");
    }
    j_video_max_seconds = cJSON_CreateNumber(video_max_seconds);
    cJSON_AddItemToObject(config, "video_max_seconds", j_video_max_seconds);

    j_frames_to_skip = cJSON_CreateObject();
    if (!j_frames_to_skip) {
      throw std::runtime_error("Error: could not create j_frames_to_skip cJSON object");
    }
    j_frames_to_skip = cJSON_CreateNumber(frames_to_skip);
    cJSON_AddItemToObject(config, "frames_to_skip", j_frames_to_skip);

    j_save_I_frames = cJSON_CreateObject();
    if (!j_save_I_frames) {
      throw std::runtime_error("Error: could not create j_save_I_frames cJSON object");
    }
    j_save_I_frames = cJSON_CreateBool(save_I_frames);
    cJSON_AddItemToObject(config, "save_I_frames", j_save_I_frames);

    j_jpeg_quality = cJSON_CreateObject();
    if (!j_jpeg_quality) {
      throw std::runtime_error("Error: could not create j_jpeg_quality cJSON object");
    }
    j_jpeg_quality = cJSON_CreateNumber(jpeg_quality);
    cJSON_AddItemToObject(config, "jpeg_quality", j_jpeg_quality);

    j_upload = cJSON_CreateObject();
    if (!j_upload) {
      throw std::runtime_error("Error: could not create j_upload cJSON object");
    }
    j_upload = cJSON_CreateBool(upload);
    cJSON_AddItemToObject(config, "upload", j_upload);

    j_stream_url = cJSON_CreateObject();
    if (!j_stream_url) {
      throw std::runtime_error("Error: could not create j_stream_url cJSON object");
    }
    j_stream_url = cJSON_CreateString(stream_url.c_str());
    cJSON_AddItemToObject(config, "stream_url", j_stream_url);

    j_stream_name = cJSON_CreateObject();
    if (!j_stream_name) {
      throw std::runtime_error("Error: could not create j_stream_name cJSON object");
    }
    j_stream_name = cJSON_CreateString(stream_name.c_str());
    cJSON_AddItemToObject(config, "stream_name", j_stream_name);

    j_stream_predict = cJSON_CreateObject();
    if (!j_stream_predict) {
      throw std::runtime_error("Error: could not create j_stream_predict cJSON object");
    }
    j_stream_predict = cJSON_CreateBool(stream_predict);
    cJSON_AddItemToObject(config, "stream_predict", j_stream_predict);

    j_metadata_structure = cJSON_CreateObject();
    if (!j_metadata_structure) {
      throw std::runtime_error("Error: could not create j_metadata_structure cJSON object");
    }
    j_metadata_structure = cJSON_CreateString(metadata_structure.c_str());
    cJSON_AddItemToObject(config, "metadata_structure", j_metadata_structure);

    char *configJson = cJSON_Print(config);
    if(!configJson) {
      throw std::runtime_error("Error: cJSON_Print failed.");
    }

    // Write configuration file.
    FILE *fp = fopen(config_filename.c_str(), "w");
    fwrite(configJson, sizeof(char), strlen(configJson), fp);
    fclose(fp);
    free(configJson);

  } catch(const std::exception& e) {
    logging(e.what());
    status = false;
  } 
  return status;
}
