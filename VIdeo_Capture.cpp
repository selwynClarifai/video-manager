// C includes
#include <dirent.h> // for directory access

// C++ includes
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

// Local includes
#include "Video_Capture.h"
#include "Utils.h"

using namespace std;

// declare global variables (from Utils.h)
std::map<int, int64_t> ptsMap;  // record PTS values during decode. Add to Alarm files in postprocessing.

// declare static variables
mutex Video_Capture::predictMutex;
bool Video_Capture::threadRunning;
thread Video_Capture::predictThread;
bool Video_Capture::predicting = false;
string Video_Capture::imageToUpload;
AIP_Client Video_Capture::aip_client;
Api Video_Capture::api;
sem_t Video_Capture::semDecode;  // semaphore to allow decode to run
sem_t Video_Capture::semPredict;  // semaphore to allow predict to run
bool Video_Capture::upload = false;
string Video_Capture::output_dir;
bool Video_Capture::save_jpeg = false;
queue<std::string> Video_Capture::imageQueue;

Video_Capture::Video_Capture(Configuration_File &c, Video_Capture::CaptureType ct) :
  config(c)
{
  save_jpeg = config.save_jpeg;
  aip_proto = config.aip_proto;
  upload = config.upload;
  output_dir = config.output_dir;
  captureType = ct;

  api.authorizationHeader = c.authorizationHeader;
  api.print_debug = c.print_debug;
  api.base_url = c.base_url;
  api.model_id = c.model_id;
  api.model_version = c.model_version;
  api.output_dir = c.output_dir;
  api.upload = c.upload;

  pOutFormatContext = NULL;
  pInFormatContext = NULL;
  pPacket = NULL;
  pCodecContext = NULL;
  pFrame = NULL;
  outStream = NULL;

  imageWidth = 0;
  imageHeight = 0;

  stopDecoding = false;
  sem_init(&semPredict, 0, 0);
  sem_init(&semDecode, 0, 1);

}

Video_Capture::~Video_Capture()
{
    //delete api;
    cout << "Video_Capture::cleanup()" << endl;
    cleanup();
}

int Video_Capture::decode_video()
{
  string videoSource;
  bool saveVideo = config.save_video_file;
  if (upload) {
    videoSource = config.upload_file;
    saveVideo = false;
  } else {
    videoSource = config.stream_url;
  }

  /*
  * initialize thread to get predictions
  */
  if (captureType == CAPTURE_PREDICT) {
    predictThread = thread(run_predict);
  }

  // AVFormatContext holds the header information from the format (Container)
  // Allocating memory for this component
  // http://ffmpeg.org/doxygen/trunk/structAVFormatContext.html
  pInFormatContext = avformat_alloc_context();
  if (!pInFormatContext) {
    logging("ERROR could not allocate memory for Format Context");
    return -1;
  }

  logging("opening the input file (%s) and loading format (container) header", videoSource.c_str());
  // Open the file and read its header. The codecs are not opened.
  // The function arguments are:
  // AVFormatContext (the component we allocated memory for),
  // url (filename),
  // AVInputFormat (if you pass NULL it'll do the auto detect)
  // and AVDictionary (which are options to the demuxer)
  // http://ffmpeg.org/doxygen/trunk/group__lavf__decoding.html#ga31d601155e9035d5b0e7efedc894ee49
  if (avformat_open_input(&pInFormatContext, videoSource.c_str(), NULL, NULL) != 0) {
    logging("ERROR could not open the file %s", videoSource.c_str());
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
  //pOutFormatContext = NULL;
  //AVStream *outStream = NULL;

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
  int framesSkipped = config.frames_to_skip;
  auto videoStartTime = chrono::steady_clock::now();

  bool videoFileExists = false;
  while (av_read_frame(pInFormatContext, pPacket) >= 0 || stopDecoding)
  {
    // if it's the video stream
    int ix = 0;
    if (pPacket->stream_index == video_stream_index) {
      if (config.print_debug) {
        logging("AVPacket->pts %" PRId64, pPacket->pts);
      }

      response = decode_packet(pPacket, pCodecContext, pFrame, framesSkipped, config.frames_to_skip, config.save_I_frames);
      if (response < 0) {
        break;
      }

      // record PTS of this video frame. Will be used to write Alarm files in postprocessing.
      if (captureType == CAPTURE_PREDICT) {
        ptsMap[pCodecContext->frame_number] = pPacket->pts;
      }

      // Save to video output file
      if (saveVideo) {
        auto videoEndTime = chrono::steady_clock::now();
        long elapsedSeconds = chrono::duration_cast<chrono::seconds>(videoEndTime-videoStartTime).count();
        bool start_new_video_file = false;
        if (elapsedSeconds >= config.video_max_seconds) {
          videoStartTime = chrono::steady_clock::now();
          start_new_video_file = true;
        }

        if (!videoFileExists || start_new_video_file) {
          // if cannot create video output file, stop trying to save.
          saveVideo = new_video_out_file(pCodecContext, outStream, inStream, 
                                        video_stream_index, videoFileExists);
          if (!saveVideo) {
            continue;
          }
          videoFileExists = true;
        }

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

  logging("Finished decoding");
  // release all resources
  //cleanup();
}

void Video_Capture::cleanup()
{
  logging("releasing all the resources");

  // Stop thread BEFORE libav resources
  if (captureType == CAPTURE_PREDICT) {
    threadRunning = false;
    predictThread.join();
  }

  // release libav resources
  avformat_close_input(&pInFormatContext);
  av_packet_free(&pPacket);
  av_frame_free(&pFrame);
  avcodec_free_context(&pCodecContext);

  close_video_out_file_and_stream();

  // Write Frame number and PTS to file.
  if (captureType == CAPTURE_PREDICT) {
    FILE *fp = NULL;
    string outFile = config.output_dir + "/frame_pts.txt";
    fp = fopen(outFile.c_str(), "w");
    if (fp) {
      for (auto pts : ptsMap) {
        stringstream line;
        line << pts.first << " " << pts.second << endl;
        fwrite(line.str().c_str(), sizeof(char), line.str().size(), fp);
      }
      fclose(fp);
    }
  }
}

int Video_Capture::decode_packet(AVPacket *pPacket, AVCodecContext *pCodecContext, AVFrame *pFrame, int &framesSkipped, int frameInterval, bool I_frames)
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

    if (response >= 0 && captureType == CAPTURE_PREDICT) {
      // print every 250th frame
      if (config.print_debug || pCodecContext->frame_number % 250 == 0) {
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

      /*
      * Write image dimensions to file. Dimensions will later be used on predict response.
      * Predict on a detection model returns bounding boxes in relative coordinates (0-1).
      */
      if (!config.imageSizeWritten && !config.upload) {
        write_image_size_file(pFrame->width, pFrame->height);
        config.imageSizeWritten = true;
      }

      char frame_filename[1024];
      snprintf(frame_filename, sizeof(frame_filename), "%s-%d.pgm", "frame", pCodecContext->frame_number);

      if (I_frames && pFrame->pict_type == AV_PICTURE_TYPE_I ||
          !I_frames && framesSkipped == frameInterval) {
        framesSkipped = 1;

        // Send image(s) to portal for predict
        if (upload) {
          // send one image at a time for predict
          sem_wait(&semDecode);
          write_jpeg_for_predict(pFrame, pCodecContext->frame_number);
          predicting = true;
          sem_post(&semPredict);
        } else {
          // lock will be obtained for a time slice long enough to decode several frames
          if (predictMutex.try_lock()) {
            write_jpeg_for_predict(pFrame, pCodecContext->frame_number);
            predicting = true;
            predictMutex.unlock();
          }
        }
      } else {
        framesSkipped++;
      }
    }
  }
  return 0;
}

void Video_Capture::write_jpeg_for_predict(AVFrame *pFrame, int frame_number)
{
  string imageFilename;
  write_jpeg(imageFilename, pFrame, pCodecContext->frame_number);
  imageToUpload = imageFilename;
  imageQueue.push(imageToUpload);
}

void Video_Capture::close_video_out_file_and_stream()
{
  if (pOutFormatContext) {
    av_write_trailer(pOutFormatContext);
    int status = avio_close(pOutFormatContext->pb);
    if (status != 0) {
      logging("Error: close_video_out_file_and_stream: cannot close video output file %s. avio_close error=%d", 
            pOutFormatContext->filename, status);
    }
    avformat_free_context(pOutFormatContext);
    pOutFormatContext = NULL;
  }
}

// https://stackoverflow.com/questions/9251747/record-rtsp-stream-with-ffmpeg-libavformat
int Video_Capture::init_video_out_file_and_stream(AVCodecContext *inCodecContext, AVStream *outStream, 
                                AVStream *inStream, const string &outFilename, int video_stream_index)
{
  //open output file
  AVOutputFormat* fmt = av_guess_format(NULL, outFilename.c_str(), NULL);
  pOutFormatContext->oformat = fmt;
  int status = avio_open2(&pOutFormatContext->pb, outFilename.c_str(), AVIO_FLAG_WRITE,NULL,NULL);
  if (status != 0) {
    logging("Error: init_video_out_file_and_stream: cannot open video output file %s. avio_open2 error=%d", 
          outFilename.c_str(), status);
  }
  // Create output stream
  outStream = avformat_new_stream(pOutFormatContext, NULL);
  status = avcodec_parameters_copy(outStream->codecpar, inStream->codecpar);

  outStream->sample_aspect_ratio.num = inCodecContext->sample_aspect_ratio.num;
  outStream->sample_aspect_ratio.den = inCodecContext->sample_aspect_ratio.den;

  // Assume r_frame_rate is accurate
  outStream->r_frame_rate = inStream->r_frame_rate;
  outStream->avg_frame_rate = outStream->r_frame_rate;
  outStream->time_base = av_inv_q( outStream->r_frame_rate );
  outStream->time_base = outStream->time_base;
  cout << "inCodecContext->bit_rate = " << inCodecContext->bit_rate << endl;

  status = avformat_write_header( pOutFormatContext, NULL );
  if (status != AVSTREAM_INIT_IN_WRITE_HEADER && 
      status != AVSTREAM_INIT_IN_INIT_OUTPUT) {
      logging("Error: init_video_out_file_and_stream: avformat_write_header error=%d", status);
      }
  snprintf( pOutFormatContext->filename, sizeof( pOutFormatContext->filename ), "%s", outFilename.c_str() );

  //start reading packets from stream and write them to file
  av_dump_format( pInFormatContext, 0, pInFormatContext->filename, 0 );
  av_dump_format( pOutFormatContext, 0, pOutFormatContext->filename, 1 );

  return status;
}

// create another video output file
bool Video_Capture::new_video_out_file(AVCodecContext *inCodecContext, AVStream *outStream, AVStream *inStream, 
                                  int video_stream_index, bool videoFileExists)
{
  if (videoFileExists) {
    close_video_out_file_and_stream();
  }

  /*
  * To save RTSP, output container format should be mp4, ts, or mkv
  * https://video.stackexchange.com/questions/28446/recording-webcam-video-ffmpeg-error
  * 
  * This article is better. Solves the slow frame rate problem. was getting 2.4 fps instead of 15 fps.
  * Use .ts for accurate frame rate.
  * https://stackoverflow.com/questions/44593241/ffmpeg-segmentation-and-inaccurate-wrong-framerate
  */
  chrono::milliseconds msSinceEpoch = millisecs_since_epoch();
  string outPrefix;
  outPrefix = config.stream_name;

  string outFilename = config.output_dir + "/" + outPrefix + "_" + 
              std::to_string(chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count()) + ".ts";
  pOutFormatContext = avformat_alloc_context();
  int status = init_video_out_file_and_stream(pCodecContext, outStream, inStream, outFilename, video_stream_index);
  if (status >= 0) {
    logging("Succesfully opened video output file %s", outFilename.c_str());
    return true;
  } else {
    logging("Error opening video output file %s, error = %d", outFilename.c_str(), status);
    logging("Not saving video output");
    return false;
  }

  return false;
}

// https://stackoverflow.com/questions/9094691/examples-or-tutorials-of-using-libjpeg-turbos-turbojpeg
int Video_Capture::write_jpeg(string &imageFileName, AVFrame *pFrame, int frameNumber)
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
                                  pFrame->height, TJSAMP_420, &jpegBuf, &jpegSize, config.jpeg_quality, flags);
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
    frame_filename << config.output_dir + "/frame-" << frameNumber << "-" <<
              chrono::duration_cast<std::chrono::milliseconds>(msSinceEpoch).count() << ".jpg";
    FILE *file = fopen(frame_filename.str().c_str(), "wb");
    if (!file) {
        cerr << "Could not open JPEG file: " << strerror(errno);
        return -1;
    }
    if (fwrite(jpegBuf, jpegSize, 1, file) < 1) {
         cerr << "Could not write JPEG file: " << strerror(errno);
        return -1;
    }
    fclose(file);
    imageFileName = frame_filename.str();

    //write out the compress date to the image file
    //cleanup
    int tjstat = tjDestroy(handle); //should deallocate data buffer
    handle = 0;
}

/*
* Write image dimensions to file. Dimensions will later be used on predict response.
* Predict on a detection model returns bounding boxes in relative coordinates (0-1).
*/
bool Video_Capture::write_image_size_file(int width, int height)
{
  if (width <= 0) {
      logging("write_image_size_file: Error: image width = %d", width);
      return false;
  }
  if (height <= 0) {
      logging("write_image_size_file: Error: image height = %d", height);
      return false;
  }

  imageWidth = width;
  imageHeight = height;

  api.imageWidth = imageWidth;
  api.imageHeight = imageHeight;

  string imageSizeFilename = config.output_dir + "/image_size.json";
  FILE *fp = fopen(imageSizeFilename.c_str(), "w");

  if (!fp) {
      return false;
  }

  bool status = true;
  cJSON *j_root = NULL;
  cJSON *j_width = NULL;
  cJSON *j_height = NULL;
  try {
      j_root = cJSON_CreateObject();
      if (!j_root) {
      throw std::runtime_error("write_image_size_file: Error: could not create j_root cJSON object");
      }

      j_width = cJSON_CreateObject();
      if (!j_width) {
      throw std::runtime_error("write_image_size_file: Error: could not create j_width cJSON object");
      }
      j_width = cJSON_CreateNumber(width);
      cJSON_AddItemToObject(j_root, "image_width", j_width);

      j_height = cJSON_CreateObject();
      if (!j_height) {
      throw std::runtime_error("write_image_size_file: Error: could not create j_height cJSON object");
      }
      j_height = cJSON_CreateNumber(height);
      cJSON_AddItemToObject(j_root, "image_height", j_height);
  } catch (const std::exception &e) {
      logging(e.what());
      status = false;
  }

  char *imageSizeJson = cJSON_Print(j_root);
  fwrite(imageSizeJson, sizeof(char), strlen(imageSizeJson), fp);
  fclose(fp);
  free(imageSizeJson);
  return status;
}

/*
* Read image dimensions from file. Dimensions will be used on predict response.
* Predict on a detection model returns bounding boxes in relative coordinates (0-1).
*/
bool Video_Capture::read_image_size_file()
{
  bool status = true;
  cJSON *j_root = NULL;
  cJSON *j_width = NULL;
  cJSON *j_height = NULL;

  try {

    // read image_size.json file
    string imageSizeFilename = config.output_dir + "/image_size.json";
    FILE *fp = std::fopen(imageSizeFilename.c_str(), "r");
    string contents;
    if (fp)
    {
      std::fseek(fp, 0, SEEK_END);
      contents.resize(std::ftell(fp));
      std::rewind(fp);
      std::fread(&contents[0], 1, contents.size(), fp);
      std::fclose(fp);
    } else {
      string err = "read_image_size_file: Error: could not open " + imageSizeFilename + " for reading.";
      throw std::runtime_error(err.c_str());
    }

    j_root = cJSON_Parse(contents.c_str());
    if (!j_root) {
      throw std::runtime_error("read_image_size_file: Error: could not create j_root cJSON object");
    }

    j_width = cJSON_GetObjectItemCaseSensitive(j_root, "image_width");
    if (cJSON_IsNumber(j_width) && (j_width->valueint != NULL))
    {
        imageWidth = j_width->valueint;
    } else {
      string err = "read_image_size_file: Error: could not parse image_width from " + imageSizeFilename + ".";
      throw std::runtime_error(err.c_str());
    }

    j_height = cJSON_GetObjectItemCaseSensitive(j_root, "image_height");
    if (cJSON_IsNumber(j_height) && (j_height->valueint != NULL))
    {
        imageHeight = j_height->valueint;
    } else {
      string err = "read_image_size_file: Error: could not parse image_height from " + imageSizeFilename + ".";
      throw std::runtime_error(err.c_str());
    }
  } catch(const std::exception& e) {
    logging(e.what());
    status = false;
  }

  api.imageWidth = imageWidth;
  api.imageHeight = imageHeight;
}

/*
* Read frame number and PTS from file. Will be written to alarm file.
*/
void Video_Capture::read_frame_pts_file_to_map()
{
  // read image_size.json file
  string framePtsFilename = config.output_dir + "/frame_pts.txt";
  cout << "frame pts file = " << framePtsFilename << endl;
  std::ifstream infile(framePtsFilename.c_str(), std::ifstream::in);

  int frameNumber;
  int64_t pts;
  while (infile >> frameNumber >> pts) {
    if (frameNumber > 0) {
      ptsMap[frameNumber] = pts;
    }
  }

  infile.close();
}


void Video_Capture::run_predict()
{
  const auto wait_duration = std::chrono::milliseconds(5);
  threadRunning = true;

  while (threadRunning) {
    if (predicting) {
      predicting = false;
      if (upload) {
        sem_wait(&semPredict);
        if (aip_proto) {
          aip_client.infer(imageToUpload, api.imageWidth, api.imageHeight);
        } else {
          api.predict_on_image(imageToUpload, "");
        }
        if (!save_jpeg) {
          remove_jpg_files();
        }
        imageQueue.push(imageToUpload);
        sem_post(&semDecode);
      } else {
        predictMutex.lock();
        if (!imageToUpload.empty()) {
          if (aip_proto) {
            aip_client.infer(imageToUpload, api.imageWidth, api.imageHeight);
          } else {
            api.predict_on_image(imageToUpload, "");
          }
          if (!save_jpeg) {
            remove_jpg_files();
          }
          imageQueue.push(imageToUpload);
        }
        predictMutex.unlock();
      }
    } else {
      std::this_thread::sleep_for(wait_duration);
    }
          //}
    //predictMutex.unlock();
  }
}

void Video_Capture::run_upload_and_predict()
{
  const auto wait_duration = std::chrono::milliseconds(10);
  //bool _predicting = false;
  string _imageToUpload;

  vector<string> jpgFiles;
  get_jpg_files_in_output_dir(jpgFiles);

  auto startTime = chrono::steady_clock::now();

  int uploadCount = 0;
  size_t totalJpgs = jpgFiles.size();
  for (auto const &jpg : jpgFiles) {
    string _imageID;
    string _imageURL;
    // the image upload is asynchronous
    bool uploadComplete = api.upload_image(_imageID, _imageURL, jpg);

    // while image is uploading, simultaneously predict
    //predict_on_image(jpg);

    // finally, if image has not yet uploaded, keep verifying its upload until complete
    while (!uploadComplete) {
      std::this_thread::sleep_for(wait_duration);
      uploadComplete = api.verify_upload_complete(_imageID, _imageURL);
    }
    api.predict_on_image(jpg, _imageID, _imageURL);
    uploadCount++;
    if (uploadCount % 100 == 0) {
      logging("Uploaded and predicted on %d of %d images.", uploadCount, totalJpgs);
    }
  }

  auto endTime = chrono::steady_clock::now();
  logging("Uploaded and predicted on %d of %d images.", uploadCount, totalJpgs);
  logging("Uploaded and predicted on %d images in %d seconds.", 
                    jpgFiles.size(), chrono::duration_cast<chrono::seconds>(endTime-startTime).count());
}

// https://stackoverflow.com/questions/306533/how-do-i-get-a-list-of-files-in-a-directory-in-c
void Video_Capture::get_jpg_files_in_output_dir(std::vector<string> &jpgFiles)
{
  DIR *dpdf;
  struct dirent *epdf;

  dpdf = opendir(config.output_dir.c_str());
  if (dpdf != NULL){
    while (epdf = readdir(dpdf)){
        string fileName = epdf->d_name;
        if (fileName.find(".jpg") != string::npos) {
          string fullFileName = config.output_dir + "/" + fileName;
        jpgFiles.push_back(fullFileName);
        }
    }
  }
  closedir(dpdf);

} 

void Video_Capture::remove_jpg_files()
{
  // Don't remove images too quickly. Predict request needs time. 
  // Always leave a couple in queue.
  while (imageQueue.size() >= 2) {
    remove(imageQueue.front().c_str());
    imageQueue.pop();
  }
} 