/*
 * http://ffmpeg.org/doxygen/trunk/index.html
 *
 * Main components
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
#include <string>
#include <thread>
#include <mutex>

// Local includes
#include "Api.h"
#include "Configuration_File.h"

class Video_Capture {
public:
    Video_Capture(Configuration_File &c);
    ~Video_Capture();

    void cleanup();
    void close_video_out_file();
    int decode_video(char *videoSource, int frameInterval, bool saveVideo, bool I_frames);
    // decode packets into frames
    int decode_packet(AVPacket *pPacket, AVCodecContext *pCodecContext, AVFrame *pFrame, 
                            int &framesSkipped, int frameInterval, bool I_frames);
    void get_jpg_files_in_output_dir(std::vector<std::string> &jpgFiles);
    int open_video_out_file_and_stream(AVFormatContext *pOutFormatContext, AVFormatContext *pInFormatContext, 
                                    AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, 
                                    const std::string &outFilename, int video_stream_index);
    // save a frame into a .pgm file
    int write_jpeg(std::string &imageFileName, AVFrame *pFrame, int frameNumber);
    void read_frame_pts_file_to_map();

    // uploading and predicting on images
    static void run_predict();
    void run_upload_and_predict();

    // image_size_file.json
    bool read_image_size_file();
    bool write_image_size_file(int width, int height);

    AVFormatContext *pInFormatContext = NULL;
    AVPacket *pPacket = NULL;
    AVCodecContext *pCodecContext = NULL;
    AVFrame *pFrame = NULL;
    AVFormatContext *pOutFormatContext = NULL;

    static std::string imageToUpload;
    int imageWidth = 0;
    int imageHeight = 0;

    Configuration_File &config;
    static Api api;

    // Thread variables
    static std::mutex predictMutex;
    std::thread predictThread;
    static bool threadRunning;
    static bool predicting;

};

#endif // VIDEO_CAPTURE_H