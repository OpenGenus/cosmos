CFLAGS = -I/usr/local/include/opencv -I/usr/local/include/opencv2 -L/usr/local/lib/ -g
LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_contrib -lopencv_legacy -lopencv_stitching -lopencv_videoio -lopencv_imgcodecs
CC = g++
% : %.cpp
	$(CC) $(CFLAGS) -o $@ $<  $(LIBS)
