# Implementation of DecisionTreeClassification on BreastCancerData


import matplotlib.pyplot as plt
from sklearn.tree import DecisionTreeClassifier
from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score, roc_auc_score,classification_report
from sklearn.decomposition import PCA
import pandas as pd
from utils.utils_scores import scores

flag_pca = False

data, target = load_breast_cancer(return_X_y=True)
data = pd.DataFrame(data)
target = pd.DataFrame(target)

if flag_pca:
    pca = PCA()
    data = pca.fit_transform(data)

data_train, data_test, target_train, target_test = train_test_split(data, target, test_size=0.1,random_state=0)

DecisionTreeClassifierObject = DecisionTreeClassifier()
DecisionTreeClassifierObject.fit(data_train, target_train)

target_test_predict = DecisionTreeClassifierObject.predict(data_test)
scores(target_test,target_test_predict)




