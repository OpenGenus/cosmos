import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

%matplotlib inline

#importing the data set
dataset=pd.read_csv('Salary_Data.csv')

dataset.describe()	

X=dataset.iloc[:,:-1].values
y=dataset.iloc[:,1].values
 
#Splitting the dataset into train set and test set
from sklearn.model_selection import train_test_split
X_train,X_test,y_train,y_test=train_test_spit(X,y,test_size=1/3,random_state=0)

#building the model
from sklearn.linear_model import LinearRegression
regressor=LinearRegression()
regressor.fit(X_train,y_train)

#Predicting the results
y_pred=regressor.predict(X_test)


#Visualsing the training set results
plt.scatter(X_train,y_train,color='red')
plt.plot(X_train,regressor.predict(X_train),)
plt.title('Salary vs Experience(Train set)')
plt.xlabel('Experience in years')
plt.ylabel('Salary')

#Visualising the test set results
plt.scatter(X_test,y_test,color='red')
plt.plot(X_train,regressor.predict(X_train),color='blue')
plt.title('Salary vs experience(Test set)')
plt.xlabel('Experience in years')
plt.ylabel('Salary')
plt.show()
