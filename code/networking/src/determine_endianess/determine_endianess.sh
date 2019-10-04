#!/bin/bash

#shell script to determine endianess of the machine
lscpu | grep Byte| cut -d ":" -f 2
