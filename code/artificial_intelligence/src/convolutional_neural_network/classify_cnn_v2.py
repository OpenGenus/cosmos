#part 1 - Building CNN
from keras.models import Sequential
from keras.layers import Dense,Flatten,Dropout
from keras.layers import Convolution2D,MaxPooling2D
import cv2,numpy as np
from keras.models import load_model
import glob

def create_cnn(model_path=None):
    #initialization
    classifier=Sequential()
    
    #Convolution
    classifier.add(Convolution2D(32,3,3,input_shape=(150,150,3),activation='relu'))

    #Pooling
    classifier.add(MaxPooling2D(pool_size=(2,2)))
    #Dropout
    classifier.add(Dropout(0.5))
    #Adding 2nd conv. layaer
    classifier.add(Convolution2D(32,3,3,activation='relu'))
    classifier.add(MaxPooling2D(pool_size=(2,2)))
    classifier.add(Dropout(0.5))
    
    classifier.add(Convolution2D(64,3,3,activation='relu'))
    classifier.add(MaxPooling2D(pool_size=(2,2)))
    classifier.add(Dropout(0.5))
    
    
    classifier.add(Convolution2D(64,3,3,activation='relu'))
    classifier.add(MaxPooling2D(pool_size=(2,2)))
    classifier.add(Dropout(0.5))
    
    #Flattening
    classifier.add(Flatten())

    #Full Connected Layers
    classifier.add(Dense(output_dim=64,activation='relu'))
    classifier.add(Dropout(0.5))
    classifier.add(Dense(output_dim=128,activation='relu'))
    classifier.add(Dropout(0.5))
    classifier.add(Dense(output_dim=1,activation='sigmoid'))

    #compliling CNN
    classifier.compile(optimizer='adam',loss='binary_crossentropy',metrics=['accuracy'])

    #Fitting CNN to Images
    from keras.preprocessing.image import ImageDataGenerator
    train_datagen = ImageDataGenerator(
        rescale=1./255,
        shear_range=0.2,
        zoom_range=0.2,
        horizontal_flip=True)

    test_datagen = ImageDataGenerator(rescale=1./255)

    training_set = train_datagen.flow_from_directory(
        'dataset/training_set',
        target_size=(150, 150),
        batch_size=32,
        class_mode='binary')
    
    test_set = test_datagen.flow_from_directory(
        'dataset/test_set',
        target_size=(150,150),
        batch_size=32,
        class_mode='binary')

    classifier.fit_generator(
        training_set,
        steps_per_epoch=8000,
        epochs=35,
        validation_data=test_set,
        validation_steps=2000)

    
    classifier.save('classifier.h5')
    
    if model_path:
        model=load_model('classifier.h5')
    
    return model

if __name__ == "__main__":
    #Opening the image for prediction
    file_path='dataset/single_prediction/cat_or_dog_2.jpg'
    im=cv2.resize(cv2.imread(file_path),(150,150)).astype(np.float32)
    #cv2.imshow('Sample',cv2.resize(cv2.imread(file_path),(640,480)))
    im = np.expand_dims(im, axis=0)
    
    #Checking if model is present in the Directory
    if(glob.glob('*.h5')):
        for filename in glob.glob('*.h5'):
            model=load_model(filename)
            print('Model Loaded')
    else:
        print('Model Not found, Creating a new Model')
        model=create_cnn('classifier.h5')
    
    #Compiling the model and predicting Output    
    model.compile(optimizer='adam',loss='binary_crossentropy',metrics=['accuracy'])
    out=model.predict(im)
    
    if out[0][0]==1:
        prediction='Dog'
    else:
        prediction='Cat'
    print(prediction)
