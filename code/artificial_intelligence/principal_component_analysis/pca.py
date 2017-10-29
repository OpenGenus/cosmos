'''
Solution to Principal Component Analysis Inspired by http://sebastianraschka.com/Articles/2014_pca_step_by_step.html
Solution is proposed for Python 3, using numpy and matplotlib
'''

import numpy as np

# generate a random seed
# np.random.seed(782384239784)


def generate_data(mean_value):
    ''' Generate 3x20 datasets for PCA '''
    # mean vector
    mu_vec1 = mean_value * np.ones(3)
    # covariance matrix
    cov_mat1 = np.array([[1,0,0],[0,1,0],[0,0,1]])
    # generate uniformed distributed samples over the mean mu_vec
    class_sample = np.random.multivariate_normal(mu_vec1, cov_mat1, 20).T
    assert class_sample.shape == (3,20), "The matrix has not the dimensions 3x20"
    return class_sample

from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d import proj3d

def visualize_data(data1, data2):
    ''' Create a 3D plot for data visualization '''
    fig = plt.figure(figsize=(8,8))
    ax = fig.add_subplot(111, projection='3d')
    plt.rcParams['legend.fontsize'] = 10
    ax.plot(data1[0,:], data1[1,:], data1[2,:], 'o', markersize=8, color='blue', alpha=0.5, label='class1')
    ax.plot(data2[0,:], data2[1,:], data2[2,:], '^', markersize=8, alpha=0.5, color='red', label='class2')

    plt.title('Samples for class 1 and class 2')
    ax.legend(loc='upper right')

    plt.show()

def main():
    # generate a mean 0 data
    class1_sample = generate_data(0)
    # generate a mean 1 data
    class2_sample = generate_data(1)
    # visualize data
    visualize_data(class1_sample, class2_sample)


if __name__ == "__main__":
    main()
