# Implementation of LogisiticRegression on BreastCancerData


import matplotlib.pyplot as plt
from sklearn.linear_model import LogisticRegression
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score, roc_auc_score,classification_report
from sklearn.decomposition import PCA
import pandas as pd

flag_pca = False

data, target = load_breast_cancer(return_X_y=True)
data = pd.DataFrame(data)
target = pd.DataFrame(target)

if flag_pca:
    pca = PCA()
    data = pca.fit_transform(data)

data_train, data_test, target_train, target_test = train_test_split(data, target, test_size=0.1,random_state=0)

LogisticRegressionObject = LogisticRegression()
LogisticRegressionObject.fit(data_train, target_train)

target_test_predict = LogisticRegressionObject.predict(data_test)

classreport = classification_report(target_test, target_test_predict
print("Classification Report \n {}\n ".format(classreport))


