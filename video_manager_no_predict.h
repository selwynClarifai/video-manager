#ifndef VIDEO_MANAGER_NO_PREDICT_H
#define VIDEO_MANAGER_NO_PREDICT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h> // for getopt

// C++ includes
#include <string>
#include <sstream>
#include <signal.h>
#include <iostream>
#include <thread>

// Local includes
#include "Video_Capture.h"
#include "Configuration_File.h"

class video_manager_no_predict {
    public:
    video_manager_no_predict();
    ~video_manager_no_predict();
    int run();
    void set_configuration_filename(const std::string conf_file);
    void cleanup_video_capture();
    static void video_capture_run();

    std::string configuration_filename;

    // the video source to capture and predict on
    Video_Capture *pVideoCap;
};

#endif  //VIDEO_MANAGER_NO_PREDICT_H