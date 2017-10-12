#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jun 27 21:38:10 2017

@author: root
"""

import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data

mnist = input_data.read_data_sets("tmp/data/", one_hot=True)

n_nodes_hl1 = 500
n_nodes_hl2 = 500
n_nodes_hl3 = 500

n_classes = 10
batch_size = 100

# input feature size = 28x28 pixels = 784
x = tf.placeholder('float', [None, 784])
y = tf.placeholder('float')

def neural_network_model(data):
 # input_data * weights + biases
 hidden_l1 = {'weights': tf.Variable(tf.random_normal([784, n_nodes_hl1])),
    'biases': tf.Variable(tf.random_normal([n_nodes_hl1]))}

 hidden_l2 = {'weights': tf.Variable(tf.random_normal([n_nodes_hl1, n_nodes_hl2])),
    'biases': tf.Variable(tf.random_normal([n_nodes_hl2]))}

 hidden_l3 = {'weights': tf.Variable(tf.random_normal([n_nodes_hl2, n_nodes_hl3])),
    'biases': tf.Variable(tf.random_normal([n_nodes_hl3]))}

 output_l = {'weights': tf.Variable(tf.random_normal([n_nodes_hl3, n_classes])),
    'biases': tf.Variable(tf.random_normal([n_classes]))}

 l1 = tf.add(tf.matmul(data, hidden_l1['weights']), hidden_l1['biases'])
 l1 = tf.nn.relu(l1)

 l2 = tf.add(tf.matmul(l1, hidden_l2['weights']), hidden_l2['biases'])
 l2 = tf.nn.relu(l2)

 l3 = tf.add(tf.matmul(l2, hidden_l3['weights']), hidden_l3['biases'])
 l3 = tf.nn.relu(l3)

 output = tf.add(tf.matmul(l3, output_l['weights']), output_l['biases'])
 return output

def train_neural_network(x):
 prediction = neural_network_model(x)
 cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=prediction, labels=y))   # v1.0 changes
  # optimizer value = 0.001, Adam similar to SGD
 optimizer = tf.train.AdamOptimizer().minimize(cost)
 epochs_no = 15
 
 with tf.Session() as sess:
  sess.run(tf.global_variables_initializer())   # v1.0 changes
  
  # training
  for epoch in range(epochs_no):
   epoch_loss = 0
   for _ in range(int(mnist.train.num_examples/batch_size)):
    epoch_x, epoch_y = mnist.train.next_batch(batch_size)
    _, c = sess.run([optimizer, cost], feed_dict = {x: epoch_x, y: epoch_y})
      # code that optimizes the weights & biases
    epoch_loss += c
   print('Epoch', epoch, 'completed out of', epochs_no, 'loss:', epoch_loss)
  
  # testing
  correct = tf.equal(tf.argmax(prediction, 1), tf.argmax(y, 1))
  accuracy = tf.reduce_mean(tf.cast(correct, 'float'))
  print('Accuracy:', accuracy.eval({x: mnist.test.images, y: mnist.test.labels}))

train_neural_network(x)
