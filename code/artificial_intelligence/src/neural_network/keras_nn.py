# Setting up the environment 
pip install keras
pip install numpy
pip install tensorflow 

# Import all necessary libraries
import numpy as np
import keras.utils
from keras.datasets import mnist # Import the MNIST data set and cache it
from keras.models import Sequential
from keras.layers import Dense, Dropout
from keras.optimizers import Adam

batch_size = 32
categories = 10
epochs = 50

(x_train, y_train), (x_test, y_test) = mnist.load_data() # Load the data and split it into train and test sets

# Reshape the input vector to 28*28 pixels
x_train = x_train.reshape(60000, 784)
x_test = x_test.reshape(10000, 784)

# Normalise the data
x_train /= 255
x_test /= 255

# Print final input vectors before training
print(x_train.shape[0], "train samples")
print(x_test.shape[0], "test samples")

# Convert class vectors to binary class matrice 
y_train = keras.utils.to_categorical(y_train, categories)
y_test = keras.utils.to_categorical(y_test, categories)

# Building the model with linear stack of layers
model = Sequential()
model.add(Dense(128, activation="relu", input_shape=(784,)))
model.add(Dropout(0.2))
model.add(Dense(128, activation="relu"))
model.add(Dropout(0.2))
model.add(Dense(128, activation="relu"))
model.add(Dropout(0.2))
model.add(Dense(categories, activation="softmax"))

# Compile the mode with Adam optimizer 
model.compile(loss="categorical_crossentropy", optimizer=Adam(), metrics=["accuracy"])

# Train the Model
model.fit(
    x_train,
    y_train,
    batch_size=batch_size,
    epochs=epochs,
    verbose=1,
    validation_data=(x_test, y_test),
)

# Evaluating model performance
model.evaluate(x_test, y_test, verbose=1)
