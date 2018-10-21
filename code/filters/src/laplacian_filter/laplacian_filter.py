"""
Laplacian filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheusguimr)
"""

import cv2
import numpy as np


def set_kernel(type_kernel):
    laplacian_kernel = 0
    if type_kernel == 3:
        laplacian_kernel = np.array([[1, 1, 1],
                                     [1, -8, 1],
                                     [1, 1, 1]])
    elif type_kernel == 5:
        laplacian_kernel = np.array([[-1, -1, -1, -1, -1],
                                     [-1, -1, -1, -1, -1],
                                     [-1, -1, 24, -1, -1],
                                     [-1, -1, -1, -1, -1],
                                     [-1, -1, -1, -1, -1]])
    return laplacian_kernel


def get_laplacian_filter(gray_image, matrix_type):
    borders = int(matrix_type / 2)
    laplacian_kernel = set_kernel(matrix_type)
    laplacian_image = np.zeros(gray_image.shape, dtype=np.int16)
    for i in range(borders, gray_image.shape[0] - borders):
        for j in range(borders, gray_image.shape[1] - borders):
            kernel = gray_image[i - borders:i + borders + 1, j - borders:j + borders + 1] * laplacian_kernel
            laplacian_image[i, j] = np.sum(kernel)
    return laplacian_image


if __name__ == '__main__':
    img = cv2.imread('lena.jpg')
    gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    laplacian_filter_3x3 = get_laplacian_filter(gray_img, 3)
    laplacian_filter_5x5 = get_laplacian_filter(gray_img, 5)

    cv2.imshow('Original image', img)
    cv2.imshow('Laplacian filter with 3x3 mask', laplacian_filter_3x3)
    cv2.imshow('Laplacian filter with 5x5 mask', laplacian_filter_5x5)
    cv2.waitKey(0)
