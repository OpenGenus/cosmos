#!/bin/bash	
# This is how you add comments
# Reading variable without promptings users
read var1
echo "$var1"
# Reading variable by prompting user
read -p "Enter a value: " var2
echo "$var2"
# Reading a silent variable by prompting user
read -sp "Enter a value: " var3
echo "" # By default it has an endline attached
echo "$var3"
