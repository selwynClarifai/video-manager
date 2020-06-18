#include "video_manager_no_predict.h"

using namespace std;

// Global static video_manager, that can be called 
// from signal_callback_handler
video_manager_no_predict vm;

video_manager_no_predict::video_manager_no_predict()
{
  pVideoCap = NULL;
}

video_manager_no_predict::~video_manager_no_predict()
{
  cleanup_video_capture();
}

void video_manager_no_predict::set_configuration_filename(const std::string conf_file)
{
  configuration_filename = conf_file;
}

void video_manager_no_predict::cleanup_video_capture()
{
  if (pVideoCap) {
    pVideoCap->stopDecoding = true;
    cout << "deleting pVideoCap" << endl;
    delete pVideoCap;
    pVideoCap = NULL;
  }
}

int video_manager_no_predict::run()
{
  Configuration_File config(configuration_filename);

  // the video source to capture and predict on
  pVideoCap = new Video_Capture(config, Video_Capture::CAPTURE);
  cout << "video capture only" << endl;

  int status = 0;
  status = pVideoCap->decode_video();

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
 
