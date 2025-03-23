# Implementation of SEQ_NN on BreastCancerData


from keras.models import Sequential
from keras import layers
import matplotlib.pyplot as plt
from sklearn.svm import SVC
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score, roc_auc_score, classification_report
from sklearn.decomposition import PCA
import pandas as pd
from utils.utils_scores import scores
from keras.utils import to_categorical

flag_pca = False

data, target = load_breast_cancer(return_X_y=True)
data = pd.DataFrame(data)
target = pd.DataFrame(target)
target = to_categorical(target)
if flag_pca:
    pca = PCA()
    data = pca.fit_transform(data)

data_train, data_test, target_train, target_test = train_test_split(data, target, test_size=0.1, random_state=0)

input_shape = len(data_train.columns)

model = Sequential()
# Input - Layer
model.add(layers.Dense(50, activation="relu", input_shape=(input_shape,)))
# Hidden - Layers
model.add(layers.Dropout(0.3, noise_shape=None, seed=None))
model.add(layers.Dense(50, activation="relu"))
model.add(layers.Dropout(0.2, noise_shape=None, seed=None))
model.add(layers.Dense(50, activation="relu"))
# Output- Layer
model.add(layers.Dense(2, activation="sigmoid"))
model.summary()

model.compile(optimizer='adam', loss="binary_crossentropy",
              metrics=["accuracy"])
model.fit(data_train, target_train, epochs=50, verbose=1)
y_predict = model.predict(data_test)




