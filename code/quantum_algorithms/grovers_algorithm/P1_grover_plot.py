### Imports required for this solution

import matplotlib.pyplot as plot
import numpy as NP
import hashlib
from math import sqrt, pi
from collections import OrderedDict
from statistics import mean

###############

### PlotGraph(n, amplitude): Plots the graph for target value with the highest amplitude.

def PlotGraph(n, amp_val):
	plot.title('Grovers Algorithm')
	plot.ylabel('Amplitude Value')
	y_pos = NP.arange(n)
	plot.bar(y_pos, amp_val.values(), align='center', color='b') # Here 'b' is color code for blue in matplotlib
	plot.xticks(y_pos, amp_val.keys())
	plot.show()
	
###############

### GetOracle(x_value): Returns the hex digest of the x value. This is referred to as the Oracle function.

def GetOracle(x_val):
    return hashlib.sha256(bytes(x_val, 'utf-8')).hexdigest()
    
###############

### GroverAlgo(target,objects,n_value,no_of_rounds): Returns amplitude retrieved based on the 1/sqrt(n_value).

def GroverAlgo(tgt, objs, nval, rounds):
    y_pos = NP.arange(nval)
    # Calculate amplitude to be returned
    amp = OrderedDict.fromkeys(objs, 1/sqrt(nval))
    for i in range(0, rounds, 2):
        for j, k in amp.items():
            if(GetOracle(j)==GetOracle(tgt)):
                amp[j] = k*(-1)
        avg = mean(amp.values())
        for j, k in amp.items():
            if(GetOracle(j)==GetOracle(tgt)):
                amp[j] = (2*avg) + abs(k)
                continue
            amp[j] = k-(2*(k-avg))
    ##
    print("Final Map with corresponding grover_amplitude", end="\n\n")
    print(amp, end="\n\n")
    
    return amp
    
###############

### Driver-Code

target = '8' #Value to be searched
objects = ('10', '20', '8', '9','16','21','22') #(Set) of different values
no_of_objs = len(objects)
no_of_rounds = int((pi/4)*sqrt(no_of_objs))
print("Number of rounds are {}".format(no_of_rounds),end="\n\n")

amp = GroverAlgo(target, objects, no_of_objs, no_of_rounds) #Calling Grover's Algo

###############

### To-Plot-Graph :- This part is the solution to P-1. in README.md

PlotGraph(no_of_objs, amp)
#Note:- If the target is found then it will have highest amplitude else all objects will have same amplitude.

###############
