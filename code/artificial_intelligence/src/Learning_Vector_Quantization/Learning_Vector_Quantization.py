import numpy as np
from collections import defaultdict
import math

def update_code_book_vector(features,ytrain,c_book_vector,c_book_output,max_epochs,alpha):
	
	for epochs in range(0,max_epochs):
		alpha=alpha*(1-((epochs*1.0)/max_epochs))
		for k in range(0,len(features)):
			distance=[]
			for i in range(0,len(c_book_vector)):
				temp=0
				for j in range(0,len(features[0])):
					temp=temp+(c_book_vector[i][j]-features[k][j])**2
				distance.append(math.sqrt(temp))

			distance=np.array(distance)
			postition=np.argmin(distance)
			
			if(ytrain[k]==c_book_output[postition]):
				for j in range(0,len(features[0])):
					c_book_vector[postition][j]=c_book_vector[postition][j]+alpha*(features[k][j]-c_book_vector[postition][j])

			else:
				for j in range(0,len(features[0])):
					c_book_vector[postition][j]=c_book_vector[postition][j]-alpha*(features[k][j]-c_book_vector[postition][j])

	return c_book_vector

def make_prediction(xtest,c_book_vector,c_book_output):
	predictions=[]
	for i in range(0,len(xtest)):
		distance=[]
		for j in range(0,len(c_book_vector)):
			temp=0
			for k in range(0,len(xtest[0])):
				temp=temp+(xtest[i][k]-c_book_vector[j][k])**2

			distance.append(math.sqrt(temp))
		distance=np.array(distance)
		predictions.append(c_book_output[np.argmin(distance)])

	return predictions


x1=[3.393533211,3.110073483,1.343808831,3.582294042,2.280362439,7.423436942,5.745051997,9.172168622,7.792783481,7.939820817]
x2=[2.331273381,1.781539638,3.368360954,4.67917911,2.866990263,4.696522875,3.533989803,2.511101045,3.424088941,0.791637231]


xtrain=[]
for i in range(0,len(x1)):
	xtrain.append([x1[i],x2[i]])

xtrain=np.array(xtrain)
ytrain=[0,0,0,0,0,1,1,1,1,1]

x1=[3.582294042,7.792783481,7.939820817,3.393533211]
x2=[0.791637231,2.331273381,2.866990263,4.67917911]

c_book_vector=[]
for i in range(0,len(x1)):
	c_book_vector.append([x1[i],x2[i]])

c_book_vector=np.array(c_book_vector)
c_book_output=np.array([0,0,1,1])

max_epochs=20
alpha=0.3
c_book_vector=update_code_book_vector(xtrain,ytrain,c_book_vector,c_book_output,max_epochs,alpha)
predictions=make_prediction(xtrain,c_book_vector,c_book_output)
print("Predictions are ",predictions)