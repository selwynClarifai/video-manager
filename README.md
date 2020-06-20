# video-manager
Decode video, save to jpeg, upload to Clarifai API, write detections to CSV

### Build container tagged as video-manager
docker build -t video-manager .

### There are 2 executables: 
video_manager - capture video and run predicts) \
video_manager_no_predict - capture video with no predicts

### To make the executables
make make_video \
make make_video_no_predict

### Record MWIR video and predict on RTSP stream (download mode)
- Use config_mwir.json config file
- Set "upload" : false
- cd to the source code directory.
- Create the desired output directory, such as "images".
- Exec into docker container: `docker run -it --network host -v <current_directory>:/files video-manager /bin/bash`
- `cd /files/build`
- `./video_manager ../config_mwir.json`
- Video file (mwir*.ts) will save to the output directory, along with predict txt files every second or so.

### Generate predict txt files (Alarm files) on each frame of MWIR video file (upload mode)
- Use config_mwir.json config file
- Set "upload" : true
- Set "upload_file" to the full path to the mwir video (i.e. /files/images/mwir_1592620397706.ts)
- cd to the source code directory.
- Create the desired output directory, such as "images".
- Exec into docker container: `docker run -it --network host -v <current_directory>:/files video-manager /bin/bash`
- `cd /files/build`
- `./video_manager ../config_mwir.json`
- Predict / Alarm txt files for each frame of the video will be saved to the output directory.

### Record Color video on RTSP stream (there is only one mode for color camera: download with no predicts)
- Use config_color.json config file
- Verify "upload" : false
- cd to the source code directory.
- Create the desired output directory, such as "images".
- Exec into docker container: `docker run -it --network host -v <current_directory>:/files video-manager /bin/bash`
- `cd /files/build`
- `./video_manager ../config_color.json`
- Video file (color*.ts) will save to the output directory.

### To record 2 cameras simultaneously:
 ./video_manager ../config_mwir.json ; ./video_manager_no_predict ../config_color.json
 
### RTSP test websites
rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov
rtsp://170.93.143.139/rtplive/470011e600ef003a004ee33696235daa (may not be working)
rtsp://freja.hiof.no:1935/rtplive/definst/hessdalen03.stream
