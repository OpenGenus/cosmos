"""
Laplacian filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheusguimr)
"""


import cv2
import numpy as np
from matplotlib import pyplot as ppl


def set_kernel(type_temp):
    laplacian_kernel = 0
    if type_temp == 3:
        laplacian_kernel = np.array([[1, 1, 1],
                                     [1, -8, 1],
                                     [1, 1, 1]])
    elif type_temp == 5:
        laplacian_kernel = np.array([[-1, -1, -1, -1, -1],
                                     [-1, -1, -1, -1, -1],
                                     [-1, -1, 24, -1, -1],
                                     [-1, -1, -1, -1, -1],
                                     [-1, -1, -1, -1, -1]])
    return laplacian_kernel


def get_laplacian_filter(gray, matrix_type):
    bd = int(matrix_type / 2)
    matrix = set_kernel(matrix_type)
    laplacian_image = np.zeros(gray.shape, dtype=np.int16)
    for i in range(bd, gray.shape[0] - bd):
        for j in range(bd, gray.shape[1] - bd):
            kernel = gray[i - bd:i + bd + 1, j - bd:j + bd + 1] * matrix
            laplacian_image[i, j] = np.sum(kernel)
    return laplacian_image


if __name__ == '__main__':
    # Read image
    img = cv2.imread('lena.jpg')
    # Convert image for gray scale
    gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Pass image to function
    filter_3x3 = get_laplacian_filter(gray_img, 3)
    filter_5x5 = get_laplacian_filter(gray_img, 5)

    # Show the images
    fig = ppl.figure()
    ppl.subplot(1, 3, 1), ppl.imshow(gray_img, 'gray')
    ppl.subplot(1, 3, 2), ppl.imshow(filter_3x3, 'gray')
    ppl.subplot(1, 3, 3), ppl.imshow(filter_3x3, 'gray')
    ppl.show()

