import numpy as np
'''numpy stands for numerical python library. It is used for scientific computing in python '''
import keras.utils
from keras.datasets import mnist
''' mnist is a data set which contains images of numbers from 1-8 in 28*28input size'''
from keras.models import Sequential
from keras.layers import Dense, Dropout
''' Demse indicates layers of connected neurons'''
from keras.optimizers import Adam
# Adam is a special optimizing algorithm


""" To run this code install keras, numpy and tensorflow.
"""

batch_size = 32
categories = 10
epochs = 50 #epochs means no. of times data will be trained

(x_train, y_train), (x_test, y_test) = mnist.load_data()

# reshape function is used to reshape matrix in python.

x_train = x_train.reshape(60000, 784)
x_test = x_test.reshape(10000, 784)


''' The below process is called noramalization. in this we try to scale the
data so that the process could be fast.'''

x_train /= 255
x_test /= 255


print(x_train.shape[0], "train samples")
print(x_test.shape[0], "test samples")

# convert class vectors to binary class matrices
y_train = keras.utils.to_categorical(y_train, categories)
y_test = keras.utils.to_categorical(y_test, categories)

model = Sequential()
model.add(Dense(128, activation="relu", input_shape=(784,)))
model.add(Dropout(0.2))
model.add(Dense(128, activation="relu")) 
''' relu stands for rectified linear unit. it is used as an activation function when output is expected not to be 0 or 1'''
model.add(Dropout(0.2))
model.add(Dense(128, activation="relu"))
model.add(Dropout(0.2))
model.add(Dense(categories, activation="softmax")) #it is an activation function which returns the highest value


model.compile(loss="categorical_crossentropy", optimizer=Adam(), metrics=["accuracy"])

model.fit(
    x_train,
    y_train,
    batch_size=batch_size,
    epochs=epochs,
    verbose=1,
    validation_data=(x_test, y_test),
)
model.evaluate(x_test, y_test, verbose=1)
