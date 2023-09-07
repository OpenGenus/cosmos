"""
Laplacian filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheustguimaraes)
"""


from cv2 import imread, cvtColor, COLOR_BGR2GRAY
from matplotlib.pyplot import figure, subplot, imshow, show
from numpy import array, zeros, sum, int16


def set_kernel(type_temp):
    laplacian_kernel = 0
    if type_temp == 3:
        laplacian_kernel = array([[1, 1, 1], [1, -8, 1], [1, 1, 1]])
    elif type_temp == 5:
        laplacian_kernel = array(
            [
                [-1, -1, -1, -1, -1],
                [-1, -1, -1, -1, -1],
                [-1, -1, 24, -1, -1],
                [-1, -1, -1, -1, -1],
                [-1, -1, -1, -1, -1],
            ]
        )
    return laplacian_kernel


def get_laplacian_filter(gray, matrix_type):
    bd = int(matrix_type / 2)
    matrix = set_kernel(matrix_type)
    laplacian_image = zeros(gray.shape, dtype=int16)
    for i in range(bd, gray.shape[0] - bd):
        for j in range(bd, gray.shape[1] - bd):
            kernel = gray[i - bd: i + bd + 1, j - bd: j + bd + 1] * matrix
            laplacian_image[i, j] = sum(kernel)
    return laplacian_image


if __name__ == "__main__":
    # Read image
    img = imread("lena.jpg")
    # Convert image for gray scale
    gray_img = cvtColor(img, COLOR_BGR2GRAY)

    # Pass image to function
    filter_3x3 = get_laplacian_filter(gray_img, 3)
    filter_5x5 = get_laplacian_filter(gray_img, 5)

    # Show the images
    fig = figure()
    subplot(1, 3, 1), imshow(gray_img, "gray")
    subplot(1, 3, 2), imshow(filter_3x3, "gray")
    subplot(1, 3, 3), imshow(filter_3x3, "gray")
    show()
