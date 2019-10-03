##Author - Sagar Vakkala (@codezoned)

import numpy
from PIL import Image


def median_filter(data, filter_size):
    temp_arr = []
    index = filter_size // 2
    data_final = []
    data_final = numpy.zeros((len(data), len(data[0])))
    for i in range(len(data)):
        # Iterate over the Image Array
        for j in range(len(data[0])):

            for z in range(filter_size):
                if i + z - index < 0 or i + z - index > len(data) - 1:
                    for c in range(filter_size):
                        temp_arr.append(0)
                else:
                    if j + z - index < 0 or j + index > len(data[0]) - 1:
                        temp_arr.append(0)
                    else:
                        for k in range(filter_size):
                            temp_arr.append(data[i + z - index][j + k - index])

            temp_arr.sort()
            data_final[i][j] = temp_arr[len(temp_arr) // 2]
            temp_arr = []
    return data_final


def main():
    ##Replace someImage with the noise image

    img = Image.open("someImage.png").convert("L")
    arr = numpy.array(img)

    ##3 defines the no of layers for the filter
    ##It also defines that the filter will be 3x3 size. Change 3 to 5 for a 5x5 filter

    removed_noise = median_filter(arr, 3)
    img = Image.fromarray(removed_noise)
    img.show()


if __name__ == "__main__":
    main()
