/*
 * http://ffmpeg.org/doxygen/trunk/index.html
 *
 * Main components:
 *
 * Format (Container) - a wrapper, providing sync, metadata and muxing for the streams.
 * Stream - a continuous stream (audio or video) of data over time.
 * Codec - defines how data are enCOded (from Frame to Packet)
 *        and DECoded (from Packet to Frame).
 * Packet - are the data (kind of slices of the stream data) to be decoded as raw frames.
 * Frame - a decoded raw frame (to be encoded or filtered).
 */
#ifndef VIDEO_CAPTURE_H
#define VIDEO_CAPTURE_H

#ifdef __cplusplus
extern "C" {
#endif  
  #include <libavcodec/avcodec.h>
  #include <libavformat/avformat.h>
  #include <libswscale/swscale.h>
  #include <turbojpeg.h>
#ifdef __cplusplus
}
#endif

// C++ includes
#include <map>
#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <semaphore.h>

// Local includes
#include "Api.h"
//#include "Configuration_File.h"

class Video_Capture {
public:

  // indicates whether to capture and predict, or capture only.
  enum CaptureType {CAPTURE_PREDICT, CAPTURE};

  Video_Capture(Configuration_File &c, Video_Capture::CaptureType ct);
  ~Video_Capture();

  void cleanup();
  int decode_video();
  // decode packets into frames
  int decode_packet(AVPacket *pPacket, AVCodecContext *pCodecContext, AVFrame *pFrame, 
                          int &framesSkipped, int frameInterval, bool I_frames);

  // handling jpg files
  void get_jpg_files_in_output_dir(std::vector<std::string> &jpgFiles);
  static void remove_jpg_files();

  // opening and closing video output files
  void close_video_out_file_and_stream();
  int init_video_out_file_and_stream(AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, 
                                  const std::string &outFilename, int video_stream_index);
  bool new_video_out_file(AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, 
                                                  int video_stream_index, bool videoFileExists);

  // save a frame into a .pgm file
  int write_jpeg(std::string &imageFileName, AVFrame *pFrame, int frameNumber);
  void write_jpeg_for_predict(AVFrame *pFrame, int frame_number);
  void read_frame_pts_file_to_map();

  // uploading and predicting on images
  static void run_predict();
  void run_upload_and_predict();

  // image_size_file.json
  bool read_image_size_file();
  bool write_image_size_file(int width, int height);

  AVFormatContext *pInFormatContext;
  AVPacket *pPacket;
  AVCodecContext *pCodecContext;
  AVFrame *pFrame;
  AVFormatContext *pOutFormatContext;
  AVStream *outStream;

  CaptureType captureType;
  std::string streamName;   // name of stream / camera which will be prefix for output file name

  static std::string imageToUpload;
  static std::queue<std::string> imageQueue;
  int imageWidth;
  int imageHeight;

  Configuration_File &config;
  static Api api;
  static bool upload;
  static std::string output_dir;

  // Thread variables
  static std::mutex predictMutex;
  static std::thread predictThread;
  static bool threadRunning;
  static bool predicting;
  static sem_t semDecode;  // semaphore to allow decode to run
  static sem_t semPredict;  // semaphore to allow predict to run

  bool stopDecoding;
};

#endif // VIDEO_CAPTURE_H
