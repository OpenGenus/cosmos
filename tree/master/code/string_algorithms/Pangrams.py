#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the pangrams function below.
def pangrams(s):
    s=list(set(s.lower()))
    count=0
    for i in range(97,123):
        for j in s:
            if ord(j)==i:
                count+=1
    if count>=26:
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
