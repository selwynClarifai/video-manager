#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h> // for getopt

// C++ includes
#include <vector>
#include <string>
#include <sstream>
#include <signal.h>
#include <iostream>

// Local includes
#include "Video_Capture.h"
#include "Configuration_File.h"

class video_manager {
    public:
    video_manager();
    ~video_manager();
    int run(const char *videoSource);
    void cleanup_video_capture();

    Configuration_File config;
    Video_Capture *pVideoCap;
};
