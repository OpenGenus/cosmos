import numpy as np
import dill

class neural_network:

    def __init__(self, num_layers, num_nodes, activation_function, cost_function):
        self.num_layers = num_layers
        self.num_nodes = num_nodes
        self.layers = []
        self.cost_function = cost_function

        for i in range(num_layers):
            if i != num_layers-1:
                layer_i = layer(num_nodes[i], num_nodes[i+1], activation_function[i])
            else:
                layer_i = layer(num_nodes[i], 0, activation_function[i])
            self.layers.append(layer_i)

    def train(self, batch_size, inputs, labels, num_epochs, learning_rate, filename):
        self.batch_size = batch_size
        self.learning_rate = learning_rate
        for j in range(num_epochs):
            i = 0
            print("== EPOCH: ", j, " ==")
            while i+batch_size != len(inputs):
                self.error = 0  
                # input_batch = []
                # label_batch = []
                # # print(i)
                # for i in range(i, i+batch_size):
                #     input_batch.append(inputs[i])
                #     label_batch.append(labels[i])   
                self.forward_pass(inputs[i:i+batch_size])
                self.calculate_error(labels[i:i+batch_size])
                self.back_pass(labels[i:i+batch_size])
                i += batch_size
            print("Error: ", self.error)
        dill.dump_session(filename)

    def forward_pass(self, inputs):
        self.layers[0].activations = inputs
        for i in range(self.num_layers-1):
            self.layers[i].add_bias(self.batch_size, self.layers[i+1].num_nodes_in_layer)
            temp = np.add(np.matmul(self.layers[i].activations, self.layers[i].weights_for_layer), self.layers[i].bias_for_layer)
            if self.layers[i+1].activation_function == "sigmoid":
                self.layers[i+1].activations = self.sigmoid(temp)
            elif self.layers[i+1].activation_function == "softmax":
                self.layers[i+1].activations = self.softmax(temp)
            elif self.layers[i+1].activation_function == "relu":
                self.layers[i+1].activations = self.relu(temp)
            elif self.layers[i+1].activation_function == "tanh":
                self.layers[i+1].activations = self.tanh(temp)
            else:
                self.layers[i+1].activations = temp

    def relu(self, layer):
        layer[layer < 0] = 0
        return layer

    def softmax(self, layer):
        exp = np.exp(layer)
        return exp/np.sum(exp, axis=1, keepdims=True)

    def sigmoid(self, layer):
        return np.divide(1, np.add(1, np.exp(layer)))

    def tanh(self, layer):
        return np.tanh(layer)

    def calculate_error(self, labels):
        if len(labels[0]) != self.layers[self.num_layers-1].num_nodes_in_layer:
            print ("Error: Label is not of the same shape as output layer.")
            print("Label: ", len(labels), " : ", len(labels[0]))
            print("Out: ", len(self.layers[self.num_layers-1].activations), " : ", len(self.layers[self.num_layers-1].activations[0]))
            return
        
        if self.cost_function == "mean_squared":
            self.error = np.mean(np.divide(np.square(np.subtract(labels, self.layers[self.num_layers-1].activations)), 2))
        elif self.cost_function == "cross_entropy":
            self.error = np.negative(np.sum(np.multiply(labels, np.log(self.layers[self.num_layers-1].activations))))

    def back_pass(self, labels):
        # if self.cost_function == "cross_entropy" and self.layers[self.num_layers-1].activation_function == "softmax":
        targets = labels
        i = self.num_layers-1
        y = self.layers[i].activations
        deltaw = np.matmul(np.asarray(self.layers[i-1].activations).T, np.multiply(y, np.multiply(1-y, targets-y)))
        new_weights = self.layers[i-1].weights_for_layer - self.learning_rate * deltaw
        for i in range(i-1, 0, -1):
            y = self.layers[i].activations
            deltaw = np.matmul(np.asarray(self.layers[i-1].activations).T, np.multiply(y, np.multiply(1-y, np.sum(np.multiply(new_weights, self.layers[i].weights_for_layer),axis=1).T)))
            self.layers[i].weights_for_layer = new_weights
            new_weights = self.layers[i-1].weights_for_layer - self.learning_rate * deltaw
        self.layers[0].weights_for_layer = new_weights
    
    def predict(self, filename, input):
        dill.load_session(filename)
        self.batch_size = 1
        self.forward_pass(input)
        a = self.layers[self.num_layers-1].activations
        a[np.where(a==np.max(a))] = 1
        a[np.where(a!=np.max(a))] = 0
        return a

    def check_accuracy(self, filename, inputs, labels):
        dill.load_session(filename)
        self.batch_size = len(inputs)
        self.forward_pass(inputs)
        a = self.layers[self.num_layers-1].activations
        num_classes = 10
        targets = np.array([a]).reshape(-1)
        a = np.asarray(a)
        one_hot_labels = np.eye(num_classes)[a.astype(int)]
        total=0
        correct=0
        for i in range(len(a)):
            total += 1
            if np.equal(one_hot_labels[i], labels[i]).all():
                correct += 1
        print("Accuracy: ", correct*100/total)



    def load_model(self, filename):
        dill.load_session(filename)
        

class layer:
    def __init__(self, num_nodes_in_layer, num_nodes_in_next_layer, activation_function):
        self.num_nodes_in_layer = num_nodes_in_layer
        self.activation_function = activation_function
        self.activations = np.zeros([num_nodes_in_layer,1])
        if num_nodes_in_next_layer != 0:
            self.weights_for_layer = np.random.normal(0, 0.001, size=(num_nodes_in_layer, num_nodes_in_next_layer))
        else:
            self.weights_for_layer = None
            self.bias_for_layer = None
     
    def add_bias(self, batch_size, num_nodes_in_next_layer):
        if num_nodes_in_next_layer != 0:
            self.bias_for_layer = np.random.normal(0, 0.01, size=(batch_size, num_nodes_in_next_layer))
