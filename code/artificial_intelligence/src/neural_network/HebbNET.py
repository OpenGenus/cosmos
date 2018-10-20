"""
Hebb Net algorithm is one of the earliest 
and simplest neural net.
The learning occurs ,that is the weight increases when both the 
neuron are activated simultaneously and the weight decreases when 
atleast one of them is not acitvated

Wi(new)=Wi(old)+Xi*Yi
Xi is the input neuron
Yi is the output neuron
Xi,Yi are preferred to be in bipolar form +1/-1
so weight is modified when both are ON

Reference-Fundamentals of Neural Networks
"""
import numpy as np
#This Hebbnet algorithm tries to predict the AND gate
class HebbNet():
	def __init__(self):
		self.weights = np.zeros((2,1))

	def train(self,Input):
		size = len(Input)
		for i in range(size):	
			print(self.weights)
			Output = np.matmul(Input[i][:2],self.weights)
			print(Output)
			if Output != Input[i][2]:
				self.weights[0] = self.weights[0]+Input[i][0]*Input[i][2]
				self.weights[1] = self.weights[1]+Input[i][1]*Input[i][2]
			else:
				self.weights[0] = self.weights[0]
				self.weights[1] = self.weights[1]

	def predict(self,Data):
		size = len(Data)
		for i in range(size):
			output = np.matmul(Data,self.weights)
			if output >= 0:
				output = 1
			else:
				output = -1
			print(output)

X = [[1,1,1],[1,-1,-1],[-1,1,-1],[-1,-1,-1]]
X = np.array(X)
test = [[1,-1]]
test = np.array(test)
model = HebbNet()
model.train(X)
model.predict(test)



