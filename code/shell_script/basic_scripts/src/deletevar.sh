#!/bin/bash
var1="Variable to be deleted!";
echo "$var1";
unset var1;
echo "Printing unset variable: $var1";
# Trying unset keyword on readonly
readonly var2="Readonly var";
echo $var2;
unset var2;
echo $var2;
