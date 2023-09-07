import numpy as np
import sys
from datetime import datetime
import pickle
import tqdm
import random
from pathlib import Path

class Sigmoid:
    def forward(self, x):
        return 1.0 / (1.0 + np.exp(-x))

    def backward(self, x):
        return (1.0 - x) * x

class Softmax:
    def forward(self, x):
        exp_scores = np.exp(x)
        return exp_scores / np.sum(exp_scores)

    def loss(self, x, y):
        return -np.log(x[y])

    def backward(self, x, y):
        x[y] -= 1.0
        return x


class Layer:
    

    def forward(self, x, prev_s, u, w, v):
        """
        x : input array
        prev_s : array
        u,v,w : weight matrices
        """
        activation = Sigmoid()
        output = Softmax()
        self.mulu = np.matmul(x, u)
        self.mulw = np.matmul(prev_s, w)
        self.sin = np.add(self.mulu, self.mulw)
        self.sout = activation.forward(self.sin)
        self.oin = np.matmul(self.sout, v)
        self.oout = output.forward(self.oin)

    def backward(self, x, prev_s, y, u, w, v):
        """
        y : integer
        """
        activation = Sigmoid()
        output = Softmax()
        self.loss = output.loss(self.oout, y)
        self.dldoi = output.backward(self.oout, y)
        self.doidso = v
        self.doidv = self.sout
        self.dsodsi = activation.backward(self.sout)
        self.dsidu = x
        self.dsidpso = w
        self.dsidw = prev_s



class RNN:
    def __init__(self, word_dim, hidden_dim=100, bptt_truncate=4):
        self.word_dim = word_dim
        self.hidden_dim = hidden_dim
        self.bptt_truncate = bptt_truncate
        self.U = np.random.uniform(-np.sqrt(1. / word_dim), np.sqrt(1. / word_dim), (word_dim, hidden_dim))
        self.W = np.random.uniform(-np.sqrt(1. / hidden_dim), np.sqrt(1. / hidden_dim), (hidden_dim, hidden_dim))
        self.V = np.random.uniform(-np.sqrt(1. / hidden_dim), np.sqrt(1. / hidden_dim), (hidden_dim, word_dim))
        self.layers = []

    def forward(self, x):
        """
        x : array of integers (denoting one training example i.e. a sentence)
        """
        T = len(x)
        self.layers = []
        prev_s = np.zeros(self.hidden_dim)
        for t in range(T):
            layer = Layer()
            input = np.zeros(self.word_dim)
            input[x[t]]=1
            layer.forward(input, prev_s, self.U, self.W, self.V)
            prev_s = layer.sout
            self.layers.append(layer)
    
    def generate(self, seed, num=100, k=10):
        """
        seed - one character (tokenized) - integer
        num - number of characters to generate
        """
        # print(detokenize(seed))
        text = []
        text.append(seed)
        prev_s = np.zeros(self.hidden_dim)
        for i in range(num):
            layer = Layer()
            input = np.zeros(self.word_dim)
            input[seed]=1
            layer.forward(input, prev_s, self.U, self.W, self.V)
            prev_s = layer.sout
            # seed = np.argmax(layer.oout)
            # print(detokenize(seed))
            # select randomly from 75% and above
            temp = sorted(layer.oout, reverse=True)
            threshold = temp[k-1]
            top = [index for index, val in enumerate(layer.oout) if val>=threshold]
            seed = random.choice(top)
            # print(layer.oout[seed])
            text.append(seed)
        return text

    def load(self, filename):
        myfile = Path(filename)
        if(myfile.exists):
            print('Loading weights...')
            with open(filename,'rb') as f:
                self.U, self.W, self.V = pickle.load(f)

    # def total_loss(self):
    #     loss  = 0
    #     for layer in self.layers:
    #         loss += layer.loss
    #     return loss

    def calculate_total_loss(self, x, y):
        L = 0
        # For each sentence...
        for i in np.arange(len(y)):
            self.forward(x[i])
            # We only care about our prediction of the "correct" words
            correct_word_predictions = [j.oout[y[i][k]] for k,j in enumerate(self.layers)]
            # Add to the loss based on how off we were
            L += -1 * np.sum(np.log(correct_word_predictions))
        return L
 
    def calculate_loss(self, x, y):
        # Divide the total loss by the number of training examples
        N = np.sum((len(y_i) for y_i in y))
        return self.calculate_total_loss(x,y)/N

    def calculate_grads(self, x, y):
        for t, layer in enumerate(self.layers):
            input = np.zeros(self.word_dim)
            input[x[t]]=1
            prev_s = np.zeros(self.hidden_dim)
            layer.backward(input, prev_s, y[t], self.U, self.W, self.V)
            prev_s = layer.sout

    def backward(self, x, y):
        """
        x,y: array of integers
        """
        self.forward(x)
        self.calculate_grads(x, y)
        dldu = np.zeros(self.U.shape)
        dldw = np.zeros(self.W.shape)
        dldv = np.zeros(self.V.shape)
        T = len(self.layers)
        for t in np.arange(T)[::-1]:
            dldv += np.outer(self.layers[t].doidv,self.layers[t].dldoi) # dim: [hidden_dim * word_dim]
            delta_t = np.matmul(self.layers[t].doidso, self.layers[t].dldoi) # dEt/dSt(out) dim: [hidden_dim] 
            for bptt_step in np.arange(max(0, t-self.bptt_truncate), t+1)[::-1]:
                delta_t = delta_t * self.layers[bptt_step].dsodsi # dim: [hidden_dim]
                dldw += np.outer(self.layers[bptt_step].dsidw, delta_t)
                dldu += np.outer(self.layers[bptt_step].dsidu, delta_t)
                delta_t = np.matmul(self.layers[bptt_step].dsidpso, delta_t) # dim: [hidden_dim]
        return (dldu, dldw, dldv)

    def sgd_step(self, x, y, learning_rate):
        dU, dW, dV = self.backward(x, y)
        self.U -= learning_rate * dU
        self.V -= learning_rate * dV
        self.W -= learning_rate * dW

    def train(self, X, Y, learning_rate, nepoch, evaluate_loss_after):
        num_examples_seen = 0
        losses = []
        print("\n\n TRAINING STARTED \n\n")
        for epoch in range(nepoch):
            if (epoch % evaluate_loss_after == 0):
                    loss = self.calculate_loss(X,Y)
                    losses.append((num_examples_seen, loss))
                    time = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
                    print("%s: Loss after num_examples_seen=%d epoch=%d: %f" % (time, num_examples_seen, epoch, loss))
                    # Adjust the learning rate if loss increases
                    if len(losses) > 1 and losses[-1][1] > losses[-2][1]:
                        learning_rate = learning_rate * 0.5
                        print("Setting learning rate to %f" % learning_rate)
                    sys.stdout.flush()
            # For each training example...
            for i in tqdm.tqdm(range(len(Y))):
                # print(i, )
                # X[i] and Y[i] are one training example
                self.sgd_step(X[i], Y[i], learning_rate)
                num_examples_seen += 1
            with open('uwv.pkl', 'wb') as f:  
                pickle.dump([self.U, self.W, self.V], f)
            f.close()
                
        
        return losses
                        



        
            
