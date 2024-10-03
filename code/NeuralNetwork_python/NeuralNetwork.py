import os
import numpy as np
from matplotlib import pyplot
from scipy import optimize
from scipy.io import loadmat

data = loadmat(os.path.join('Data', 'data/path'))
X, y = data['X'], data['y'].ravel()
y[y == 10] = 0
m=y.size
input_layer_size  = 400  # 20x20 Input Images of Digits
hidden_layer_size = 25   # 25 hidden units
num_labels = 10 
def sigmoid(z):
    return 1.0 / (1.0 + np.exp(-z))
def sigmoidGradient(z):
    g = np.zeros(z.shape)
    g=z*(1-z)
    return g
def randInitializeWeights(L_in, L_out, epsilon_init=0.12):
    W = np.zeros((L_out, 1 + L_in))
    W = np.random.rand(L_out, 1 + L_in) * 2 * epsilon_init - epsilon_init
    return W
Theta1=randInitializeWeights(400,25)
Theta2=randInitializeWeights(25,10)
X=np.insert(X,0,1,axis=1)
output=np.zeros((10,m))
for t in range(0,m):
    l=y[t]
    output[l][t]=1    
    
def nnCostFunction(Theta1,Theta2,input_layer_size,hidden_layer_size,num_labels,X,output, y, lambda_=0.0):
    z1=np.dot(X,Theta1.T)
    epoch=10000
    etta=0.5
    a1=sigmoid(z1)
    a1=np.insert(a1,0,1,axis=1)
    z1=np.insert(z1,0,1,axis=1)
    z2=np.dot(a1,Theta2.T)
    hypo=sigmoid(z2)
    m=y.size
    Theta1_grad = np.zeros(Theta1.shape)
    Theta2_grad = np.zeros(Theta2.shape)
    delta1= np.zeros(Theta1.shape)
    delta2 = np.zeros(Theta2.shape)
    output=output.T
    for i in range(epoch):
        for t in range(m):
            a1_=a1[t,:]
            X_=X[t,:]
            X_ = np.asmatrix(X_)
            hypo_=hypo[t,:]
            output_=output[t,:]
            d3=hypo_-output_
            d2=np.dot(Theta2.T,d3)*sigmoidGradient(a1_)#*********** BACKPROPAGATION ALGORITHM
            d2=d2[1:]
            d2= np.asmatrix(d2)
            delta1+=np.dot(d2.T,X_)
            Theta1-=etta*delta1
            d3= np.asmatrix(d3)
            a1_ = np.asmatrix(a1_)
            delta2+=np.dot(d3.T,a1_)
            Theta2-=etta*delta2
    return Theta1,Theta2

def predict(Theta1,Theta2,X):
    z1=np.dot(Theta1,X.T)
    a1=sigmoid(z1)
    a1=np.insert(a1,0,1,axis=0)
    z1=np.insert(z1,0,1,axis=0)
    z2=np.dot(Theta2,a1)
    m,n=X.shape
    hypo=sigmoid(z2)
    result=np.argmax(hypo, axis=0)
    for i in range(m):
        print(result[i])
lambda_ = 3
Theta1,Theta2= nnCostFunction(Theta1,Theta2, input_layer_size, hidden_layer_size,
                   num_labels, X,output, y, lambda_)
predict(Theta1,Theta2,X)