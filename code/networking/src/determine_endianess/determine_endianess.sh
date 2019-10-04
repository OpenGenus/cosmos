#!/bin/bash

#shell script to determine endianess of the machine
lscpu | grep Byte| cut -d ":" -f 2
#more portable code
#uncomment below lines if above command fails


#a=`echo -n I | od -to2 | awk 'FNR==1{ print substr($2,6,1)}'`
#if [[ "$a" -eq 1 ]]
#then
#echo "Little Endian"
#else
#echo "Big Endian"
#fi
