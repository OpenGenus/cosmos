#!/bin/bash
# creating a normal variable
var1="Variable 1"; # No spacing between variable name and value else error
echo $var1;
# Changing value of variable 1
var1="Variable 1 updated";
echo $var1;
# Creating readonly variable
readonly var2="Readonly var";
echo $var2;
var2="Can I change?";
echo $var2;
