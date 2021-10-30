import nn
import numpy as np
import os
import matplotlib.pyplot as plt

path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "mnist.npz")
with np.load(path) as data:
    training_images = data["training_images"]
    training_labels = data["training_labels"]

layer_sizes = (784, 5, 10)

net = nn.neural_network(layer_sizes)
net.accuracy(training_images, training_labels)
