#!/bin/bash
read -p "Enter your name: " name
case $name in
	admin) echo "Access Granted! Welcome Admin" ;;
	root) echo "Access Granted! Welcome root" ;;
	*) echo "Access Denied" ;;
esac
