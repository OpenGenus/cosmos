
##CNN Model for the fashion MNIST dataset

import numpy as np
import pandas as pd
import keras
from keras.datasets import fashion_mnist
from keras.layers import Dense
from keras.models import Sequential
import numpy as np
from keras.layers import Dropout
from keras.layers import Flatten
from keras.utils import np_utils
from keras.layers.convolutional import Conv2D
from keras.layers.convolutional import MaxPooling2D
from keras import backend as K
K.set_image_dim_ordering('th')
import matplotlib.pyplot as plt
import PIL.Image as pil
 
#Loading the data
(x_train, y_train) ,(x_test, y_test) = fashion_mnist.load_data()

#Reshaping
x_train=x_train.reshape(x_train.shape[0],1,28,28).astype('float32')
x_test=x_test.reshape(x_test.shape[0],1,28,28).astype('float32')

#Normalizing
x_train=x_train/255-1
x_test=x_test/255-1

#converting to categorical format 
y_train = np_utils.to_categorical(y_train)
y_test = np_utils.to_categorical(y_test)



def cnnmodel():
    model= Sequential()
    model.add(Conv2D(32,(5,5),input_shape=(1,28,28),activation='relu'))
    model.add(MaxPooling2D(pool_size=(1,1)))
    model.add(Dropout(0.2))
    model.add(Flatten())
    model.add(Dense(128,activation='relu'))
    model.add(Dense(y_train.shape[1],activation='softmax'))
    model.compile(loss='categorical_crossentropy',optimizer='adam',metrics=['accuracy'])
    return model


model=cnnmodel()

#Model summary
print(model.summary())



model.fit(x_train, y_train, validation_split=0.1, epochs=20, batch_size=200, verbose=2)

scores = model.evaluate(x_test, y_test, verbose=0)
print(scores)



#storing the predicted values of test data in 'results'
predictions=model.predict(x_test)
results=[]
for i in predictions:
    results.append(np.argmax(i))
    


#Verification
##Displays 'TestIndex' image and also the predicted value

TestIndex=10 
testImage = (np.array(x_test[TestIndex], dtype='float')).reshape(28,28)
img = pil.fromarray(np.uint8(testImage * 255) , 'L')
img.show()
print(results[TestIndex])


