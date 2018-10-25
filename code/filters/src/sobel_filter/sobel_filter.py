"""
Sobel filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheusguimr)
"""


import cv2
import math as mt
import numpy as np
from matplotlib import pyplot as ppl


def set_kernel(direction):
    sobel_kernel = 0
    if direction:
        sobel_kernel = np.array([[-1, 0, 1],
                                 [-2, 0, 2],
                                 [-1, 0, 1]])
    elif not direction:
        sobel_kernel = np.array([[-1, -2, -1],
                                 [0, 0, 0],
                                 [1, 2, 1]])
    return sobel_kernel


def get_sobel_filter(gray):
    bd = int(np.ndim(gray) / 2)
    kernel_x = set_kernel(False)
    kernel_y = set_kernel(True)
    sob_x = np.zeros(gray.shape, dtype=np.int16)
    sob_y = np.zeros(gray.shape, dtype=np.int16)
    sob_conv = np.zeros(gray.shape, dtype=np.int16)
    for i in range(bd, gray.shape[0] - bd):
        for j in range(bd, gray.shape[1] - bd):
            conv_x = gray[i - bd:i + bd + 1, j - bd:j + bd + 1] * kernel_x
            conv_y = gray[i - bd:i + bd + 1, j - bd:j + bd + 1] * kernel_y
            sob_x[i][j] = np.sum(conv_x)
            sob_y[i][j] = np.sum(conv_y)
            sob_conv[i][j] = mt.sqrt(pow(sob_y[i][j], 2) + pow(sob_x[i][j], 2))
    return sob_conv, sob_y, sob_x


if __name__ == '__main__':
    # Read image
    img = cv2.imread('lena.jpg')
    # Convert image for gray scale
    gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Pass image to function
    sobel, sobel_vertical, sobel_horizontal = get_sobel_filter(gray_img)

    # Show the images
    fig = ppl.figure()
    ppl.subplot(1, 3, 1), ppl.imshow(sobel_horizontal, 'gray')
    ppl.subplot(1, 3, 2), ppl.imshow(sobel_vertical, 'gray')
    ppl.subplot(1, 3, 3), ppl.imshow(sobel, 'gray')
    ppl.show()

