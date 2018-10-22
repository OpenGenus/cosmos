"""
Mean filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheusguimr)
"""


import cv2
import numpy as np


def get_mean_filter(gray_image, mask_size=3):
    bord = int(mask_size / 2)
    # Create a copy of the original image
    mean_filter = gray_image[:, :].copy()
    for i in range(bord, gray_image.shape[0] - bord):
        for j in range(bord, gray_image.shape[1] - bord):
            # Create a 3x3 convolution matrix
            kernel = gray_image[i - bord:i + bord + 1, j - bord:j + bord + 1]
            # Get the kernel mean
            mean_filter[i, j] = int(np.mean(kernel, dtype=np.float32))
    return mean_filter


if __name__ == '__main__':
    # Read image
    img = cv2.imread('lena.jpg')
    # Convert image for gray scale
    gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Pass images to function
    mean_img_3x3 = get_mean_filter(gray_img, 3)
    mean_img_5x5 = get_mean_filter(gray_img, 5)

    # Show the images
    cv2.imshow('mask 3x3', mean_img_3x3)
    cv2.imshow('mask 5x5', mean_img_5x5)
    cv2.waitKey(0)

