#!/bin/bash

#USAGE: ./anagram_search.sh <string1> <string2>

#adding check for parameters

if [[ $# -ne 2 ]]
then
echo "USAGE: ./anagram_search.sh <string1> <string2>"
echo ""
exit 0
fi

first_word=$1
second_word=$2
length_of_first_word=$(echo ${#first_word})
length_of_second_word=$(echo ${#second_word})
#if the strings are of unequal length they are not anagrams
if [[ "$length_of_first_word" -ne "$length_of_second_word"]]
  then
  echo "The strings are not anagram"
else
 #sort the strings
 sort_first=$(echo "$first_word"|grep -o . |sort|tr -d '\n') 
 sort_second=$(echo "$second_word"|grep -o . |sort|tr -d '\n') 
 if [[ "$sort_first" == "$sort_second" ]]
 then
 echo "The strings are Anagram"
 else
 echo "The strings are not Anagram"
 fi
