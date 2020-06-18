# video-manager
Decode video, save to jpeg, upload to Clarifai API, write detections to CSV

# Build container tagged as video-manager
docker build -t video-manager .

# Exec into container and run executables. First cd to the source code directory.
# The executables will be in /files/build
docker run -it --network host -v `pwd`:/files video-manager bash

There are 2 executables: 
video_manager - capture video and run predicts
video_manager_no_predict - capture video with no predicts

To record 2 cameras simultaneously:
 ./video_manager ../config_mwir.json ; ./video_manager_no_predict ../config_color.json
 
# RTSP test websites
rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov
rtsp://170.93.143.139/rtplive/470011e600ef003a004ee33696235daa (may not be working)
rtsp://freja.hiof.no:1935/rtplive/definst/hessdalen03.stream
