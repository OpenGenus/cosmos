import os
import random
import numpy as np
from matplotlib import pyplot
from scipy import optimize
from scipy.io import loadmat

data = loadmat(os.path.join('Data', 'data/path'))
X, y = data['X'], data['y'].ravel()
test=X
test=np.insert(test,0,1,axis=1)
y[y == 10] = 0
X=np.insert(X,0,0,axis=1)
m=y.size
for i in range(m):
    X[i][400]=y[i]
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
output=np.zeros((10,5000))
for t in range(0,5000):
    l=y[t]
    output[l][t]=1   

def update(Theta1,Theta2,mini_batch,etta,batch_size):
    theta1_grad=np.zeros(Theta1.shape)
    theta2_grad=np.zeros(Theta2.shape)
    x=mini_batch[:,0:400]
    y=mini_batch[:,401]
    m1,n1=(mini_batch.shape)
    output=np.zeros((10,batch_size))
    for t in range(0,m1):
        l= int (y[t])
        output[l][t]=1
    x=np.insert(x,0,1,axis=1)
    theta1_grad,theta2_grad=backpropagation(x,output,Theta1,Theta2,batch_size)
    Theta1-=etta*theta1_grad
    Theta2-=etta*theta2_grad
    return Theta1,Theta2
    
    
def SGD(X,Theta1,Theta2,epo,etta,batch_size):
    for i in range(epo):
        np.random.shuffle(X)
        mini_batches = [X[k:k+50] for k in range(0, m, batch_size)]
        for mini_batch in(mini_batches):
            Theta1,Theta2=update(Theta1,Theta2,mini_batch,etta,batch_size)
    return Theta1,Theta2
    
def backpropagation(x,output,Theta1,Theta2,batch_size):
    lambda_=0.5
    z2=np.dot(Theta1,x.T)
    a2=sigmoid(z2)
    #a2=a2_
    a2=np.insert(a2,0,1,axis=0)
    z3=np.dot(Theta2,a2)
    a3=sigmoid(z3)
    delta12= np.zeros(Theta1.shape)
    delta23 = np.zeros(Theta2.shape)
    for t in range(batch_size):
        x_=x[t,:]
        z2_=z2[:,t]
        a2_=a2[:,t]
        a3_=a3[:,t]
        output_=output[:,t]
        d3=a3_-output_
        d2=np.dot(Theta2.T,d3)*sigmoidGradient(a2_)
        d2=d2[1:]
        d2 = np.asmatrix(d2)
        x_ = np.asmatrix(x_)
        d3= np.asmatrix(d3)
        a2_= np.asmatrix(a2_)
        delta12+=np.dot(d2.T,x_)
        delta23+=np.dot(d3.T,a2_)
    theta1_grad = 1/batch_size * delta12 +(lambda_/batch_size)*Theta1
    theta2_grad = 1/batch_size * delta23 + (lambda_/batch_size)*Theta2
    return theta1_grad,theta2_grad

def predict(w1,w2,X):
    z1=np.dot(w1,X.T)
    a1=sigmoid(z1)
    a1=np.insert(a1,0,1,axis=0)
    z1=np.insert(z1,0,1,axis=0)
    z2=np.dot(w2,a1)
    m,n=X.shape
    hypo=sigmoid(z2)
    result=np.argmax(hypo, axis=0)
    print(result[i])
    
epo=1
etta=0.5
batch_size=50
w1,w2=SGD(X,Theta1,Theta2,epo,etta,batch_size)
X=X[:,1:]
predict(w1,w2,test)

