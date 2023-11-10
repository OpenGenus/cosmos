import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def f(args):
    return np.sum([x ** 2 for x in args])


def distance(p1, p2):
    return np.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2 + (f(p2) - f(p1)) ** 2)


dimensions = 2
boundary = (-10, 10)
particles = 30
positions = []
velocities = []

w_min = 0.01
w_max = 0.1
c1 = 0
c2 = 0
num_iters = 10

for i in range(particles):
    positions.append(np.random.uniform(boundary[0], boundary[1], dimensions))

positions = np.array(positions)
best_positions = positions

for i in range(particles):
    velocities.append(np.random.uniform(-1, 1, dimensions))

velocities = np.array(velocities)

fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

fig.show()

x = y = np.arange(boundary[0], boundary[1], 0.1)
surface_x, surface_y = np.meshgrid(x, y)
surface_z = np.array(
    [f([x, y]) for x, y in zip(np.ravel(surface_x), np.ravel(surface_y))]
).reshape(surface_x.shape)

for k in range(num_iters):
    for p in range(particles):
        c1 = 2.5 - 2 * (k / num_iters)
        c2 = 0.5 + 2 * (k / num_iters)
        w = w_max - ((w_max - w_min) * k) / num_iters

        distances = list(
            zip(
                [
                    distance(positions[p], other)
                    for other in positions
                    if (other != positions[p]).any()
                ],
                range(particles),
            )
        )
        distances.sort()

        neighbours = [positions[i] for i in list(zip(*distances[:5]))[1]]
        neighbours_best = neighbours[0]

        for n in neighbours:
            if f(n) < f(neighbours_best):
                neighbours_best = n

        for d in range(2):
            r1, r2 = np.random.rand(), np.random.rand()
            velocities[p][d] = (
                w * velocities[p][d]
                + c1 * r1 * (best_positions[p][d] - positions[p][d])
                + c1 * r2 * (neighbours_best[d] - positions[p][d])
            )

            positions[p][d] += velocities[p][d]

            if f(positions[p]) < f(best_positions[p]):
                best_positions[p] = positions[p]

            if f(best_positions[p]) < f(neighbours_best):
                neighbours_best = best_positions[p]

        ax.clear()
        ax.plot_surface(surface_x, surface_y, surface_z, alpha=0.3)

        positions_x = [p[0] for p in positions]
        positions_y = [p[1] for p in positions]
        positions_z = [f([x, y]) for x, y in zip(positions_x, positions_y)]

        ax.scatter(positions_x, positions_y, positions_z, c="#FF0000")
        fig.canvas.draw()
    print("Iter: {}".format(k))
lowest = np.argmin(f(positions))
print(positions[lowest])
