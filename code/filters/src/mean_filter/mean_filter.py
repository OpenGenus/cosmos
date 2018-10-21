"""
Mean filter algorithm
Part of Cosmos by OpenGenus Foundation
Author: Matheus Guimaraes (@matheusguimr)
"""

import cv2
import numpy as np
from matplotlib import pyplot as plt


def get_mean_filter(gray_image, mask_size=3):
    borders = int(mask_size / 2)
    # Create a copy of the original image
    mean_filter = gray_image[:, :].copy()
    for i in range(borders, gray_image.shape[0] - borders):
        for j in range(borders, gray_image.shape[1] - borders):
            # Create a 3x3 convolution matrix around the central value of the position 'i' and 'j'
            kernel = gray_image[i - borders:i + borders + 1, j - borders:j + borders + 1]
            # Get the mean of the kernel and store in the result image of the convolution
            mean_filter[i, j] = int(np.mean(kernel, dtype=np.float32))
    return mean_filter


if __name__ == '__main__':
    # Read image
    img = cv2.imread('../samples/lena.jpg')
    # Convert image for gray scale
    gray_img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    images = []
    iterator = 3
    images.append(gray_img)
    # Pass images five times, with the mask value increasing, starting with 3x3 until 11x11
    for k in range(0, 5):
        # Save each value in a list
        images.append(get_mean_filter(gray_img, iterator))
        iterator += 2

    # Plot images in a figure to see the results
    fig = plt.figure(0)
    titles = ['Gray Image', '3x3 mask', '5x5 mask', '7x7 mask', '9x9 mask', '11x11 mask']
    for x in range(len(images)):
        plt.subplot(2, 3, x + 1), plt.imshow(images[x], 'gray')
        plt.title(titles[x])
        plt.axis('off')
        # Save each image
        cv2.imwrite("../results/mean_filter_image_mask_{}.jpg".format(x + 1), images[x])

    # Save the plot image
    fig.savefig("../results/mean_filter_figure.jpg")
    plt.show()
    plt.close()
