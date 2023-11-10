#!bin/bash

cd /home/kshitiz/archives

rm $(find -mtime +2 -name "*.tar")
rm $(find -mtime +2 -name "*.tar.gz")
rm $(find -mtime +2 -name "*.tar.bz2")
