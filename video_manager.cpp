#include "video_manager.h"

using namespace std;

// Global static video_manager, that can be called 
// from signal_callback_handler
video_manager vm;

video_manager::video_manager()
{
  Configuration_File config;
  pVideoCap = NULL;
  pVideoCap = new Video_Capture(config);
}

video_manager::~video_manager()
{
  cleanup_video_capture();
}

void video_manager::cleanup_video_capture()
{
  if (pVideoCap) {
    pVideoCap->stopDecoding = true;
    delete pVideoCap;
  }
}

int video_manager::run(const char *videoSource)
{
  int status = 0;
  if (config.upload) {
    cout << "UPLOADING AND PREDICTING" << endl;
    pVideoCap->read_image_size_file();
    pVideoCap->read_frame_pts_file_to_map();
    pVideoCap->run_upload_and_predict();
  } else {
    status = pVideoCap->decode_video(videoSource, config.frames_to_skip, config.save_video_file, config.save_I_frames);
  }

  return status;
}

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
   vm.cleanup_video_capture();

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

  vm.run(argv[1]);

  return 1;
}
 
