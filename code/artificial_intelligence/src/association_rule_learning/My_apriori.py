# Part of Cosmos by OpenGenus Foundation

#Apriori

#importing libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('dataset.csv', header = None)

transactions = []
for i in range(0,7501):
    transactions.append([str(dataset.values[i,j]) for j in range (0,20)])


#Training apriori on dataset
from apyori import apriori
rules = apriori(transactions, min_support = 0.003 , min_confidence = 0.2, min_lift = 3, min_length = 2)

#Visualising

results = list(rules)

def inspect(results):
    rh          = [tuple(result[2][0][0]) for result in results]
    lh          = [tuple(result[2][0][1]) for result in results]
    supports    = [result[1] for result in results]
    confidences = [result[2][0][2] for result in results]
    lifts       = [result[2][0][3] for result in results]
    return list(zip(rh, lh, supports, confidences, lifts))

# this command creates a data frame to view
resultDataFrame=pd.DataFrame(inspect(results),
                columns=['rhs','lhs','support','confidence','lift'])