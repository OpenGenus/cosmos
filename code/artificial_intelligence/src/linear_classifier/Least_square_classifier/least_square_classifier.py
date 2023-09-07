import sys
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from pylab import *

def LeastSquareClassifier(inputData):
	A=[ x[1:] for x in inputData ]
	A=np.insert(A, 2 ,1 , axis=1)
	m = np.matrix(A)
	t = m.getT()
	mul = t*m
	inv = mul.getI()
	secondMul = inv*t

	b = np.matrix( [x[0] for x in inputData] )
	bt = b.getT()

	f = secondMul*bt

	weightPlot = []
	weightPlot.insert(0, f.item(0))
	weightPlot.insert(1, f.item(1))
	weightPlot.insert(2, f.item(2))
	return weightPlot

#start
if __name__ == '__main__':
	inputData = [[1,-1,-1], [1,-1,1], [1,0,0], [1,1,0], [-1,2,1], [-1,3,0], [-1,3,3], [-1,0,2]]
	#The first column of inputData denotes the expected class of points (+1/-1)
	weightPlotLS = LeastSquareClassifier(inputData)
	a = weightPlotLS[0]
	b = weightPlotLS[1]
	c = weightPlotLS[2]
	# The line ax+by+c=0 is the finally obtained linear classifier