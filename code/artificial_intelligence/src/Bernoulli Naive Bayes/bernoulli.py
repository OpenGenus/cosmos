mport numpy as np
from sklearn.naive_bayes import BernoulliNB 
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt

#creating dataset with with 0 and 1

X = np.random.randint(2, size=(500,10))
Y = np.random.randint(2, size=(500, 1))

X_test = X[:50, :10]
y_test = Y[:50, :1]

clf = BernoulliNB()
model = clf.fit(X, Y)

y_pred =clf.predict(X_test)
acc_score = accuracy_score(y_test, y_pred)
print(acc_score)

plt.scatter(X[:, 0], X[:, 1], c=y, s=50, cmap='RdBu')
l = plt.axis()
plt.scatter(Xtest[:, 0], Xtest[:, 1], c=Ytest, s=20, cmap='RdBu', alpha=0.1)
plt.axis(l);
