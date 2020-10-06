# example using iris dataset
# Part of Cosmos by OpenGenus
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import GaussianNB
from sklearn.metrics import classification_report, confusion_matrix

dataset = pd.read_csv("iris1.csv", header=0)

X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, 4].values


X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.30, stratify=y)


classifier = GaussianNB()
classifier.fit(X_train, y_train)

y_pred = classifier.predict(X_test)

# labeled confusion matrix
print(
    pd.crosstab(y_test, y_pred, rownames=["True"], colnames=["Predicted"], margins=True)
)

from sklearn.model_selection import StratifiedKFold
from sklearn.metrics import accuracy_score

skf = StratifiedKFold(n_splits=10)
skf.get_n_splits(X, y)
StratifiedKFold(n_splits=10, random_state=None, shuffle=False)
a = 0
for train_index, test_index in skf.split(X, y):
    # print("TRAIN:", train_index, "TEST:", test_index) #These are the mutually exclusive sets from the 10 folds
    X_train, X_test = X[train_index], X[test_index]
    y_train, y_test = y[train_index], y[test_index]
    y_pred = classifier.predict(X_test)
    accuracy = accuracy_score(y_test, y_pred)
    a += accuracy
print("\nK-fold cross validation (10 folds): " + str(a / 10))
