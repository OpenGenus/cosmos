import numpy as np


def show_as_height_map(height, mat):
    from mpl_toolkits.mplot3d import Axes3D
    import matplotlib.pyplot as plt

    x, y = np.meshgrid(np.arange(height), np.arange(height))
    fig = plt.figure()
    ax = fig.add_subplot(111, projection="3d")
    ax.plot_surface(x, y, mat)
    plt.title("height map")
    plt.show()


def update_pixel(pixel, mean, magnitude):
    return mean + (2 * pixel * magnitude) - magnitude


def main(n, smooth_factor, plot_enable):
    height = (1 << n) + 1
    mat = np.random.random((height, height))

    i = height - 1

    magnitude = 1

    # seeds init
    mat[0, 0] = update_pixel(mat[0, 0], 0, magnitude)
    mat[0, height - 1] = update_pixel(mat[0, height - 1], 0, magnitude)
    mat[height - 1, height - 1] = update_pixel(
        mat[height - 1, height - 1], 0, magnitude
    )
    mat[0, height - 1] = update_pixel(mat[0, height - 1], 0, magnitude)

    while i > 1:
        id_ = i >> 1
        magnitude *= smooth_factor
        for xIndex in range(id_, height, i):  # Beginning of the Diamond Step
            for yIndex in range(id_, height, i):
                mean = (
                    mat[xIndex - id_, yIndex - id_]
                    + mat[xIndex - id_, yIndex + id_]
                    + mat[xIndex + id_, yIndex + id_]
                    + mat[xIndex + id_, yIndex - id_]
                ) / 4
                mat[xIndex, yIndex] = update_pixel(mat[xIndex, yIndex], mean, magnitude)
        for xIndex in range(0, height, id_):  # Beginning of the Square Step
            if xIndex % i == 0:
                shift = id_
            else:
                shift = 0

            for yIndex in range(shift, height, i):
                sum_ = 0
                n = 0
                if xIndex >= id_:
                    sum_ += mat[xIndex - id_, yIndex]
                    n += 1

                if xIndex + id_ < height:
                    sum_ += mat[xIndex + id_, yIndex]
                    n += 1

                if yIndex >= id_:
                    sum_ += mat[xIndex, yIndex - id_]
                    n += 1

                if yIndex + id_ < height:
                    sum_ += mat[xIndex, yIndex + id_]
                    n += 1

                mean = sum_ / n
                mat[xIndex, yIndex] = update_pixel(mat[xIndex, yIndex], mean, magnitude)
        i = id_

    if plot_enable:
        show_as_height_map(height, mat)

    return mat


def check_smooth_factor(value):
    fvalue = float(value)
    if fvalue < 0 or fvalue > 1:
        raise argparse.ArgumentTypeError("%s is an invalid smooth factor value" % value)
    return fvalue


def check_positive(value):
    ivalue = int(value)
    if ivalue <= 0:
        raise argparse.ArgumentTypeError("%s is an invalid positive int value" % value)
    return ivalue


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="machine generated calculation")
    parser.add_argument(
        "-n",
        help="the size of the image will be 2**n + 1",
        required=False,
        default=8,
        type=check_positive,
    )

    parser.add_argument(
        "-s",
        help="smooth factor, needs to be in range of [0, 1], value of 0 means image is very smooth,"
        "value of 1 means image is very rough",
        required=False,
        default=0.5,
        type=check_smooth_factor,
    )

    parser.add_argument("-p", help="plot with matplotlib", action="store_true")

    args = parser.parse_args()

    main(args.n, args.s, args.p)
