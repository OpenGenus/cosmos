import numpy as np


class svm:
    def __init__(self):
        self.b = None
        self.t = None
        self.count = None
        self._lambda = None

    def train(self, xtrain, ytrain, count, _lambda):
        self.count = count
        self.b = []
        for i in range(0, len(xtrain[0])):
            self.b.append(0.0)
        self.t = 1
        self._lambda = _lambda
        for i in range(self.count):
            for j in range(len(xtrain)):
                output = ytrain[j] * xtrain[j][0] * self.b[0]
                for k in range(1, len(xtrain[0])):
                    output = output + xtrain[j][k] * self.b[k]

                if output > 1:
                    for k in range(0, len(xtrain[0])):
                        self.b[k] = self.b[k] * (
                            1 - (1 / self.t)
                        )  # /(self._lambda*self.t)
                else:
                    for k in range(0, len(xtrain[0])):
                        self.b[k] = self.b[k] * (1 - (1 / self.t)) + (
                            ytrain[j] * xtrain[j][k]
                        ) / (self._lambda * self.t)
                self.t = self.t + 1

    def predict(self, xtest):
        p_array = []
        for i in range(len(xtest)):
            output = 0
            for j in range(len(xtest[0])):
                output = output + self.b[j] * xtest[i][j]
            if output < 0:
                p_array.append(-1)
            else:
                p_array.append(1)

        return p_array


xtrain = [
    [2.327868056, 2.458016525],
    [3.032830419, 3.170770366],
    [4.485465382, 3.696728111],
    [3.684815246, 3.846846973],
    [2.283558563, 1.853215997],
    [7.807521179, 3.290132136],
    [6.132998136, 2.140563087],
    [7.514829366, 2.107056961],
    [5.502385039, 1.404002608],
    [7.432932365, 4.236232628],
]
ytrain = [-1, -1, -1, -1, -1, 1, 1, 1, 1, 1]

clf = svm()
clf.train(xtrain, ytrain, 16, 0.5)
print(clf.predict(xtrain))
