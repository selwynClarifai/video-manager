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

#ifdef __cplusplus
extern "C" {
#endif  
  #include <libavcodec/avcodec.h>
  #include <libavformat/avformat.h>
  #include <libswscale/swscale.h>
  #include <turbojpeg.h>
  #include <curl/curl.h>
  #include "cJSON.h"
  #include "base64.h"
#ifdef __cplusplus
}
#endif

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h> // for getopt
#include <dirent.h> // for directory access


// C++ includes
#include <vector>
#include <string>
#include <sstream>
#include <signal.h>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <ctime>
//#include "nlohmann/json.hpp"

using namespace std;
//using json = nlohmann::json;

/*
* Globals
*/
AVFormatContext *pInFormatContext = NULL;
AVPacket *pPacket = NULL;
AVCodecContext *pCodecContext = NULL;
AVFrame *pFrame = NULL;
AVFormatContext *pOutFormatContext = NULL;
std::mutex uploadMutex;
bool printDebug = false;
// Thread variables
thread predictThread;
bool threadRunning = true;
bool predicting = false;
string imageToUpload;
// Globals for configuration file
string api_key = "4a5f25ecc48047ad8fb1d33ca687082e";
int frames_to_skip = 1;
int jpeg_quality = 75;
string output_dir = "/files/images";
bool save_I_frames = false;
bool save_video_file = true;
bool print_debug = false;
bool upload = false;
string metadata_structure = "{\n \
      \"my interesting thing 1\": \"value\",\n \
      \"key2\": \"value2\"\n \
    }";

string authorizationHeader;

/*
* Function declarations
*/

// print out the steps and errors
static void logging(const char *fmt, ...);
static void cleanup();
static int decode_video(char *videoSource, int frameInterval, bool saveVideo, bool I_frames);
// decode packets into frames
static int decode_packet(AVPacket *pPacket, AVCodecContext *pCodecContext, AVFrame *pFrame, 
                          int &framesSkipped, int frameInterval, bool I_frames);
// save a frame into a .pgm file
static int write_jpeg(string &imageFileName, AVFrame *pFrame, int frameNumber);

// uploading and predicting on images
static void run_predict();
static void run_upload_and_predict();
static bool upload_image(string &imageID, const string &imageFileName);
static bool verify_upload_complete(const string &imageID);
static int predict_on_image(const string &imageFileName);
static bool create_json_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, cJSON *base64, 
                        const string &imageFileName);
static void encode_jpeg_to_base64(cJSON **base64_string, const char *jpeg_file_name);
static void encode_jpeg_to_base64_cpp(string &base64_string, const string &jpeg_file_name);
static bool parse_json_predict_response(string &responseParsed, const string &responseJson);
static bool parse_json_workflow_predict_response(string &responseParsed, const string &responseJson);
static bool parse_json_inputs_response(string &imageID, bool &uploadComplete, const string &responseJson);
static string make_csv_header();
static size_t write_predict_response(char *ptr, size_t size, size_t nmemb, void *responseJson);
static void show_usage(std::string name);
static int open_video_out_file_and_stream(AVFormatContext *pOutFormatContext, AVFormatContext *pInFormatContext, 
  AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, const string &outFilename, int video_stream_index);
static void close_video_out_file();
static void get_jpg_files_in_output_dir(std::vector<string> &jpgFiles);
static chrono::milliseconds millisecs_since_epoch();

// Configuration file functions
static bool write_json_config_file();
static bool read_json_config_file();
static bool found_config_file();
static void write_metadata_from_config();

// Define the function to be called when ctrl-c (SIGINT) is sent to process
void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << endl;
   cleanup();
   // Terminate program
   exit(signum);
}

int main(int argc, char *argv[])
{
  if (argc < 2) {
    printf("You need to specify a media file.\n");
    return -1;
  }
  int opt;

  while ((opt = getopt(argc, argv, "df:hIsu")) != -1) {
      switch (opt) {
      case 'h':
        show_usage(argv[0]);
        exit(EXIT_FAILURE);
        break;
      case 'd':
        printDebug = true;
        break;
      case 'f':
        frames_to_skip = atoi(optarg);
        cout << "Frame interval = " << frames_to_skip << endl;
        break;
      case 'I':
        save_I_frames = true;
        cout << "Save only I-Frames" << endl;
        break;
      case 's':
        save_video_file = true;
        break;
      case 'u':
        upload = true;
        break;
      default: /* '?' */
        show_usage(argv[0]);
        exit(EXIT_FAILURE);
      }
  }

  if (optind >= argc) {
      fprintf(stderr, "Expected argument after options\n");
      exit(EXIT_FAILURE);
  }
  printf("Video Source = %s\n", argv[optind]);

  // Configuration file
  if (!found_config_file()) {
    cout << "configuration file not found. Writing a default one." << endl;
    write_json_config_file();
  } else {
    cout << "configuration file found. Reading..." << endl;
    read_json_config_file();
  }
  authorizationHeader = "Authorization: Key " + api_key;

  write_metadata_from_config();

  int status = 0;
  if (upload) {
    cout << "UPLOADING AND PREDICTING" << endl;
    run_upload_and_predict();
  } else {
    int status = decode_video(argv[optind], frames_to_skip, save_video_file, save_I_frames);
  }
  return status;
}

static int decode_video(char *videoSource, int frameInterval, bool saveVideo, bool I_frames)
{
  /*
  * initialize thread to get predictions
  */
  predictThread = thread(run_predict);

  logging("initializing all the containers, codecs and protocols.");

   // Register signal and signal handler for ctrl-c
   signal(SIGINT, signal_callback_handler);

  // AVFormatContext holds the header information from the format (Container)
  // Allocating memory for this component
  // http://ffmpeg.org/doxygen/trunk/structAVFormatContext.html
  pInFormatContext = avformat_alloc_context();
  if (!pInFormatContext) {
    logging("ERROR could not allocate memory for Format Context");
    return -1;
  }

  logging("opening the input file (%s) and loading format (container) header", videoSource);
  // Open the file and read its header. The codecs are not opened.
  // The function arguments are:
  // AVFormatContext (the component we allocated memory for),
  // url (filename),
  // AVInputFormat (if you pass NULL it'll do the auto detect)
  // and AVDictionary (which are options to the demuxer)
  // http://ffmpeg.org/doxygen/trunk/group__lavf__decoding.html#ga31d601155e9035d5b0e7efedc894ee49
  if (avformat_open_input(&pInFormatContext, videoSource, NULL, NULL) != 0) {
    logging("ERROR could not open the file");
    return -1;
  }

  // now we have access to some information about our file
  // since we read its header we can say what format (container) it's
  // and some other information related to the format itself.
  logging("format %s, duration %lld us, bit_rate %lld", pInFormatContext->iformat->name, pInFormatContext->duration, pInFormatContext->bit_rate);

  logging("finding stream info from format");
  // read Packets from the Format to get stream information
  // this function populates pInFormatContext->streams
  // (of size equals to pInFormatContext->nb_streams)
  // the arguments are:
  // the AVFormatContext
  // and options contains options for codec corresponding to i-th stream.
  // On return each dictionary will be filled with options that were not found.
  // https://ffmpeg.org/doxygen/trunk/group__lavf__decoding.html#gad42172e27cddafb81096939783b157bb
  if (avformat_find_stream_info(pInFormatContext,  NULL) < 0) {
    logging("ERROR could not get the stream info");
    return -1;
  }

  // the component that knows how to enCOde and DECode the stream
  // it's the codec (audio or video)
  // http://ffmpeg.org/doxygen/trunk/structAVCodec.html
  AVCodec *pCodec = NULL;
  // this component describes the properties of a codec used by the stream i
  // https://ffmpeg.org/doxygen/trunk/structAVCodecParameters.html
  AVCodecParameters *pCodecParameters =  NULL;
  int video_stream_index = -1;
  AVStream *inStream = NULL;

  // loop though all the streams and print its main information
  for (int i = 0; i < pInFormatContext->nb_streams; i++)
  {
    AVCodecParameters *pLocalCodecParameters =  NULL;
    pLocalCodecParameters = pInFormatContext->streams[i]->codecpar;
    logging("AVStream->time_base before open coded %d/%d", pInFormatContext->streams[i]->time_base.num, pInFormatContext->streams[i]->time_base.den);
    logging("AVStream->r_frame_rate before open coded %d/%d", pInFormatContext->streams[i]->r_frame_rate.num, pInFormatContext->streams[i]->r_frame_rate.den);
    logging("AVStream->start_time %" PRId64, pInFormatContext->streams[i]->start_time);
    logging("AVStream->duration %" PRId64, pInFormatContext->streams[i]->duration);

    logging("finding the proper decoder (CODEC)");

    AVCodec *pLocalCodec = NULL;

    // finds the registered decoder for a codec ID
    // https://ffmpeg.org/doxygen/trunk/group__lavc__decoding.html#ga19a0ca553277f019dd5b0fec6e1f9dca
    pLocalCodec = avcodec_find_decoder(pLocalCodecParameters->codec_id);

    if (pLocalCodec==NULL) {
      logging("ERROR unsupported codec!");
      return -1;
    }

    // when the stream is a video we store its index, codec parameters and codec
    if (pLocalCodecParameters->codec_type == AVMEDIA_TYPE_VIDEO) {
      if (video_stream_index == -1) {
        video_stream_index = i;
        pCodec = pLocalCodec;
        pCodecParameters = pLocalCodecParameters;
        inStream = pInFormatContext->streams[i];
      }

      logging("Video Codec: resolution %d x %d", pLocalCodecParameters->width, pLocalCodecParameters->height);
    } else if (pLocalCodecParameters->codec_type == AVMEDIA_TYPE_AUDIO) {
      logging("Audio Codec: %d channels, sample rate %d", pLocalCodecParameters->channels, pLocalCodecParameters->sample_rate);
    }

    // print its name, id and bitrate
    logging("\tCodec %s ID %d bit_rate %lld", pLocalCodec->name, pLocalCodec->id, pLocalCodecParameters->bit_rate);
  }
  // https://ffmpeg.org/doxygen/trunk/structAVCodecContext.html
  pCodecContext = avcodec_alloc_context3(pCodec);
  if (!pCodecContext)
  {
    logging("failed to allocated memory for AVCodecContext");
    return -1;
  }

  /*
  * Create context for video output file. This is where RTSP stream will be saved.
  */
  pOutFormatContext = NULL;
  AVStream *outStream = NULL;
  if (saveVideo) {
    /*
    * To save RTSP, output container format should be mp4, ts, or mkv
    * https://video.stackexchange.com/questions/28446/recording-webcam-video-ffmpeg-error
    * 
    * This article is better. Solves the slow frame rate problem. was getting 2.4 fps instead of 15 fps.
    * Use .ts for accurate frame rate.
    * https://stackoverflow.com/questions/44593241/ffmpeg-segmentation-and-inaccurate-wrong-framerate
    */
    chrono::milliseconds msSinceEpoch = millisecs_since_epoch();
    string outFilename = output_dir + "/video_" + 
                std::to_string(chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count()) + ".ts";
    pOutFormatContext = avformat_alloc_context();

    int status = open_video_out_file_and_stream(pOutFormatContext, pInFormatContext, pCodecContext, 
                                                outStream, inStream, outFilename, video_stream_index);
    if (status == 0) {
      logging("Succesfully opened video output file %s", outFilename.c_str());
    } else {
      logging("Error opening video output file %s, error = %d", outFilename.c_str(), status);
      logging("Not saving video output");
      saveVideo = false;
    }
  }

  // Fill the codec context based on the values from the supplied codec parameters
  // https://ffmpeg.org/doxygen/trunk/group__lavc__core.html#gac7b282f51540ca7a99416a3ba6ee0d16
  if (avcodec_parameters_to_context(pCodecContext, pCodecParameters) < 0)
  {
    logging("failed to copy codec params to codec context");
    return -1;
  }

  // Initialize the AVCodecContext to use the given AVCodec.
  // https://ffmpeg.org/doxygen/trunk/group__lavc__core.html#ga11f785a188d7d9df71621001465b0f1d
  if (avcodec_open2(pCodecContext, pCodec, NULL) < 0)
  {
    logging("failed to open codec through avcodec_open2");
    return -1;
  }

  // https://ffmpeg.org/doxygen/trunk/structAVFrame.html
  pFrame = av_frame_alloc();
  if (!pFrame)
  {
    logging("failed to allocated memory for AVFrame");
    return -1;
  }
  // https://ffmpeg.org/doxygen/trunk/structAVPacket.html
  pPacket = av_packet_alloc();
  if (!pPacket)
  {
    logging("failed to allocated memory for AVPacket");
    return -1;
  }

  int response = 0;
  //int how_many_packets_to_process = 120;
  // fill the Packet with data from the Stream
  // https://ffmpeg.org/doxygen/trunk/group__lavf__decoding.html#ga4fdb3084415a82e3810de6ee60e46a61
  int framesSkipped = frameInterval;
  while (av_read_frame(pInFormatContext, pPacket) >= 0)
  {
    // if it's the video stream
    int ix = 0;
    if (pPacket->stream_index == video_stream_index) {
      if (printDebug) {
        logging("AVPacket->pts %" PRId64, pPacket->pts);
      }

      response = decode_packet(pPacket, pCodecContext, pFrame, framesSkipped, frameInterval, I_frames);
      if (response < 0)
        break;

      // Save to video output file
      if (saveVideo) {

        // set pPacket->stream_index to 0 because pOutFormatContext contains only one stream - for video.
        pPacket->stream_index = 0;
        int stat = av_interleaved_write_frame(pOutFormatContext, pPacket);
        //int stat = av_write_frame(pOutFormatContext, pPacket);
      }

      // stop it, otherwise we'll be saving hundreds of frames
      //if (--how_many_packets_to_process <= 0) break;
    }
    // https://ffmpeg.org/doxygen/trunk/group__lavc__packet.html#ga63d5a489b419bd5d45cfd09091cbcbc2
    av_packet_unref(pPacket);
  }

  // release all resources
  cleanup();
}

static void cleanup()
{
  logging("releasing all the resources");

  // Stop thread BEFORE libav resources
  threadRunning = false;
  predictThread.join();

  // release libav resources
  avformat_close_input(&pInFormatContext);
  av_packet_free(&pPacket);
  av_frame_free(&pFrame);
  avcodec_free_context(&pCodecContext);

  close_video_out_file();
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

static void logging(const char *fmt, ...)
{
    va_list args;
    fprintf( stderr, "LOG: " );
    va_start( args, fmt );
    vfprintf( stderr, fmt, args );
    va_end( args );
    fprintf( stderr, "\n" );
}

static int decode_packet(AVPacket *pPacket, AVCodecContext *pCodecContext, AVFrame *pFrame, int &framesSkipped, int frameInterval, bool I_frames)
{
  // Supply raw packet data as input to a decoder
  // https://ffmpeg.org/doxygen/trunk/group__lavc__decoding.html#ga58bc4bf1e0ac59e27362597e467efff3
  int response = avcodec_send_packet(pCodecContext, pPacket);

  if (response < 0) {
    // comment out when using C++: http://libav-users.943685.n4.nabble.com/Libav-user-g-4-7-2-fails-to-compile-av-err2str-td4656417.html
    //logging("Error while sending a packet to the decoder: %s", av_err2str(response));
    fprintf(stderr, "Error while sending a packet to the decoder: %d", response);
    return response;
  }

  while (response >= 0)
  {
    // Return decoded output data (into a frame) from a decoder
    // https://ffmpeg.org/doxygen/trunk/group__lavc__decoding.html#ga11e6542c4e66d3028668788a1a74217c
    response = avcodec_receive_frame(pCodecContext, pFrame);
    if (response == AVERROR(EAGAIN) || response == AVERROR_EOF) {
      break;
    } else if (response < 0) {
      // comment out when using C++: http://libav-users.943685.n4.nabble.com/Libav-user-g-4-7-2-fails-to-compile-av-err2str-td4656417.html
      //logging("Error while receiving a frame from the decoder: %s", av_err2str(response));
      fprintf(stderr, "Error while receiving a frame from the decoder: %d", response);
      return response;
    }

    if (response >= 0) {
      // print every 250th frame
      if (printDebug || pCodecContext->frame_number % 250 == 0) {
        logging(
            "Frame %d (type=%c, pix format=%d, size=%d bytes) pts %d key_frame %d [DTS %d]",
            pCodecContext->frame_number,
            av_get_picture_type_char(pFrame->pict_type),
            pFrame->format,
            pFrame->pkt_size,
            pFrame->pts,
            pFrame->key_frame,
            pFrame->coded_picture_number
        );
      }

      char frame_filename[1024];
      snprintf(frame_filename, sizeof(frame_filename), "%s-%d.pgm", "frame", pCodecContext->frame_number);
      //if (pFrame->pict_type == AV_PICTURE_TYPE_I) {
      if (I_frames && pFrame->pict_type == AV_PICTURE_TYPE_I ||
          !I_frames && framesSkipped == frameInterval) {
        framesSkipped = 1;
        string imageFilename;
        write_jpeg(imageFilename, pFrame, pCodecContext->frame_number);

        // Send image(s) to portal
        //send_image_to_portal(imageFilename);
       // Trigger run_upload
        if (uploadMutex.try_lock()) {
          predicting = true;
          imageToUpload = imageFilename;
          uploadMutex.unlock();
        }

      } else {
        framesSkipped++;
      }
    }
  }
  return 0;
}

// https://stackoverflow.com/questions/9094691/examples-or-tutorials-of-using-libjpeg-turbos-turbojpeg
static int write_jpeg(string &imageFileName, AVFrame *pFrame, int frameNumber)
{     
    tjhandle handle = tjInitCompress();

    if(handle == NULL)
    {
        const char *err = (const char *) tjGetErrorStr();
        //cerr << "TJ Error: " << err << " UNABLE TO INIT TJ Compressor Object\n";
        fprintf(stderr, "TJ Error: %s, UNABLE TO INIT TJ Compressor Object\n", err);
        return -1;
    }
    //int jpegQual =92;
    //int width = 128;
    //int height = 128;
    int nbands = 3;
    int flags = 0;
    unsigned char* jpegBuf = NULL;
    //int pitch = width * nbands;
    int pixelFormat = TJPF_GRAY;
    int jpegSubsamp = TJSAMP_GRAY;
    if(nbands == 3)
    {
        pixelFormat = TJPF_RGB;
        jpegSubsamp = TJSAMP_411;
    }

    unsigned long jpegSize = 0;
    int tj_stat = tjCompressFromYUVPlanes(handle, pFrame->data, pFrame->width, pFrame->linesize, 
                                  pFrame->height, TJSAMP_420, &jpegBuf, &jpegSize, jpeg_quality, flags);
    if(tj_stat != 0)
    {
        const char *err = (const char *) tjGetErrorStr();
        //cerr << "TurboJPEG Error: " << err << " UNABLE TO COMPRESS JPEG IMAGE\n";
        fprintf(stderr, "TurboJPEG Error: %s, UNABLE TO COMPRESS JPEG IMAGE\n", err);
        tjDestroy(handle);
        handle = NULL;
        return -1;

    }

    stringstream frame_filename;
    chrono::milliseconds msSinceEpoch = millisecs_since_epoch();
    frame_filename << output_dir + "/frame-" << 
              chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count() << ".jpg";
    FILE *file = fopen(frame_filename.str().c_str(), "wb");
    if (!file) {
        //cerr << "Could not open JPEG file: " << strerror(errno);
        fprintf(stderr, "Could not open JPEG file: %s\n", strerror(errno));
        return -1;
    }
    if (fwrite(jpegBuf, jpegSize, 1, file) < 1) {
        //cerr << "Could not write JPEG file: " << strerror(errno);
        fprintf(stderr, "Could not write JPEG file: %s\n", strerror(errno));
        return -1;
    }
    fclose(file);
    imageFileName = frame_filename.str();

    //write out the compress date to the image file
    //cleanup
    int tjstat = tjDestroy(handle); //should deallocate data buffer
    handle = 0;
}

static bool upload_image(string &imageID, const string &imageFileName)
{
  bool status = true;
  CURL *handle;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a handle handle */ 
  handle = curl_easy_init();
  if (handle) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    string uploadInputsURL = "https://api.clarifai.com/v2/inputs";
    curl_easy_setopt(handle, CURLOPT_URL, uploadInputsURL.c_str());

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader.c_str());    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    /* Now specify the POST data */ 
    char *inputsJson = NULL;
    cJSON *inputs = NULL;
    cJSON *input = NULL;
    cJSON *data = NULL;
    cJSON *image = NULL;
    cJSON *base64 = NULL;
    cJSON *root = NULL;
    try {
      root = cJSON_CreateObject();
      if (!root) {
        fprintf(stderr, "Error: could not create root cJSON object\n");
        throw "Error: could not create root cJSON object";
      }

      inputs = cJSON_CreateArray();
      if (!inputs) {
        //fprintf(stderr, "Error: could not create inputs cJSON object\n");
        throw "Error: could not create inputs cJSON object";
      }
      cJSON_AddItemToObject(root, "inputs", inputs);

      if (!create_json_inputs(inputs, input, data, image, base64, imageFileName)) {
        throw "Error: create_json_inputs failed.";
      }

      inputsJson = cJSON_PrintUnformatted(root);
      if(!inputsJson) {
        //fprintf(stderr, "Error: cJSON_PrintUnformatted failed.\n");
        throw "Error: cJSON_PrintUnformatted failed.";
      }

      curl_easy_setopt(handle, CURLOPT_POSTFIELDS, inputsJson);

/*
      string base64_string;
      encode_jpeg_to_base64_cpp(base64_string, imageFileName);
      json requestJ;
      requestJ = {
        { "inputs", {
          { "data", 
            { "image", {
              { "url", "https://samples.clarifai.com/metro-north.jpg" },
            }
            }
          },
        }},
      };
      cout << "JSON request: " << requestJ.dump() << endl;  
      */
      string response;

      // https://stackoverflow.com/questions/5701587/can-someone-explain-the-arguments-to-write-function-used-for-the-curl-option-cur
      curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
      curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_predict_response);
  
      /* Perform the request, res will get the return code */ 
      res = curl_easy_perform(handle);
      /* Check for errors */ 
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      }

      // Parse JSON predict response
      string imageID;
      bool uploadComplete = false;
      if (parse_json_inputs_response(imageID, uploadComplete, response)) {
        if (printDebug) {
          logging("parse_json_inputs_response: imageFileName = %s, imageID = %s, uploadComplete = %d", 
                                              imageFileName.c_str(), imageID.c_str(), uploadComplete);
        }
      } else {
        if (printDebug) {
          logging("parse_json_inputs_response: FAIL");
        }
      }
      status = uploadComplete;

    } catch (string &err) {
      if (printDebug) {
        logging(err.c_str());
        status = false;
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
      if (inputsJson) {
        free(inputsJson);
      }
  }
  curl_global_cleanup();
  return status;
}

static bool verify_upload_complete(const string &imageID)
{
  CURL *handle;
  CURLcode res;
  bool uploadComplete = false;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a handle handle */ 
  handle = curl_easy_init();
  if (handle) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    string uploadInputsURL = "https://api.clarifai.com/v2/inputs/" + imageID;
    curl_easy_setopt(handle, CURLOPT_URL, uploadInputsURL.c_str());

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader.c_str());    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    string response;

    // https://stackoverflow.com/questions/5701587/can-someone-explain-the-arguments-to-write-function-used-for-the-curl-option-cur
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_predict_response);

    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(handle);
    /* Check for errors */ 
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    // Parse JSON predict response
    string imageID;
    if (parse_json_inputs_response(imageID, uploadComplete, response)) {
      if (printDebug) {
        logging("parse_json_inputs_response: imageID = %s, uploadComplete = %d", imageID.c_str(), uploadComplete);
      }
    } else {
      if (printDebug) {
        logging("parse_json_inputs_response: FAIL");
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
  }
  curl_global_cleanup();
  return uploadComplete;
}

static int predict_on_image(const string &imageFileName)
{
  CURL *handle;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */ 
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a handle handle */ 
  handle = curl_easy_init();
  if (handle) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */ 
    //string workflowDetectConceptURL = "https://api.clarifai.com/v2/workflows/Detect-Concept/results";
    string generalDetectModelID = "cb649131aa72f86911815b0fe98dee55";
    string generalDetectModelVersion = "13c11ec702854e97a695ca2a0f809a95";
    string predictGeneralDetectURL = "https://api.clarifai.com/v2/models/" + 
                  generalDetectModelID + "/versions/" + generalDetectModelVersion + "/outputs";
    curl_easy_setopt(handle, CURLOPT_URL, predictGeneralDetectURL.c_str());

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, authorizationHeader.c_str());    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    /* Now specify the POST data */ 
    char *inputsJson = NULL;
    cJSON *inputs = NULL;
    cJSON *input = NULL;
    cJSON *data = NULL;
    cJSON *image = NULL;
    cJSON *base64 = NULL;
    cJSON *root = NULL;
    try {
      root = cJSON_CreateObject();
      if (!root) {
        fprintf(stderr, "Error: could not create root cJSON object\n");
        throw "Error: could not create root cJSON object";
      }

      inputs = cJSON_CreateArray();
      if (!inputs) {
        throw "Error: could not create inputs cJSON object";
      }
      cJSON_AddItemToObject(root, "inputs", inputs);

      if (!create_json_inputs(inputs, input, data, image, base64, imageFileName)) {
        throw "Error: create_json_inputs failed.";
      }

      inputsJson = cJSON_PrintUnformatted(root);
      if(!inputsJson) {
        throw "Error: cJSON_PrintUnformatted failed.";
      }

      curl_easy_setopt(handle, CURLOPT_POSTFIELDS, inputsJson);

      // Write response to output file
      string response;
      FILE *fp = NULL;
      size_t pos = imageFileName.find_last_of(".");

      if (pos != string::npos) {
        string outFile = imageFileName.substr(0, pos) + ".txt";
        fp  = fopen(outFile.c_str(), "w");

        // https://stackoverflow.com/questions/5701587/can-someone-explain-the-arguments-to-write-function-used-for-the-curl-option-cur
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &response);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_predict_response);
      } else {
        //fprintf(stderr, "Error: image file name %s does not have extension.\n", imageFileName);
        throw "Error: image file name " + imageFileName  + " does not have extension.";
      }
  
      /* Perform the request, res will get the return code */ 
      res = curl_easy_perform(handle);
      /* Check for errors */ 
      if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
      }

      // Parse JSON predict response
      string responseParsed;
      if (parse_json_predict_response(responseParsed, response)) {
        if (printDebug) {
          logging("parse_json_predict_response: SUCCESS");
        }
      } else {
        if (printDebug) {
          logging("parse_json_predict_response: FAIL");
        }
        responseParsed.append("parse_json_predict_response: FAIL\n");
      }
      if (pos != string::npos) {
        fwrite(responseParsed.c_str(), responseParsed.size(), 1, fp);
        fclose(fp);
      }
    } catch (string &err) {
      if (printDebug) {
        cerr << err <<  endl;
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
      if (inputsJson) {
        free(inputsJson);
      }
  }
  curl_global_cleanup();
  return 0;
}

static void run_predict()
{
  const auto wait_duration = std::chrono::milliseconds(10);
  bool _predicting = false;
  string _imageToUpload;

  while (threadRunning) {
    std::this_thread::sleep_for(wait_duration);

    uploadMutex.lock();
      _predicting = predicting;
      _imageToUpload = imageToUpload;
      predicting = false;
    uploadMutex.unlock();

    if (_predicting) {
      predict_on_image(_imageToUpload);
    }
  }
}

static void run_upload_and_predict()
{
  const auto wait_duration = std::chrono::milliseconds(10);
  bool _predicting = false;
  string _imageToUpload;

  vector<string> jpgFiles;
  get_jpg_files_in_output_dir(jpgFiles);

  auto startTime = chrono::steady_clock::now();

  for (auto const &jpg : jpgFiles) {
    string _imageID;
    bool uploadComplete = upload_image(_imageID, jpg);
    while (!uploadComplete) {
      std::this_thread::sleep_for(wait_duration);
      uploadComplete = verify_upload_complete(_imageID);
    }
    predict_on_image(jpg);
  }

  auto endTime = chrono::steady_clock::now();


  logging("Uploaded and predicted on %d images in %d seconds.", 
                    jpgFiles.size(), chrono::duration_cast<chrono::seconds>(endTime-startTime).count());
}


string make_csv_header()
{
  // Write CSV header
  string sepString = ", ";    // separator string for CSV file
  stringstream header;
  header << "BB_ID" << sepString;
  header << "BB_top_row" << sepString;
  header << "BB_left_col" << sepString;
  header << "BB_bot_row" << sepString;
  header << "BB_right_col" << sepString;
  header << "Concept_ID_1" << sepString;
  header << "Concept_Name_1" << sepString;
  header << "Concept_Prediction_1" << sepString;
  header << "Concept_ID_2" << sepString;
  header << "Concept_Name_2" << sepString;
  header << "Concept_Prediction_2" << sepString;
  header << "...\n";

  return header.str();
}

// Parse JSON predict response
static bool parse_json_predict_response(string &responseParsed, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *outputs = NULL;

  // Write CSV header
  string sepString = ", ";    // separator string for CSV file
  responseParsed.append(make_csv_header());

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw errString;
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: Predict response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw errString;
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_predict_response: Predict response failed. Response description = ";
        errString.append(description->valuestring);
        throw errString;
      }
    }

    /*
    * outputs
    */
    outputs = cJSON_GetObjectItemCaseSensitive(root, "outputs");
    cJSON * output = NULL;
    if (!outputs) {
      errString = "Error: parse_json_predict_response: Predict response failed. No outputs found.";
      throw errString;
    }
    
    /*
    * outputs->status
    */
    cJSON_ArrayForEach(output, outputs) {
      cJSON *status = NULL;
      status = cJSON_GetObjectItemCaseSensitive(output, "status");
      if (!status) {
        errString = "Error: parse_json_predict_response: Predict outputs status not found";
        throw errString;
      }

      cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: parse_json_predict_response: Predict outputs response failed. Outputs response Code = " + std::to_string(code->valueint);
        throw errString;
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_predict_response: Predict outputs response failed. Outputs response description = ";
        errString.append(description->valuestring);
        throw errString;
      }

      /*
      * outputs->data
      */
      cJSON *outputs_data = NULL;
      outputs_data = cJSON_GetObjectItemCaseSensitive(output, "data");
      if (!outputs_data) {
        errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data found.";
        throw errString;
      }

      /*
      * outputs->data->regions
      */
      cJSON *regions = NULL;
      regions = cJSON_GetObjectItemCaseSensitive(outputs_data, "regions");
      if (!regions) {
        errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions found.";
        throw errString;
      } 

      stringstream ssRegion;
      cJSON *region = NULL;
      cJSON_ArrayForEach(region, regions) {
        cJSON *id = cJSON_GetObjectItemCaseSensitive(region, "id");
        cJSON *region_info = cJSON_GetObjectItemCaseSensitive(region, "region_info");
        cJSON *bbox = NULL;
        bbox = cJSON_GetObjectItemCaseSensitive(region_info, "bounding_box");
        if (!cJSON_IsString(id)) {
          errString = "Error: parse_json_predict_response: Predict outputs response failed. No outputs->data->regions->bounding_box.";
          throw errString;
        }
        ssRegion << id->valuestring;
        if (bbox) {
          cJSON *top_row = cJSON_GetObjectItemCaseSensitive(bbox, "top_row");
          cJSON *left_col = cJSON_GetObjectItemCaseSensitive(bbox, "left_col");
          cJSON *bottom_row = cJSON_GetObjectItemCaseSensitive(bbox, "bottom_row");
          cJSON *right_col = cJSON_GetObjectItemCaseSensitive(bbox, "right_col");
          if ( !cJSON_IsNumber(top_row) || !cJSON_IsNumber(left_col) ||
              !cJSON_IsNumber(bottom_row) || !cJSON_IsNumber(right_col) ) {
            errString = "Error: parse_json_predict_response: Predict regions response failed. Could not parse bounding box";
            throw errString;
          }

          ssRegion << sepString << top_row->valuedouble << sepString << left_col->valuedouble;
          ssRegion << sepString << bottom_row->valuedouble << sepString << right_col->valuedouble;
        }

        /*
        * outputs->data->regions->data
        */
        cJSON *regions_data = NULL;
        regions_data = cJSON_GetObjectItemCaseSensitive(region, "data");
        if (!regions_data) {
          errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data found.";
          throw errString;
        }

        /*
        * outputs->data->regions->data->concepts
        */
        cJSON *concepts = NULL;
        concepts = cJSON_GetObjectItemCaseSensitive(regions_data, "concepts");
        if (!concepts) {
          errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts found.";
          throw errString;
        }

        cJSON *concept = NULL;
        cJSON_ArrayForEach(concept, concepts) {
          cJSON *id = NULL;
          id = cJSON_GetObjectItemCaseSensitive(concept, "id");
          if (!cJSON_IsString(id)) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts->id found.";
            throw errString;
          }

          ssRegion << sepString << id->valuestring;

          cJSON *name = NULL;
          name = cJSON_GetObjectItemCaseSensitive(concept, "name");
          if (!cJSON_IsString(name)) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts->name found.";
            throw errString;
          }

          ssRegion << sepString << name->valuestring;

          cJSON *value = NULL;
          value = cJSON_GetObjectItemCaseSensitive(concept, "value");
          if (!cJSON_IsNumber(value)) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data->concepts->value found.";
            throw errString;
          }

          ssRegion << sepString << value->valuedouble;
        }   // concepts

        responseParsed.append(ssRegion.str());
        responseParsed.append("\n");

        // reset to empty string
        ssRegion.str("");
        ssRegion.clear();
      }   // regions
    }   // outputs

  } catch (string &err) {
    logging(err.c_str());
    responseParsed.append(err);
    responseParsed.append("\n");
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

// Parse JSON workflow predict response
static bool parse_json_workflow_predict_response(string &responseParsed, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *outputs = NULL;

  // Write CSV header
  string sepString = ", ";    // separator string for CSV file
  responseParsed.append(make_csv_header());

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw errString;
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: Predict response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw errString;
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_workflow_predict_response: Predict response failed. Response description = ";
        errString.append(description->valuestring);
        throw errString;
      }
    }

    /*
    * results
    */
    results = cJSON_GetObjectItemCaseSensitive(root, "results");
    if (!results) {
      errString = "Error: parse_json_workflow_predict_response: Predict response failed. No results found.";
      throw errString;
    }

    cJSON * result = NULL;
    cJSON_ArrayForEach(result, results) {
      /*
      * results->outputs
      */
      outputs = cJSON_GetObjectItemCaseSensitive(result, "outputs");
      cJSON * output = NULL;
      if (!outputs) {
        errString = "Error: parse_json_workflow_predict_response: Predict response failed. No results->outputs found.";
        throw errString;
      }
      
      /*
      * results->outputs->status
      */
      cJSON_ArrayForEach(output, outputs) {
        cJSON *status = NULL;
        status = cJSON_GetObjectItemCaseSensitive(output, "status");
        if (!status) {
          errString = "Error: parse_json_workflow_predict_response: Predict outputs status not found";
          throw errString;
        }

        cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
        cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
        if (!cJSON_IsNumber(code) || code->valueint != 10000) {
          errString = "Error: parse_json_workflow_predict_response: Predict outputs response failed. Outputs response Code = " + std::to_string(code->valueint);
          throw errString;
        }

        if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
          errString = "Error: parse_json_workflow_predict_response: Predict outputs response failed. Outputs response description = ";
          errString.append(description->valuestring);
          throw errString;
        }

        /*
        * results->outputs->data
        */
        cJSON *outputs_data = NULL;
        outputs_data = cJSON_GetObjectItemCaseSensitive(output, "data");
        if (!outputs_data) {
          errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data found.";
          throw errString;
        }

        /*
        * results->outputs->data->regions
        */
        cJSON *regions = NULL;
        regions = cJSON_GetObjectItemCaseSensitive(outputs_data, "regions");
        if (!regions) {
          errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions found.";
          throw errString;
        } 

        stringstream ssRegion;
        cJSON *region = NULL;
        cJSON_ArrayForEach(region, regions) {
          cJSON *id = cJSON_GetObjectItemCaseSensitive(region, "id");
          cJSON *region_info = cJSON_GetObjectItemCaseSensitive(region, "region_info");
          cJSON *bbox = NULL;
          bbox = cJSON_GetObjectItemCaseSensitive(region_info, "bounding_box");
          if (!cJSON_IsString(id)) {
            errString = "Error: parse_json_workflow_predict_response: Predict outputs response failed. No outputs->data->regions->bounding_box.";
            throw errString;
          }
          ssRegion << id->valuestring;
          if (bbox) {
            cJSON *top_row = cJSON_GetObjectItemCaseSensitive(bbox, "top_row");
            cJSON *left_col = cJSON_GetObjectItemCaseSensitive(bbox, "left_col");
            cJSON *bottom_row = cJSON_GetObjectItemCaseSensitive(bbox, "bottom_row");
            cJSON *right_col = cJSON_GetObjectItemCaseSensitive(bbox, "right_col");
            if ( !cJSON_IsNumber(top_row) || !cJSON_IsNumber(left_col) ||
                !cJSON_IsNumber(bottom_row) || !cJSON_IsNumber(right_col) ) {
              errString = "Error: parse_json_workflow_predict_response: Predict regions response failed. Could not parse bounding box";
              throw errString;
            }

            ssRegion << sepString << top_row->valuedouble << sepString << left_col->valuedouble;
            ssRegion << sepString << bottom_row->valuedouble << sepString << right_col->valuedouble;
          }

          /*
          * results->outputs->data->regions->data
          */
          cJSON *regions_data = NULL;
          regions_data = cJSON_GetObjectItemCaseSensitive(region, "data");
          if (!regions_data) {
            errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data found.";
            throw errString;
          }

          /*
          * results->outputs->data->regions->data->concepts
          */
          cJSON *concepts = NULL;
          concepts = cJSON_GetObjectItemCaseSensitive(regions_data, "concepts");
          if (!concepts) {
            errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts found.";
            throw errString;
          }

          cJSON *concept = NULL;
          cJSON_ArrayForEach(concept, concepts) {
            cJSON *id = NULL;
            id = cJSON_GetObjectItemCaseSensitive(concept, "id");
            if (!cJSON_IsString(id)) {
              errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts->id found.";
              throw errString;
            }

            ssRegion << sepString << id->valuestring;

            cJSON *name = NULL;
            name = cJSON_GetObjectItemCaseSensitive(concept, "name");
            if (!cJSON_IsString(name)) {
              errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts->name found.";
              throw errString;
            }

            ssRegion << sepString << name->valuestring;

            cJSON *value = NULL;
            value = cJSON_GetObjectItemCaseSensitive(concept, "value");
            if (!cJSON_IsNumber(value)) {
              errString = "Error: parse_json_workflow_predict_response: Predict response failed. No outputs->data->regions->data->concepts->value found.";
              throw errString;
            }

            ssRegion << sepString << value->valuedouble;
          }   // concepts

          responseParsed.append(ssRegion.str());
          responseParsed.append("\n");

          // reset to empty string
          ssRegion.str("");
          ssRegion.clear();
        }   // regions
      }   // outputs
    }   // results



  } catch (string &err) {
    logging(err.c_str());
    responseParsed.append(err);
    responseParsed.append("\n");
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

// Parse JSON inputs response
static bool parse_json_inputs_response(string &imageID, bool &uploadComplete, const string &responseJson)
{
  string errString;
  bool parseStatus = true;
  cJSON *root = cJSON_Parse(responseJson.c_str());
  const cJSON *results = NULL;
  const cJSON *rootStatus = NULL;
  const cJSON *inputs = NULL;

  try {
    if (root == NULL)
    {
        const char *error_ptr = cJSON_GetErrorPtr();
        if (error_ptr != NULL)
        {
            errString = "Error before: ";
            errString.append(error_ptr);
            throw errString;
        }
    }

    rootStatus = cJSON_GetObjectItemCaseSensitive(root, "status");
    if (rootStatus) {
      cJSON *code = cJSON_GetObjectItemCaseSensitive(rootStatus, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(rootStatus, "description");
      if (!cJSON_IsNumber(code) || code->valueint != 10000) {
        errString = "Error: Predict response failed: ";
        errString.append(description->valuestring);
        errString.append(". Response Code = " + std::to_string(code->valueint));
        throw errString;
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_inputs_response: Predict response failed. Response description = ";
        errString.append(description->valuestring);
        throw errString;
      }
    }

    /*
    * inputs
    */
    inputs = cJSON_GetObjectItemCaseSensitive(root, "inputs");
    cJSON * input = NULL;
    if (!inputs) {
      errString = "Error: parse_json_inputs_response: Predict response failed. No inputs found.";
      throw errString;
    }
    
    /*
    * inputs->status
    */
    cJSON_ArrayForEach(input, inputs) {
      cJSON *id = NULL;
      id = cJSON_GetObjectItemCaseSensitive(input, "id");
      if (!id) {
        errString = "Error: parse_json_inputs_response: inputs id not found";
        throw errString;
      }
      imageID.assign(id->valuestring);

      cJSON *status = NULL;
      status = cJSON_GetObjectItemCaseSensitive(input, "status");
      if (!status) {
        errString = "Error: parse_json_inputs_response: inputs status not found";
        throw errString;
      }

      cJSON *code = cJSON_GetObjectItemCaseSensitive(status, "code");
      cJSON *description = cJSON_GetObjectItemCaseSensitive(status, "description");
      if (!cJSON_IsNumber(code)) {
        errString = "Error: parse_json_inputs_response:  inputs response failed.";
        throw errString;
      }
      uploadComplete = true;
      if (code->valueint != 30000) {
        uploadComplete = false;
      }
    }   // inputs

  } catch (string &err) {
    logging(err.c_str());
    parseStatus = false;
  }
  cJSON_Delete(root);

  return parseStatus;
}

static bool create_json_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, cJSON *base64, 
                        const string &imageFileName)
{
    /*
    * Add input images
    */
    input = cJSON_CreateObject();
    if (!input) {
      fprintf(stderr, "Error: could not create input cJSON object\n");
      return false;
    }
    cJSON_AddItemToArray(inputs, input);

    data = cJSON_CreateObject();
    if (!data) {
      fprintf(stderr, "Error: could not create data cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(input, "data", data);

    image = cJSON_CreateObject();
    if (!image) {
      fprintf(stderr, "Error: could not create image cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(data, "image", image);

    // assign encoded jpg string to base64 object
    encode_jpeg_to_base64(&base64, imageFileName.c_str());
    if (!base64) {
      fprintf(stderr, "Error: could not create base64 cJSON object\n");
      return false;
    }
    cJSON_AddItemToObject(image, "base64", base64);

    return true;
}

// Callback function to handle response from workflow predict request.
// https://stackoverflow.com/questions/9786150/save-curl-content-result-into-a-string-in-c
static size_t write_predict_response(char *ptr, size_t size, size_t nmemb, void *responseJson)
{
  size_t realSize = size * nmemb;
  ((std::string*)responseJson)->append((char*)ptr, realSize);

  return realSize;
}

// https://stackoverflow.com/questions/26175293/how-to-convert-image-to-base64-in-c
static void encode_jpeg_to_base64(cJSON **base64_string, const char *jpeg_file_name)
{
  FILE *file;
  unsigned char *jpeg64_buf = NULL;
  char *jpeg64_string = NULL;

  //Open file                                                                                                                                                                                                
  file = fopen(jpeg_file_name , "rb");
  if (!file) {
    {
      fprintf(stderr, "Unable to open file %s", jpeg_file_name);
      return;
    }
  }
 
  // Get file length                                                               
  fseek(file, 0, SEEK_END);
  long fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory
  jpeg64_buf=(unsigned char *)malloc(fileLen+1);
  if (!jpeg64_buf)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return;
    }

  //Read file contents into buffer                                                                                                                                                                           
  fread(jpeg64_buf, fileLen, 1, file);
  size_t output_length = 0;
  jpeg64_string = base64_encode(jpeg64_buf, (size_t)fileLen, &output_length);

  // Null-terminate jpeg64_string. Else cJSON_CreateString reads beyond the end.
  //jpeg64_string[output_length] = '\0';
  *base64_string = cJSON_CreateString(jpeg64_string);

  fclose(file);
  //insert_blob(jpeg64_buf);
  if (jpeg64_buf) {
    free(jpeg64_buf);
  }
  if (jpeg64_string) {
    free(jpeg64_string);
  }
}

// https://stackoverflow.com/questions/26175293/how-to-convert-image-to-base64-in-c
static void encode_jpeg_to_base64_cpp(string &base64_string, const string &jpeg_file_name)
{
  FILE *file;
  unsigned char *jpeg64_buf = NULL;
  char *jpeg64_string = NULL;

  //Open file                                                                                                                                                                                                
  file = fopen(jpeg_file_name.c_str() , "rb");
  if (!file) {
    {
      fprintf(stderr, "Unable to open file %s", jpeg_file_name.c_str());
      return;
    }
  }
 
  // Get file length                                                               
  fseek(file, 0, SEEK_END);
  long fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory
  jpeg64_buf=(unsigned char *)malloc(fileLen+1);
  if (!jpeg64_buf)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return;
    }

  //Read file contents into buffer                                                                                                                                                                           
  fread(jpeg64_buf, fileLen, 1, file);
  size_t output_length = 0;
  jpeg64_string = base64_encode(jpeg64_buf, (size_t)fileLen, &output_length);

  base64_string.assign(jpeg64_string);

  fclose(file);
  //insert_blob(jpeg64_buf);
  if (jpeg64_buf) {
    free(jpeg64_buf);
  }
  if (jpeg64_string) {
    free(jpeg64_string);
  }
}

// https://stackoverflow.com/questions/9251747/record-rtsp-stream-with-ffmpeg-libavformat
static int open_video_out_file_and_stream(AVFormatContext *pOutFormatContext, AVFormatContext *pInFormatContext, 
  AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, const string &outFilename, int video_stream_index)
{
  //open output file
  AVOutputFormat* fmt = av_guess_format(NULL, outFilename.c_str(), NULL);
  //pOutFormatContext = avformat_alloc_context();
  pOutFormatContext->oformat = fmt;
  int status = avio_open2(&pOutFormatContext->pb, outFilename.c_str(), AVIO_FLAG_WRITE,NULL,NULL);
  if (status != 0) {
    logging("Error: init_video_out_file: cannot open video output file %s. avio_open2 error=%d", 
          outFilename.c_str(), status);
  }
  // Create output stream
  //outStream = avformat_new_stream( ofcx, (AVCodec *) inCodecContext->codec );
  outStream = avformat_new_stream(pOutFormatContext, NULL);
  //avcodec_copy_context( outStream->codec, inCodecContext );
  //status = avcodec_parameters_to_context(outStream->codecpar, (*pInFormatContext)->streams[video_stream_index]->codecpar);
  status = avcodec_parameters_copy(outStream->codecpar, inStream->codecpar);

  outStream->sample_aspect_ratio.num = inCodecContext->sample_aspect_ratio.num;
  outStream->sample_aspect_ratio.den = inCodecContext->sample_aspect_ratio.den;

  // Assume r_frame_rate is accurate
  outStream->r_frame_rate = inStream->r_frame_rate;
  outStream->avg_frame_rate = outStream->r_frame_rate;
  outStream->time_base = av_inv_q( outStream->r_frame_rate );
  //outStream->codec->time_base = outStream->time_base;
  outStream->time_base = outStream->time_base;
  cout << "inCodecContext->bit_rate = " << inCodecContext->bit_rate;

  avformat_write_header( pOutFormatContext, NULL );

  snprintf( pOutFormatContext->filename, sizeof( pOutFormatContext->filename ), "%s", outFilename.c_str() );

  //start reading packets from stream and write them to file

  av_dump_format( pInFormatContext, 0, pInFormatContext->filename, 0 );
  av_dump_format( pOutFormatContext, 0, pOutFormatContext->filename, 1 );

  return status;
}

static void close_video_out_file()
{
  if (pOutFormatContext) {
    av_write_trailer(pOutFormatContext);
    avio_close(pOutFormatContext->pb);
    avformat_free_context(pOutFormatContext);
  }
}

// https://stackoverflow.com/questions/306533/how-do-i-get-a-list-of-files-in-a-directory-in-c
static void get_jpg_files_in_output_dir(std::vector<string> &jpgFiles)
{
  DIR *dpdf;
  struct dirent *epdf;

  dpdf = opendir(output_dir.c_str());
  if (dpdf != NULL){
    while (epdf = readdir(dpdf)){
        string fileName = epdf->d_name;
        if (fileName.find(".jpg") != string::npos) {
          string fullFileName = output_dir + "/" + fileName;
        jpgFiles.push_back(fullFileName);
        }
    }
  }
  closedir(dpdf);

} // GetFilesInDirectory

// Looks for config.json in exe directory 
static bool found_config_file()
{
  DIR *dpdf;
  struct dirent *epdf;
  bool found = false;

  dpdf = opendir("/files");
  if (dpdf != NULL){
    while (epdf = readdir(dpdf)){
      if (strcmp(epdf->d_name, "config.json") == 0) {
        found = true;
        break;
      }
    }
  }
  closedir(dpdf);

  return found;
} 

/*
* JSON configuration file format

{
   "api_key": "4a5f25ecc48047ad8fb1d33ca687082e",
   "frames_to_skip": 1,
   "jpeg_quality": 75,
   "save_I_frames", false,
   "output_dir": "/my/output/dir",
   "print_debug": false,
   "save_video_file": true,
   "upload": false,
   "metadata_structure": {
      "my interesting thing 1": "value",
      "key2": "value2"
    }
}
*/
static bool write_json_config_file()
{
  bool status = true;
  
  cJSON *j_api_key = NULL;
  cJSON *j_frames_to_skip = NULL;
  cJSON *j_jpeg_quality = NULL;
  cJSON *j_save_I_frames = NULL;
  cJSON *j_output_dir = NULL;
  cJSON *j_print_debug = NULL;
  cJSON *j_save_video_file = NULL;    
  cJSON *j_upload = NULL;
  cJSON *j_metadata_structure = NULL;
  cJSON *config = NULL;

  try {
    config = cJSON_CreateObject();
    if (!config) {
      fprintf(stderr, "Error: could not create config cJSON object\n");
      throw "Error: could not create config cJSON object";
    }

    j_api_key = cJSON_CreateObject();
    if (!j_api_key) {
      throw "Error: could not create j_api_key cJSON object";
    }
    j_api_key = cJSON_CreateString(api_key.c_str());
    cJSON_AddItemToObject(config, "api_key", j_api_key);

    j_frames_to_skip = cJSON_CreateObject();
    if (!j_frames_to_skip) {
      throw "Error: could not create j_frames_to_skip cJSON object";
    }
    j_frames_to_skip = cJSON_CreateNumber(frames_to_skip);
    cJSON_AddItemToObject(config, "frames_to_skip", j_frames_to_skip);

    j_jpeg_quality = cJSON_CreateObject();
    if (!j_jpeg_quality) {
      throw "Error: could not create j_jpeg_quality cJSON object";
    }
    j_jpeg_quality = cJSON_CreateNumber(jpeg_quality);
    cJSON_AddItemToObject(config, "jpeg_quality", j_jpeg_quality);

    j_save_I_frames = cJSON_CreateObject();
    if (!j_save_I_frames) {
      throw "Error: could not create j_save_I_frames cJSON object";
    }
    j_save_I_frames = cJSON_CreateBool(save_I_frames);
    cJSON_AddItemToObject(config, "save_I_frames", j_save_I_frames);

    j_output_dir = cJSON_CreateObject();
    if (!j_output_dir) {
      throw "Error: could not create j_output_dir cJSON object";
    }
    j_output_dir = cJSON_CreateString(output_dir.c_str());
    cJSON_AddItemToObject(config, "output_dir", j_output_dir);

    j_print_debug = cJSON_CreateObject();
    if (!j_print_debug) {
      throw "Error: could not create j_print_debug cJSON object";
    }
    j_print_debug = cJSON_CreateBool(print_debug);
    cJSON_AddItemToObject(config, "print_debug", j_print_debug);

    j_save_video_file = cJSON_CreateObject();
    if (!j_save_video_file) {
      throw "Error: could not create j_save_video_file cJSON object";
    }
    j_save_video_file = cJSON_CreateBool(save_video_file);
    cJSON_AddItemToObject(config, "save_video_file", j_save_video_file);

    j_upload = cJSON_CreateObject();
    if (!j_upload) {
      throw "Error: could not create j_upload cJSON object";
    }
    j_upload = cJSON_CreateBool(upload);
    cJSON_AddItemToObject(config, "upload", j_upload);

    j_metadata_structure = cJSON_CreateObject();
    if (!j_metadata_structure) {
      throw "Error: could not create j_metadata_structure cJSON object";
    }
    j_metadata_structure = cJSON_CreateString(metadata_structure.c_str());
    cJSON_AddItemToObject(config, "metadata_structure", j_metadata_structure);

    char *configJson = cJSON_Print(config);
    if(!configJson) {
      throw "Error: cJSON_Print failed.";
    }

    // Write configuration file.
    FILE *fp = fopen("../config.json", "w");
    fwrite(configJson, sizeof(char), strlen(configJson), fp);
    fclose(fp);
    free(configJson);

  } catch (string &err) {
    if (printDebug) {
      logging(err.c_str());
      status = false;
    }
  } 
  return status;
}

static bool read_json_config_file()
{
  bool status = true;
  
  cJSON *j_api_key = NULL;
  cJSON *j_frames_to_skip = NULL;
  cJSON *j_jpeg_quality = NULL;
  cJSON *j_save_I_frames = NULL;
  cJSON *j_output_dir = NULL;
  cJSON *j_print_debug = NULL;
  cJSON *j_save_video_file = NULL;    
  cJSON *j_upload = NULL;
  cJSON *j_metadata_structure = NULL;
  cJSON *config = NULL;

  try {

    // read config file
    FILE *fp = std::fopen("../config.json", "r");
    string contents;
    if (fp)
    {
      std::fseek(fp, 0, SEEK_END);
      contents.resize(std::ftell(fp));
      std::rewind(fp);
      std::fread(&contents[0], 1, contents.size(), fp);
      std::fclose(fp);
    } else {
      throw "Error: could not open config.json for reading.";
    }

    config = cJSON_Parse(contents.c_str());
    if (!config) {
      fprintf(stderr, "Error: could not create config cJSON object\n");
      throw "Error: could not create config cJSON object";
    }

    j_api_key = cJSON_GetObjectItemCaseSensitive(config, "api_key");
    if (cJSON_IsString(j_api_key) && (j_api_key->valuestring != NULL))
    {
        api_key = j_api_key->valuestring;
        cout << "read_json_config_file: api_key = " << api_key << endl;
    } else {
      throw "Error: could not parse api_key from config.json";
    }

    j_frames_to_skip = cJSON_GetObjectItemCaseSensitive(config, "frames_to_skip");
    if (cJSON_IsNumber(j_frames_to_skip))
    {
        frames_to_skip = j_frames_to_skip->valueint;
        cout << "read_json_config_file: frames_to_skip = " << frames_to_skip << endl;
    } else {
      throw "Error: could not parse frames_to_skip from config.json";
    }

    j_jpeg_quality = cJSON_GetObjectItemCaseSensitive(config, "jpeg_quality");
    if (cJSON_IsNumber(j_jpeg_quality))
    {
        jpeg_quality = j_jpeg_quality->valueint;
        cout << "read_json_config_file: jpeg_quality = " << jpeg_quality << endl;
    } else {
      throw "Error: could not parse jpeg_quality from config.json";
    }

    j_save_I_frames = cJSON_GetObjectItemCaseSensitive(config, "save_I_frames");
    if (cJSON_IsBool(j_save_I_frames))
    {
      if (cJSON_IsTrue(j_save_I_frames)) {
        save_I_frames = true;
      } else {
        save_I_frames = false;
      }
      cout << "read_json_config_file: save_I_frames = " << save_I_frames << endl;
    } else {
      throw "Error: could not parse save_I_frames from config.json";
    }

    j_output_dir = cJSON_GetObjectItemCaseSensitive(config, "output_dir");
    if (cJSON_IsString(j_output_dir) && (j_output_dir->valuestring != NULL))
    {
        output_dir = j_output_dir->valuestring;
        cout << "read_json_config_file: output_dir = " << output_dir << endl;
    } else {
      throw "Error: could not parse output_dir from config.json";
    }

    j_print_debug = cJSON_GetObjectItemCaseSensitive(config, "print_debug");
    if (cJSON_IsBool(j_print_debug))
    {
      if (cJSON_IsTrue(j_print_debug)) {
        print_debug = true;
      } else {
        print_debug = false;
      }
      cout << "read_json_config_file: print_debug = " << print_debug << endl;
    } else {
      throw "Error: could not parse print_debug from config.json";
    }

    j_save_video_file = cJSON_GetObjectItemCaseSensitive(config, "save_video_file");
    if (cJSON_IsBool(j_save_video_file))
    {
      if (cJSON_IsTrue(j_save_video_file)) {
        save_video_file = true;
      } else {
        save_video_file = false;
      }
      cout << "read_json_config_file: save_video_file = " << save_video_file << endl;
    } else {
      throw "Error: could not parse save_video_file from config.json";
    }

    j_upload = cJSON_GetObjectItemCaseSensitive(config, "upload");
    if (cJSON_IsBool(j_upload))
    {
      if (cJSON_IsTrue(j_upload)) {
        upload = true;
      } else {
        upload = false;
      }
      cout << "read_json_config_file: upload = " << upload << endl;
    } else {
      throw "Error: could not parse upload from config.json";
    }

    j_metadata_structure = cJSON_GetObjectItemCaseSensitive(config, "metadata_structure");
    if (cJSON_IsString(j_metadata_structure) && (j_metadata_structure->valuestring != NULL))
    {
        metadata_structure = j_metadata_structure->valuestring;
        cout << "read_json_config_file: metadata_structure = " << metadata_structure << endl;
    } else {
      throw "Error: could not parse metadata_structure from config.json";
    }

    char *configJson = cJSON_Print(config);
    if(!configJson) {
      throw "Error: cJSON_Print failed.";
    }
  } catch (string &err) {
    if (printDebug) {
      logging(err.c_str());
      status = false;
    }
  } 
  return status;
}

/*
* Writes metadata_structure from config file into a separate time-stamped file.
* Time is represented as seconds from the epoch (1970).
*/
static void write_metadata_from_config()
{
  // Get number of ms from epoch
  chrono::milliseconds msSinceEpoch = millisecs_since_epoch();

  // Insert epochTime before metadata_structure.
  size_t pos = metadata_structure.find("{");  // opening brace of the json object
  if (pos == string::npos) {
    pos = 0;
  } else {
    // "{" found. Insert after it.
    pos += 1;
  }
  metadata_structure.insert(pos, "\"time_ms_since_epoch\": " + 
            std::to_string(chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count()) + ", ");

  // Convert metadata_structure string to JSON, and add timestamp.
  cJSON *metaJson = cJSON_Parse(metadata_structure.c_str());
  if (!metaJson) {
    logging("Error: failed to parse metadata_structure to JSON.");
  }
  //cJSON_AddNumberToObject(metaJson, "time", epochSeconds);
  char *metaJsonChars = cJSON_Print(metaJson);

  stringstream metadataFilename;
  metadataFilename << output_dir << "/metadata_" << 
            chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count() << ".json";
  FILE *fp = fopen(metadataFilename.str().c_str(), "w");
  fwrite(metaJsonChars, sizeof(char), strlen(metaJsonChars), fp);
  fclose(fp);

  // Cleanup JSON objects
  cJSON_Delete(metaJson);
  free(metaJsonChars);
}

  // Get number of ms from epoch
  static chrono::milliseconds millisecs_since_epoch()
  {
    return chrono::duration_cast< chrono::milliseconds >(
              chrono::system_clock::now().time_since_epoch());
  }
