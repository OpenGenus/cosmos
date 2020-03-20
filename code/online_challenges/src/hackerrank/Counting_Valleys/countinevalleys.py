#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the countingValleys function below.
def countingValleys(n, s):
    countu,countd=0,0
    x=""
    v=0
    for x in s:
        if(x=="U"):
            #c+=1
            countu+=1
        else:
            countu-=1
        if(countu==0 and x=="U"):
            v+=1
    return(v)
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    s = input()

    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')

    fptr.close()
