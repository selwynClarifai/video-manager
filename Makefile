usage:
	echo "make fetch_small_bunny_video && make run_hello"

all: clean make_video
.PHONY: all

clean:
	@rm -rf ./build/*

make_video: clean
	docker run -w /files --rm -it  -v `pwd`:/files video-manager \
	  g++ -std=c++11 -pthread -L/opt/ffmpeg/lib -L/usr/lib/x86_64-linux-gnu \
	  -I/opt/ffmpeg/include/ -I/usr/lib/include -I/usr/include -I/files/nlohmann/ \
	  /files/cJSON.c /files/base64.c /files/video_manager.cpp \
	  -lavcodec -lavformat -lavfilter -lavdevice -lswresample -lswscale -lavutil -ljpeg -lturbojpeg -lcurl \
	  -o /files/build/video_manager

run_video: make_video
	docker run -w /files --rm -it -v `pwd`:/files video-manager /files/build/video_manager /files/small_bunny_1080p_60fps.mp4

run_rtsp: make_video
	#docker run -w /files --rm -it -v `pwd`:/files video-manager /files/build/video_manager rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov
	#docker run -w /files --rm -it -v `pwd`:/files video-manager /files/build/video_manager rtsp://170.93.143.139/rtplive/470011e600ef003a004ee33696235daa
	docker run -w /files --rm -it -v `pwd`:/files video-manager /files/build/video_manager rtsp://freja.hiof.no:1935/rtplive/definst/hessdalen03.stream

run_stream: make_video
	docker run -w /files --rm -it -v `pwd`:/files video-manager /files/build/video_manager http://wmccpinetop.axiscam.net/mjpg/video.mjpg

