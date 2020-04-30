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

// C++ includes
#include <vector>
#include <string>
#include <sstream>
#include <signal.h>
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

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
thread uploadThread;
bool threadRunning = true;
bool uploading = false;
string imageToUpload;
/*
* Function declarations
*/

// print out the steps and errors
static void logging(const char *fmt, ...);
static void cleanup();
// decode packets into frames
static int decode_packet(AVPacket *pPacket, AVCodecContext *pCodecContext, AVFrame *pFrame, 
                          int &framesSkipped, int frameInterval, bool I_frames);
// save a frame into a .pgm file
static int write_jpeg(string &imageFileName, AVFrame *pFrame, int frameNumber);
static void run_upload();
static int send_image_to_portal(const string &imageFileName);
static bool create_json_inputs(cJSON *inputs, cJSON *input, cJSON *data, cJSON *image, cJSON *base64, 
                        const string &imageFileName);
static void encode_jpeg_to_base64(cJSON **base64_string, const char *jpeg_file_name);
static bool parse_json_predict_response(string &responseParsed, const string &responseJson);
static size_t write_predict_response(char *ptr, size_t size, size_t nmemb, void *responseJson);
static void show_usage(std::string name);
static int open_video_out_file_and_stream(AVFormatContext *pOutFormatContext, AVFormatContext *pInFormatContext, 
  AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, const string &outFilename, int video_stream_index);
static void close_video_out_file();

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
  int frameInterval = 1;
  bool I_frames = false;  // save only video I-frames
  bool saveVideo = false;
  while ((opt = getopt(argc, argv, "df:hIs")) != -1) {
      switch (opt) {
      case 'h':
        show_usage(argv[0]);
        exit(EXIT_FAILURE);
        break;
      case 'd':
        printDebug = true;
      case 'f':
        frameInterval = atoi(optarg);
        cout << "Frame interval = " << frameInterval << endl;
        break;
      case 'I':
        I_frames = true;
        cout << "Save only I-Frames" << endl;
        break;
      case 's':
        saveVideo = true;
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

  /*
  * initialize thread to upload images and get predictions
  */
  uploadThread = thread(run_upload);

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

  logging("opening the input file (%s) and loading format (container) header", argv[optind]);
  // Open the file and read its header. The codecs are not opened.
  // The function arguments are:
  // AVFormatContext (the component we allocated memory for),
  // url (filename),
  // AVInputFormat (if you pass NULL it'll do the auto detect)
  // and AVDictionary (which are options to the demuxer)
  // http://ffmpeg.org/doxygen/trunk/group__lavf__decoding.html#ga31d601155e9035d5b0e7efedc894ee49
  if (avformat_open_input(&pInFormatContext, argv[optind], NULL, NULL) != 0) {
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
  pOutFormatContext = avformat_alloc_context();
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
    string outFilename = "/files/images/out.ts";
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
        //cout << "pPacket->stream_index = " << pPacket->stream_index << ", outStream->index = " << outStream->index << endl;
        //cout << "outStream->stream_identifier = " << outStream->stream_identifier << endl;
        //pPacket->stream_index = outStream->index;
        //pPacket->pts = av_rescale_q(pPacket->pts, pInFormatContext->streams[0]->codec->time_base, pOutFormatContext->streams[0]->time_base);
        //pPacket->dts = av_rescale_q(pPacket->dts, pInFormatContext->streams[0]->codec->time_base, pOutFormatContext->streams[0]->time_base);

        /* rescale output packet timestamp values from codec to stream timebase */
        //av_packet_rescale_ts(pPacket, pCodecContext->time_base, inStream->time_base);
        //pPacket->stream_index = inStream->index;

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
  return 0;
}

static void cleanup()
{
  logging("releasing all the resources");

  // Stop thread BEFORE libav resources
  threadRunning = false;
  uploadThread.join();

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
          uploading = true;
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
    int jpegQual =75;
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
                                  pFrame->height, TJSAMP_420, &jpegBuf, &jpegSize, jpegQual, flags);
    if(tj_stat != 0)
    {
        const char *err = (const char *) tjGetErrorStr();
        //cerr << "TurboJPEG Error: " << err << " UNABLE TO COMPRESS JPEG IMAGE\n";
        fprintf(stderr, "TurboJPEG Error: %s, UNABLE TO COMPRESS JPEG IMAGE\n", err);
        tjDestroy(handle);
        handle = NULL;
        return -1;

    }

    //char frame_filename[256];
    //snprintf(frame_filename, sizeof(frame_filename), "%s-%d.jpg", "/files/frame", frameNumber);
    stringstream frame_filename;
    frame_filename << "/files/images/frame-" << frameNumber << ".jpg";
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

static int send_image_to_portal(const string &imageFileName)
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
    curl_easy_setopt(handle, CURLOPT_URL, "https://api.clarifai.com/v2/inputs");
    //curl_easy_setopt(handle, CURLOPT_URL, 
    //            "https://api.clarifai.com/v2/workflows/Detect-Concept/results");

    // Specify headers
    struct curl_slist *headers=NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, "Authorization: Key 4a5f25ecc48047ad8fb1d33ca687082e");    
    /* pass our list of custom made headers */
    curl_easy_setopt(handle, CURLOPT_HTTPHEADER, headers);

    /* Now specify the POST data */ 
    char *requestJson = NULL;
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
        //goto cleanup;
      }

      inputs = cJSON_CreateArray();
      if (!inputs) {
        //fprintf(stderr, "Error: could not create inputs cJSON object\n");
        throw "Error: could not create inputs cJSON object";
        //goto cleanup;
      }
      cJSON_AddItemToObject(root, "inputs", inputs);

      if (!create_json_inputs(inputs, input, data, image, base64, imageFileName)) {
        throw "Error: create_json_inputs failed.";
        //goto cleanup;
      }

      requestJson = cJSON_PrintUnformatted(root);
      if(!requestJson) {
        //fprintf(stderr, "Error: cJSON_PrintUnformatted failed.\n");
        throw "Error: cJSON_PrintUnformatted failed.";
        //goto cleanup;
      }

      curl_easy_setopt(handle, CURLOPT_POSTFIELDS, requestJson);

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
      /*
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
      */
    } catch (string &err) {
      if (printDebug) {
        cerr << err <<  endl;
      }
    }
 
    /* always cleanup */     
    cleanup:
      curl_slist_free_all(headers); /* free the header list */
      curl_easy_cleanup(handle);
      if (requestJson) {
        free(requestJson);
      }
  }
  curl_global_cleanup();
  return 0;
}

static void run_upload()
{
  const auto wait_duration = std::chrono::milliseconds(5);
  bool _uploading = false;
  string _imageToUpload;

  while (threadRunning) {
    std::this_thread::sleep_for(wait_duration);

    uploadMutex.lock();
      _uploading = uploading;
      _imageToUpload = imageToUpload;
      uploading = false;
    uploadMutex.unlock();

    if (_uploading) {
      send_image_to_portal(_imageToUpload);
    }
  }
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
  responseParsed.append(header.str());

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
        errString = "Error: parse_json_predict_response: Predict response failed. Response Code = " + std::to_string(code->valueint);
        throw errString;
      }

      if (!cJSON_IsString(description) || strcmp(description->valuestring, "Ok") != 0) {
        errString = "Error: parse_json_predict_response: Predict response failed. Response description = ";
        errString.append(description->valuestring);
        throw errString;
      }
    }

    /*
    * results
    */
    results = cJSON_GetObjectItemCaseSensitive(root, "results");
    if (!results) {
      errString = "Error: parse_json_predict_response: Predict response failed. No results found.";
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
        errString = "Error: parse_json_predict_response: Predict response failed. No results->outputs found.";
        throw errString;
      }
      
      /*
      * results->outputs->status
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
        * results->outputs->data
        */
        cJSON *outputs_data = NULL;
        outputs_data = cJSON_GetObjectItemCaseSensitive(output, "data");
        if (!outputs_data) {
          errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data found.";
          throw errString;
        }

        /*
        * results->outputs->data->regions
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
          * results->outputs->data->regions->data
          */
          cJSON *regions_data = NULL;
          regions_data = cJSON_GetObjectItemCaseSensitive(region, "data");
          if (!regions_data) {
            errString = "Error: parse_json_predict_response: Predict response failed. No outputs->data->regions->data found.";
            throw errString;
          }

          /*
          * results->outputs->data->regions->data->concepts
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
    }   // results



  } catch (string &err) {
    if (printDebug) {
      logging(err.c_str());
    }
    responseParsed.append(err);
    responseParsed.append("\n");
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