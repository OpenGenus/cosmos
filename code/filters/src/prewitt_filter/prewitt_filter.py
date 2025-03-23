from cv2 import imread, cvtColor, COLOR_BGR2GRAY
from matplotlib import pyplot as plt
from math import sqrt
import numpy as np


def set_kernel(direction):
    """
    Set prewitt kernel directions
    :param direction: np.array
    :return: np.array
    """
    if direction:
        kernel = np.array([[-1, 0, 1],
                           [-1, 0, 1],
                           [-1, 0, 1]])
    else:
        kernel = np.array([[-1, -1, -1],
                           [0, 0, 0],
                           [1, 1, 1]])
    return kernel


def get_prewitt_filter(image):
    """
    Prewitt filter
    :param image: np.array
    :return: prewitt, prewitt vertical and prewitt horizontal (all are np.array)
    """
    # Image borders
    border = int(3 / 2)
    # Vertical and horizontal Prewitt directions
    ker_x = set_kernel(False)
    ker_y = set_kernel(True)
    # Vertical and horizontal Prewitt images
    pre_x = np.zeros(image.shape, dtype=np.int16)
    pre_y = np.zeros(image.shape, dtype=np.int16)
    # Final Prewitt image
    prewitt = np.zeros(image.shape, dtype=np.int16)
    for i in range(border, image.shape[0] - border):
        for j in range(border, image.shape[1] - border):
            # Row intervals
            row_ini = i - border
            row_end = i + border + 1
            # Column intervals
            col_ini = j - border
            col_end = j + border + 1
            # Convolution matrix in each iteration
            img_matrix = image[row_ini:row_end, col_ini:col_end]
            # Calculate Vertical and horizontal Prewitt sum
            pre_x[i][j] = np.sum(img_matrix * ker_x)
            pre_y[i][j] = np.sum(img_matrix * ker_y)
            # Calculate combined Prewitt filter
            prewitt[i][j] = sqrt(pow(pre_y[i][j], 2) + pow(pre_x[i][j], 2))
    return prewitt, pre_y, pre_x


if __name__ == '__main__':
    img = imread('lena.jpg')
    gray_img = cvtColor(img, COLOR_BGR2GRAY)
    # Get prewitt filters
    prewitt, prewitt_vert, prewitt_horiz = get_prewitt_filter(gray_img)
    # Add all images in list, to plot
    images = [gray_img, prewitt, prewitt_vert, prewitt_horiz]
    # Plot original image, and all prewitt filters
    fig = plt.figure(0)
    titles = ['Gray Image', 'Total', 'Vertical', 'Horizontal']
    for x in range(len(images)):
        plt.subplot(2, 2, x + 1)
        plt.imshow(images[x], 'gray')
        plt.title(titles[x])
        plt.axis('off')
    plt.show()
    plt.close()
