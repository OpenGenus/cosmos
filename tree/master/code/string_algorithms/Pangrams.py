#!/bin/python3
#A panagram is a sentence containing every letter of the alphabet.
import math
import os
import random
import re
import sys

# Complete the pangrams function below.
def pangrams(s):
    s=list(set(s.lower()))# setting all alphabets to lower case
    count=0
    for i in range(97,123):# checking in ASCII range of lower case
        for j in s:
            if ord(j)==i:
                count+=1
    if count>=26: #if count exceeds 26, which implies it is a panagram!
        print("pangram")
        return "pangram"
    else:
        print("not pangram")
        return "not pangram"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = pangrams(s)

    fptr.write(result + '\n')

    fptr.close()
