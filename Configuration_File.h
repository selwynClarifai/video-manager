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
    Configuration_File();
    ~Configuration_File();
    bool write_json_config_file();
    bool read_json_config_file();
    bool found_config_file();
    void write_metadata_from_config();

    std::string base_url;
    std::string api_key;
    std::string model_id;
    std::string model_version;
    int frames_to_skip;
    int jpeg_quality;
    std::string output_dir;
    bool imageSizeWritten;
    bool save_I_frames;
    bool save_video_file;
    bool print_debug;
    bool upload;
    unsigned long video_max_seconds;   // max number of seconds for video before creating new file
    std::string metadata_structure;      
    std::string authorizationHeader;
 
};

#endif // CONFIGURATION_FILE_H