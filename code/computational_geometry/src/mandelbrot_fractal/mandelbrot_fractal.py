import numpy
import matplotlib.pyplot as plt


def mandelbrot(Re, Im, max_iter):
    c = complex(Re, Im)
    z = 0.0j

    for i in range(max_iter):
        z = z * z + c
        if (z.real * z.real + z.imag * z.imag) >= 4:
            return i

    return max_iter


columns = 2000
rows = 2000

result = numpy.zeros([rows, columns])
for row_index, Re in enumerate(numpy.linspace(-2, 1, num=rows)):
    for column_index, Im in enumerate(numpy.linspace(-1, 1, num=columns)):
        result[row_index, column_index] = mandelbrot(Re, Im, 100)

plt.figure(dpi=100)
plt.imshow(result.T, cmap="plasma", interpolation="bilinear", extent=[-2, 1, -1, 1])
plt.xlabel("Re")
plt.ylabel("Im")
plt.show()
