#ifndef CONFIGURATION_FILE_H
#define CONFIGURATION_FILE_H

#ifdef __cplusplus
extern "C" {
#endif  
  #include "cJSON.h"
#ifdef __cplusplus
}
#endif
#include <string>

// Configuration file functions
class Configuration_File {
    public:
    Configuration_File(const std::string &conf_file);
    ~Configuration_File();
    bool write_json_config_file();
    bool read_json_config_file();
    bool found_config_file();
    void write_metadata_from_config();

    std::string authorizationHeader;

    // Configuration file name
    std::string config_filename;

    // Configuration file parameters
    std::string base_url;
    std::string api_key;
    std::string model_id;
    std::string model_version;
    int frames_to_skip;
    int jpeg_quality;
    std::string output_dir;
    bool aip_proto;
    int server_port;  // GRPC server port
    bool imageSizeWritten;
    bool save_I_frames;
    bool save_jpeg;
    bool save_video_file;
    bool print_debug;
    bool upload;
    std::string upload_file;
    unsigned long video_max_seconds;   // max number of seconds for video before creating new file
    std::string metadata_structure;      
 
    // Streams to be recorded
    std::string stream_url;   // URL of stream to capture and predict on
    std::string stream_name;  // Name of stream to capture and predict on (output file prefix)
    bool stream_predict;      // set to true to do predicts on stream
};

#endif // CONFIGURATION_FILE_H