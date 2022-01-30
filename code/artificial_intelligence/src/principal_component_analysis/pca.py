"""
Solution to Principal Component Analysis Inspired by http://sebastianraschka.com/Articles/2014_pca_step_by_step.html
Solution is proposed for Python 3, using numpy and matplotlib

The PCA approach may be summerized according to these steps:
1. Take the whole dataset consisting of dd-dimensional samples ignoring the class labels
2. Compute the dd-dimensional mean vector (i.e., the means for every dimension of the whole dataset)
3. Compute the scatter matrix (alternatively, the covariance matrix) of the whole data set
4. Compute eigenvectors and corresponding eigenvalues
5. Sort the eigenvectors by decreasing eigenvalues and choose kk eigenvectors with the largest eigenvalues.
6. Use this d×kd×k eigenvector matrix to transform the samples onto the new subspace.
"""

import numpy as np

# Visualization ------------------------------------------------------------
from matplotlib import pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from mpl_toolkits.mplot3d import proj3d
from matplotlib.patches import FancyArrowPatch


def visualize_data(data1, data2):
    """ Create a 3D plot for data visualization """
    fig = plt.figure(figsize=(8, 8))
    ax = fig.add_subplot(111, projection="3d")
    plt.rcParams["legend.fontsize"] = 10
    ax.plot(
        data1[0, :],
        data1[1, :],
        data1[2, :],
        "o",
        markersize=8,
        color="blue",
        alpha=0.5,
        label="class1",
    )
    ax.plot(
        data2[0, :],
        data2[1, :],
        data2[2, :],
        "^",
        markersize=8,
        alpha=0.5,
        color="red",
        label="class2",
    )
    ax.set_xlabel("x_values")
    ax.set_ylabel("y_values")
    ax.set_zlabel("z_values")

    plt.title("Samples for class 1 and class 2")
    ax.legend(loc="upper right")

    plt.show()


class Arrow3D(FancyArrowPatch):
    """ Arrow graphics class """

    def __init__(self, xs, ys, zs, *args, **kwargs):
        FancyArrowPatch.__init__(self, (0, 0), (0, 0), *args, **kwargs)
        self._verts3d = xs, ys, zs

    def draw(self, renderer):
        xs3d, ys3d, zs3d = self._verts3d
        xs, ys, zs = proj3d.proj_transform(xs3d, ys3d, zs3d, renderer.M)
        self.set_positions((xs[0], ys[0]), (xs[1], ys[1]))
        FancyArrowPatch.draw(self, renderer)


def visualize_eigen(data, eig_vec_sc):
    """ Create 3D representation of the eigenvectors computed """
    # separate mean vector components
    mean_x = np.mean(data[0, :])
    mean_y = np.mean(data[1, :])
    mean_z = np.mean(data[2, :])
    # create figure
    fig = plt.figure(figsize=(7, 7))
    ax = fig.add_subplot(111, projection="3d")
    # plot eigen vectors centered at the mean value of the dataset
    ax.plot(
        data[0, :], data[1, :], data[2, :], "o", markersize=8, color="green", alpha=0.2
    )
    ax.plot([mean_x], [mean_y], [mean_z], "o", markersize=10, color="red", alpha=0.5)
    for v in eig_vec_sc.T:
        a = Arrow3D(
            [mean_x, v[0]],
            [mean_y, v[1]],
            [mean_z, v[2]],
            mutation_scale=20,
            lw=3,
            arrowstyle="-|>",
            color="r",
        )
        ax.add_artist(a)
    ax.set_xlabel("x_values")
    ax.set_ylabel("y_values")
    ax.set_zlabel("z_values")

    plt.title("Eigenvectors")

    plt.show()


def visulize_pca(transformed):
    """
        2D visualization of the principal components to evidence the dimensionality reduction.
        The markers shows different classes of the original normalized_distributed_data().
        Its valuable to notice that class classification is not made by the PCA.
    """
    plt.plot(
        transformed[0, 0:20],
        transformed[1, 0:20],
        "o",
        markersize=7,
        color="blue",
        alpha=0.5,
        label="class1",
    )
    plt.plot(
        transformed[0, 20:40],
        transformed[1, 20:40],
        "^",
        markersize=7,
        color="red",
        alpha=0.5,
        label="class2",
    )
    plt.xlim([-4, 4])
    plt.ylim([-4, 4])
    plt.xlabel("PC 1")
    plt.ylabel("PC 2")
    plt.legend()
    plt.title("Transformed samples with class labels")

    plt.show()


# Data Generation ------------------------------------------------------------
def normalized_distributed_data(mean_value):
    """ Generate 3x20 datasets for PCA """
    # mean vector
    mu_vec1 = mean_value * np.ones(3)
    # covariance matrix
    cov_mat1 = np.array([[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    # generate uniformed distributed samples over the mean mu_vec
    class_sample = np.random.multivariate_normal(mu_vec1, cov_mat1, 20).T
    assert class_sample.shape == (3, 20), "The matrix has not the dimensions 3x20"
    return class_sample


# PCA subroutines -----------------------------------------------------------
def generate_data():
    """
        Combine two 3x20 datasets ignoring their labels.
        This is the data which will be analyzed by the PCA algorithm
    """
    # generate a mean 0 data
    class1_sample = normalized_distributed_data(0)
    # generate a mean 1 data
    class2_sample = normalized_distributed_data(1)
    # visualize data
    visualize_data(class1_sample, class2_sample)
    # combine them into one structure
    data = np.concatenate((class1_sample, class2_sample), axis=1)
    assert data.shape == (3, 40), "The matrix has not the dimensions 3x40"
    return data


def compute_mean_vector(data):
    """ Compute the mean vector for the dataset """
    mean_x = np.mean(data[0, :])
    mean_y = np.mean(data[1, :])
    mean_z = np.mean(data[2, :])

    mean_vector = np.array([[mean_x], [mean_y], [mean_z]])
    print("Mean Vector:\n", mean_vector)

    return mean_vector


def compute_scatter_matrix(data, mean_vector):
    """ Compute scatter matrix values """
    scatter_matrix = np.zeros((3, 3))
    for i in range(data.shape[1]):
        scatter_matrix += (data[:, i].reshape(3, 1) - mean_vector).dot(
            (data[:, i].reshape(3, 1) - mean_vector).T
        )
    print("Scatter Matrix:\n", scatter_matrix)
    return scatter_matrix


def compute_covariance_matrix(data):
    """ Compute covariance matrix, an alternative to scatter matrix """
    cov_mat = np.cov([data[0, :], data[1, :], data[2, :]])
    print("Covariance Matrix:\n", cov_mat)
    return cov_mat


def verify_eigen_values(scatter_matrix, eig_val_sc, eig_vec_sc):
    """
        Verify if the eigen values of the scatter matrix were made correctly.
        Test consists in asserting that the covariance and eigen vector product equals the eigen value and eigen vector.
    """
    for i in range(len(eig_val_sc)):
        eigv = eig_vec_sc[:, i].reshape(1, 3).T
        np.testing.assert_array_almost_equal(
            scatter_matrix.dot(eigv),
            eig_val_sc[i] * eigv,
            decimal=6,
            err_msg="",
            verbose=True,
        )
    # test eigen vectors module to equal one
    for ev in eig_vec_sc:
        np.testing.assert_array_almost_equal(1.0, np.linalg.norm(ev))
    return True


def compute_eigen(scatter_matrix, cov_mat):
    """ Compute eigen vectors and corresponding eigen values for the scatter and covariance matrix """
    # eigenvectors and eigenvalues for the from the scatter matrix
    eig_val_sc, eig_vec_sc = np.linalg.eig(scatter_matrix)

    # eigenvectors and eigenvalues for the from the covariance matrix
    eig_val_cov, eig_vec_cov = np.linalg.eig(cov_mat)

    for i in range(len(eig_val_sc)):
        eigvec_sc = eig_vec_sc[:, i].reshape(1, 3).T
        eigvec_cov = eig_vec_cov[:, i].reshape(1, 3).T
        # assert if the scatter_matrix and covariance matrix eigen vectors are identical
        assert eigvec_sc.all() == eigvec_cov.all(), "Eigenvectors are not identical"

        print("Eigenvector {}: \n{}".format(i + 1, eigvec_sc))
        print("Eigenvalue {} from scatter matrix: {}".format(i + 1, eig_val_sc[i]))
        print("Eigenvalue {} from covariance matrix: {}".format(i + 1, eig_val_cov[i]))
        print("Scaling factor: ", eig_val_sc[i] / eig_val_cov[i])
        print(40 * "-")

    verify_eigen_values(scatter_matrix, eig_val_sc, eig_vec_sc)

    return eig_val_sc, eig_vec_sc


def sort_eigen_vectors(eigen_vec, eigen_val):
    """
        Sort eigen vectors by decreasing eigenvalues.
        Eigen vectors with lower eigenvalues hold less information about the data distribution.
    """
    # Make a list of (eigenvalue, eigenvector) tuples
    eig_pairs = [(np.abs(eigen_val[i]), eigen_vec[:, i]) for i in range(len(eigen_val))]

    # Sort the (eigenvalue, eigenvector) tuples from high to low
    eig_pairs.sort(key=lambda x: x[0], reverse=True)

    # Visually confirm that the list is correctly sorted by decreasing eigenvalues
    print("Eigen values ordered in decreasing order:")
    for pair in eig_pairs:
        print(pair[0])

    return eig_pairs


def get_2_largest_eigen_vectors(eigen_vec, eigen_val):
    """
        Return 2 principal components eigen vectors.
        The decision of which vectors are principals is made by their sorting
    """
    eig_pairs = sort_eigen_vectors(eigen_vec, eigen_val)
    # combine the two highest eigen vectors into matrix_w
    matrix_w = np.hstack((eig_pairs[0][1].reshape(3, 1), eig_pairs[1][1].reshape(3, 1)))
    print("Matrix W:\n", matrix_w)
    return matrix_w


def principal_subspace_transformation(data, matrix_w):
    """ Transform data into a new subspace through the equation: transformed = matrix_w' * data """
    transformed = matrix_w.T.dot(data)
    assert transformed.shape == (2, 40), "The matrix is not 2x40 dimensional."
    return transformed


def main():
    """ Main function to perform Principal Component Analysis"""
    # 1. Take the whole dataset consisting of dd-dimensional samples ignoring the class labels
    all_samples = generate_data()
    # 2. Compute the dd-dimensional mean vector (i.e., the means for every dimension of the whole dataset)
    mean_vector = compute_mean_vector(all_samples)
    # 3. Compute the scatter matrix (alternatively, the covariance matrix) of the whole data set
    scatter_matrix = compute_scatter_matrix(all_samples, mean_vector)
    cov_mat = compute_covariance_matrix(all_samples)
    # 4. Compute eigenvectors and corresponding eigenvalues
    eigen_val, eigen_vec = compute_eigen(scatter_matrix, cov_mat)
    visualize_eigen(all_samples, eigen_vec)
    # 5. Sort the eigenvectors by decreasing eigenvalues and choose kk eigenvectors with the largest eigenvalues.
    matrix_w = get_2_largest_eigen_vectors(eigen_vec, eigen_val)
    # 6. Use this d×kd×k eigenvector matrix to transform the samples onto the new subspace.
    transformed = principal_subspace_transformation(all_samples, matrix_w)
    visulize_pca(transformed)


if __name__ == "__main__":
    main()
