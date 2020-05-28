
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
#include <chrono>
#include <ctime>

// Local includes
#include "Video_Capture.h"
#include "Utils.h"
#include "Configuration_File.h"

using namespace std;

/*
* Function declarations
*/
static void show_usage(std::string name);

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
   // Terminate program
   exit(signum);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("You need to specify a media file.\n");
    return -1;
  }

  printf("Video Source = %s\n", argv[1]);

  // Register signal and signal handler for ctrl-c
  signal(SIGINT, signal_callback_handler);

  Configuration_File config;
  Video_Capture videoCap(config);

  int status = 0;
  if (config.upload) {
    cout << "UPLOADING AND PREDICTING" << endl;
    videoCap.read_image_size_file();
    videoCap.read_frame_pts_file_to_map();
    videoCap.run_upload_and_predict();
  } else {
    int status = videoCap.decode_video(argv[1], config.frames_to_skip, config.save_video_file, config.save_I_frames);
  }
  return status;
}

static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> Video_Source\n"
              << "Video_Source can be a video file or RTSP URL"
              << "Options:\n"
              << "\t-h\t\tShow this help message\n"
              << "\t-d\t\tPrint debug messages\n"
              << "\t-f\t\tNumber of frames to skip. ('-f 10' will save every 10th frame)\n"
              << "\t-s\t\tSave video file to images directory.\n"
              << "\t-I\t\tSave only I-frames. (key frames)\n"
              << std::endl;
}

