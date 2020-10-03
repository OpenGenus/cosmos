#!/bin/bash
read -p "Enter username: " name
if [ $name == "admin" ]
then
	echo "Access Granted"
else
	echo "Access Denied"
fi
