import numpy as np
from matplotlib.pyplot import subplots


def f(x):
    return -15 * np.sin(x - 5) / (abs(x) + 1)


particles = 10

positions = np.random.uniform(-10, 10, particles)
velocities = np.random.uniform(-1, 1, particles)
best_locals = positions
num_iters = 20

w_min = 0.01
w_max = 0.1
c1 = 0
c2 = 0

gbest = positions[0]

for p in positions:
    if f(p) < f(gbest):
        gbest = p


fig, ax = subplots()
fig.show()

for k in range(num_iters):
    for i in range(particles):

        c1 = 2.5 - 2 * (k / num_iters)
        c2 = 0.5 + 2 * (k / num_iters)
        w = w_max - ((w_max - w_min) * k) / num_iters

        r1, r2 = np.random.uniform(0, 1, 1), np.random.uniform(0, 1, 1)

        velocities[i] = (
            w * velocities[i]
            + c1 * r1 * (best_locals[i] - positions[i])
            + c2 * r2 * (gbest - positions[i])
        )
        positions[i] += velocities[i]

        if f(positions[i]) < f(best_locals[i]):
            best_locals[i] = positions[i]

        if f(best_locals[i]) < f(gbest):
            gbest = best_locals[i]

        ax.clear()
        ax.axis([-20, 15, -17, 15])
        ax.plot(np.arange(-10, 10, 0.1), f(np.arange(-10, 10, 0.1)), "-")
        ax.plot(positions, f(positions), "ro", markersize=5)

        fig.canvas.draw()
    print("Iter: {}".format(k))

lowest = np.argmin(positions)
print(positions[lowest])
local_lowest = np.argmin(best_locals)
print(best_locals[local_lowest])
