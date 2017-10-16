#!/usr/bin/bash

# A program that converts all media into 320kbps mp3 file.
# I use it to organize my media in a common format and common bitrates.
# Author: Adithya Bhat [dth.bht@gmail.com]

# Dependencies:
#	Please install ffmpeg on your machine for the program to work

# Usage:
# 	$ convert2mp3 webm m4a
# 	Converts all .webm, .m4a media files to .mp3 files and deletes the 
#	original files after successful conversion.

bitrate=320k
format=mp3
delete=false

for i
do
	for file in *."$i"
	do
		ffmpeg -i "$file" -f $format -b:a $bitrate "`basename "$file" ."$i"`.$format" 2>/dev/null
		if [ $delete == true ];
		then
			if [ $? -eq 0 ];
			then
				rm "$file"
			fi
		fi
	done
done
