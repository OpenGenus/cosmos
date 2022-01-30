import numpy as np


def matrix_factorization(data, K, steps=5000, beta=0.0002, lamda=0.02):

    W = np.random.rand(data.shape[0], K)
    H = np.random.rand(data.shape[1], K)
    # W = np.random.normal(scale=1./K, size = (data.shape[0], K))
    # H = np.random.normal(scale=1./K, size = (data.shape[1], K))

    H = H.T

    b_u = np.zeros(data.shape[0])

    for i in range(len(data)):
        # print("len",len(np.where(data[i] != 0)[0]))
        if len(np.where(data[i] != 0)[0]) == 0:
            b_u[i] = 0
        else:
            b_u[i] = np.mean(data[i][np.where(data[i] != 0)])
        # print(b_u[i])

    b_i = np.zeros(data.shape[1])
    for i in range(len(data.T)):
        if len(np.where(data.T[i] != 0)[0]) == 0:
            b_i[i] = 0
        else:
            b_i[i] = np.mean(data.T[i][np.where(data.T[i] != 0)])

        # b_i[i] = np.mean(data.T[i][np.where(data.T[i] != 0)])
        # print(b_i[i])

    b = np.mean(data[np.where(data != 0)])

    # i : user
    # j : item

    for step in range(steps):
        for i in range(len(data)):
            for j in range(len(data[i])):
                if data[i][j] > 0:
                    p_bar = b + b_u[i] + b_i[j] + np.dot(W[i, :], H[:, j])

                    eij = data[i][j] - p_bar

                    b = b + beta * eij

                    b_u[i] += beta * (eij - lamda * b_u[i])
                    b_i[j] += beta * (eij - lamda * b_i[j])

                    """
                    for k in range(K):
                        P[i][k] = P[i][k] + beta * (2 * eij * Q[k][j] - lamda * P[i][k])
                        Q[k][j] = Q[k][j] + beta * (2 * eij * P[i][k] - lamda * Q[k][j])
                    """
                    W[i, :] += beta * (2 * eij * H[:, j] - lamda * W[i, :])
                    H[:, j] += beta * (2 * eij * W[i, :] - lamda * H[:, j])

        edata = np.dot(W, H)
        e = 0
        for i in range(len(data)):
            for j in range(len(data[i])):
                if data[i][j] > 0:
                    e = e + pow(data[i][j] - np.dot(W[i, :], H[:, j]), 2)
                    for k in range(K):
                        e = e + (lamda / 2) * (pow(W[i][k], 2) + pow(H[k][j], 2))

        if e < 0.001:
            print("Epsilon's exit")
            break
    return W, H.T, b_u, b_i, b


def readFile(fileString):
    return np.loadtxt(fileString, delimiter=" ", dtype="int").tolist()


if __name__ == "__main__":
    fileString = r"/home/ledsinh/test.txt"
    """
    You can read the matrix in many dismension

    """
    data = readFile(fileString)

    data = np.array(data)
    print(data)
    K = 2

    W, H, b_u, b_i, b = matrix_factorization(data, K)
    print("Matrix Factorization with Bias")
    fitted = b + W.dot(H.T) + b_u[:, np.newaxis] + b_i[np.newaxis, :]

    for i in fitted:
        print(np.around(i, decimals=2))
    # print(fitted)
