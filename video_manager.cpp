#include "video_manager.h"

using namespace std;

// Global static video_manager, that can be called 
// from signal_callback_handler
video_manager vm;

video_manager::video_manager()
{
  pVideoCapPredict = NULL;
}

video_manager::~video_manager()
{
  cleanup_video_capture();
}

void video_manager::set_configuration_filename(const std::string conf_file)
{
  configuration_filename = conf_file;
}

void video_manager::cleanup_video_capture()
{
  if (pVideoCapPredict) {
    pVideoCapPredict->stopDecoding = true;
    cout << "deleting pVideoCapPredict" << endl;
    delete pVideoCapPredict;
    pVideoCapPredict = NULL;
  }
}

int video_manager::run()
{
  Configuration_File config(configuration_filename);

  // the video source to capture and predict on
  pVideoCapPredict = new Video_Capture(config, Video_Capture::CAPTURE_PREDICT);
  cout << "video capture and predict" << endl;

  int status = 0;
  if (config.upload) {
    cout << "UPLOADING AND PREDICTING" << endl;
    pVideoCapPredict->read_image_size_file();
    pVideoCapPredict->read_frame_pts_file_to_map();
  }
  status = pVideoCapPredict->decode_video();

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
    printf("You need to specify a configuration file.\n");
    return -1;
  }
  printf("Configuration file = %s\n", argv[1]);
  
  // Register signal and signal handler for ctrl-c
  signal(SIGINT, signal_callback_handler);

  vm.set_configuration_filename(argv[1]);
  vm.run();

  return 1;
}
 
