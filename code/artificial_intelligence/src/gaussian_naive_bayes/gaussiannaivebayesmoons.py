############################################################################
############################################################################

# Importing necessary packages
import numpy as np
import scipy
import matplotlib.pyplot as plt
from sklearn.utils import check_random_state
from sklearn.utils import shuffle as util_shuffle
from sklearn.preprocessing import scale
from pandas import DataFrame


############################################################################
############################################################################
def make_moons(n_samples=100, shuffle=True, noise=None, random_state=None):
    """Make two interleaving half circles
    A simple toy dataset to visualize clustering and classification
    algorithms. Read more in the :ref:`User Guide <sample_generators>`.
    Parameters
    ----------
    n_samples : int, optional (default=100)
        The total number of points generated.
    shuffle : bool, optional (default=True)
        Whether to shuffle the samples.
    noise : double or None (default=None)
        Standard deviation of Gaussian noise added to the data.
    random_state : int, RandomState instance or None, optional (default=None)
        If int, random_state is the seed used by the random number generator;
        If RandomState instance, random_state is the random number generator;
        If None, the random number generator is the RandomState instance used
        by `np.random`.
    Returns
    -------
    X : array of shape [n_samples, 2]
        The generated samples.
    y : array of shape [n_samples]
        The integer labels (0 or 1) for class membership of each sample.
    """
    n_samples_out = n_samples // 2  # Floor division
    n_samples_in = n_samples - n_samples_out  # splitting it into two halves

    generator = check_random_state(random_state)

    outer_circ_x = np.cos(np.linspace(0, np.pi, n_samples_out))
    outer_circ_y = np.sin(np.linspace(0, np.pi, n_samples_out))
    inner_circ_x = 1 - np.cos(np.linspace(0, np.pi, n_samples_in))
    inner_circ_y = 1 - np.sin(np.linspace(0, np.pi, n_samples_in)) - 1

    X = np.vstack(
        (np.append(outer_circ_x, inner_circ_x), np.append(outer_circ_y, inner_circ_y))
    ).T
    y = np.hstack(
        [np.zeros(n_samples_out, dtype=np.intp), np.ones(n_samples_in, dtype=np.intp)]
    )

    if shuffle:
        X, y = util_shuffle(X, y, random_state=generator)

    if noise is not None:
        X += generator.normal(scale=noise, size=X.shape)

    return X, y


############################################################################
# generating 2D classification dataset

crts, Class = make_moons(n_samples=2000, noise=0.08, random_state=0)

Class = Class + 1

df = DataFrame(dict(x=crts[:, 0], y=crts[:, 1], label=Class))


colors = {1: "red", 2: "blue"}
fig, ax = plt.subplots()

############################################################################
############################################################################
# Separating the co ordinates according to the classes CLASSES 1 followed by CLASSES 2
grouped = df.groupby("label")


u = []  # The MEAN
gX = []  # Group

for key, group in grouped:
    gX.append(group.values)
    u.append(group.mean().values)

    group.plot(ax=ax, kind="scatter", x="x", y="y", label=key, color=colors[key])

plt.savefig("graph.png")


gX = np.array(gX)
print(gX)

############################################################################

X = gX[:, :, -2]
Y = gX[:, :, -1]
classes = gX[:, :, -3]

print("Classes")
classes = np.hstack(classes)
print(classes)

print("Xh")
Xh = np.hstack(X)
print(Xh)

print("Yh")
Yh = np.hstack(Y)
print(Yh)

print("XY")
XY = np.column_stack((Xh, Yh))
print(XY)

############################################################################
# Calculating Covariance
print("Covariance")
C = np.cov(Xh, Yh)
print(C)

print("Cinv")
Cinv = np.linalg.inv(C)
print(Cinv)

############################################################################
############################################################################
"""
The Gaussain Bayes Classifier is:

log (Likelihood Ratio ^) = W' * X + b
    where

    W = (u1 - u2)' * Cinv * X
    b = 0.5 * ((u2' * Cinv * u2) - (u1' * Cinv * u1))


Now, if the Likelihood Ratio is:
            Greater than 1? Class 0 Txt Book Class 1
            Lesser  than 1? Class 1 Txt Book Class 2

Now, if the Logarithm of the Likelihood Ratio is:
            Greater than log(1) = 0? Class 0 Txt Book Class 1
            Lesser  than log(1) = 0? Class 1 Txt Book Class 2

"""
############################################################################
############################################################################
# Finding W

mask = [False, True, True]

u1 = u[0]  # Mean of Class 1
u2 = u[1]  # Mean of Class 2


u1 = u1[mask]
u2 = u2[mask]


print("u1 - u2")
print((u1 - u2).T.shape)
############################################################################

stage1W = np.asmatrix(np.dot((u1 - u2).T, Cinv))
print("stage1W")
print(stage1W.shape)

print("W")
W = np.dot(stage1W, XY.T)
print(W)

print("Weight W: ")
print(W.shape)

############################################################################
############################################################################
# Finding b
u1 = np.asmatrix(u1)

u2 = np.asmatrix(u2)


print("Stage 1b")
stage11b = np.dot(u2, Cinv)
stage1b = np.dot(stage11b, u2.T)
stage1b = np.asscalar(np.array(stage1b))

print("Stage 2b")
stage22b = np.dot(u1, Cinv)
stage2b = np.dot(stage22b, u1.T)
stage2b = np.asscalar(np.array(stage2b))

b = 0.5 * (stage1b - stage2b)

print("Bias b: ")
print(b)

############################################################################
############################################################################
# Calculating error rate
print("xtest")
xtest = XY[:, 0]
xtest = np.asmatrix(xtest)
print(xtest.shape)


ytest = np.multiply(W, xtest)
ytest = np.add(ytest, b)
print(ytest)

# ERROR CLASSIFICATION
print("CLASSIFICATION")
ytest[ytest > 0] = 1
ytest[ytest < 1] = 2
print(ytest)

print(classes)

error = ytest - classes

SQE = np.power(error, [2])
ERR = np.sum(SQE)

print("CLASSIFICATION ERROR RATE:")
MSE = (ERR / 2000) * 100
print(MSE)


ytest = np.subtract(ytest, [1])
ax.plot(xtest, ytest, marker="x", linewidth=10)

plt.show()

############################################################################
############################################################################
