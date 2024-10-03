#!/usr/bin/bash

# A program that downloads the link in your clipboard.
# I use it to download links that I have copied.
# Author: Adithya Bhat [dth.bht@gmail.com]

# Dependencies:
#	Please install xclip and/or one of {axel,aria2c} on your machine to maximize the 
#   download speeds.

# Usage:
# 	$ download
# 	Downloads the last thing copied to the clipboard. 

if [ $(which axel 2>/dev/null) ];
then 
    axel -an 32 "`xclip -o`"
elif [ $(which aria2c 2>/dev/null) ];
then
    aria2c -x 8 -s 32 `xclip -o`
else
    wget "`xclip -o`"
fi
