#importing modules 
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

#reading and loading of dataset
url = 'https://goo.gl/bDdBiA'
names = ['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age', 'class']
data = pd.read_csv(url, names=names)
y=data['class']
x=data.drop('class',axis=1)
labels=['preg', 'plas', 'pres', 'skin', 'test', 'mass', 'pedi', 'age']

#converting pandas dataframe to array
array=data.values
X = array[:,0:8]
Y = array[:,8]

#Stastistics of data
print(data.describe(),'\n')

#data visualization
from pandas.plotting import scatter_matrix
scatter_matrix(data)
plt.show()

#Gradient boosting Classifier Algorithm
from sklearn.ensemble import GradientBoostingClassifier
model = GradientBoostingClassifier(learning_rate=0.1, n_estimators=100)

from sklearn.model_selection import KFold
from sklearn.model_selection import cross_val_score

#finding mean square loss
kfold = KFold(n_splits=10, random_state=7)
scoring = 'neg_mean_squared_error'
results = cross_val_score(model, X, Y, cv=kfold,scoring=scoring)
print("Cross Validation Score(mean square error):",results.mean(),'\n')

#splitting data into training and testing dataset
import sklearn.model_selection
x_train,x_test,y_train,y_test=sklearn.model_selection.train_test_split(x,y,test_size=0.3)
model=model.fit(x_train,y_train)

#training and accuracy of splitted dataset
print("Gradient Boosting Accuracy: %.3f%%"%(model.score(x_test,y_test)*100),'\n')

#prediction on training dataset
final_pred=model.predict(x_test)
y_test=y_test.values
y_test=y_test.reshape(-1,1)
final_pred=final_pred.reshape(-1,1)

#cross validation score on predicted data
results = cross_val_score(model, y_test, final_pred, cv=kfold,scoring=scoring)
print("mean square error(predicted data):",results.mean(),'\n')

#Classification report
from sklearn.metrics import classification_report
print(classification_report(y_test,final_pred),'\n')

#Confusion Matrix
from sklearn.metrics import confusion_matrix
print(confusion_matrix(y_test,final_pred),'\n')
