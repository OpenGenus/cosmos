import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

prandtl = 10
rho = 28
beta = 8 / 3


def lorenz_attr(x, y, z):
    x_dot = prandtl * (y - x)
    y_dot = rho * x - y - x * z
    z_dot = x * y - beta * z
    return x_dot, y_dot, z_dot


dt = 0.01
num_steps = 10000

xs = np.empty(num_steps + 1)
ys = np.empty(num_steps + 1)
zs = np.empty(num_steps + 1)

xs[0], ys[0], zs[0] = (0.0, 1.0, 1.05)

for i in range(num_steps):
    x_dot, y_dot, z_dot = lorenz_attr(xs[i], ys[i], zs[i])
    xs[i + 1] = xs[i] + (x_dot * dt)
    ys[i + 1] = ys[i] + (y_dot * dt)
    zs[i + 1] = zs[i] + (z_dot * dt)

fig = plt.figure()
plt.style.context("dark_background")
ax = fig.gca(projection="3d")

ax.plot(xs, ys, zs, lw=0.5)
ax.set_xlabel("X-Axis")
ax.set_ylabel("Y-Axis")
ax.set_zlabel("Z-Axis")
ax.set_title("Lorenz Attractor")

plt.style.use("dark_background")
plt.show()
