"""
Sobel filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheustguimaraes)
"""


from math import sqrt

from cv2 import imread, cvtColor, COLOR_BGR2GRAY
from matplotlib.pyplot import figure, subplot, imshow, show
from numpy import array, ndim, zeros, sum, int16


def set_kernel(direction):
    if direction:
        sobel_kernel = array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]])
    else:
        sobel_kernel = array([[-1, -2, -1], [0, 0, 0], [1, 2, 1]])
    return sobel_kernel


def get_sobel_filter(gray):
    bd = int(ndim(gray) / 2)
    kernel_x = set_kernel(False)
    kernel_y = set_kernel(True)
    sob_x = zeros(gray.shape, dtype=int16)
    sob_y = zeros(gray.shape, dtype=int16)
    sob_conv = zeros(gray.shape, dtype=int16)
    for i in range(bd, gray.shape[0] - bd):
        for j in range(bd, gray.shape[1] - bd):
            conv_x = gray[i - bd: i + bd + 1, j - bd: j + bd + 1] * kernel_x
            conv_y = gray[i - bd: i + bd + 1, j - bd: j + bd + 1] * kernel_y
            sob_x[i][j] = sum(conv_x)
            sob_y[i][j] = sum(conv_y)
            sob_conv[i][j] = sqrt(pow(sob_y[i][j], 2) + pow(sob_x[i][j], 2))
    return sob_conv, sob_y, sob_x


if __name__ == "__main__":
    # Read image
    img = imread("lena.jpg")
    # Convert image for gray scale
    gray_img = cvtColor(img, COLOR_BGR2GRAY)

    # Pass image to function
    sobel, sobel_vertical, sobel_horizontal = get_sobel_filter(gray_img)

    # Show the images
    fig = figure()
    subplot(1, 3, 1), imshow(sobel_horizontal, "gray")
    subplot(1, 3, 2), imshow(sobel_vertical, "gray")
    subplot(1, 3, 3), imshow(sobel, "gray")
    show()
