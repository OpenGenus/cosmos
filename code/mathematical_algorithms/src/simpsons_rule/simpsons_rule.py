from math import sqrt
from scipy.integrate import quad


def simpson(f, a, b, n):
    def compute_141(x, index):
        return 2 * f(x) if index % 2 == 0 else 4 * f(x)

    n = n if n % 2 == 0 else 2 * n
    h = (b - a) / n
    return (h / 3) * (f(a) + f(b) + sum(compute_141(a + i * h, i) for i in range(1, n)))


a, b, k = 1, 10, 20

f = lambda x: x + sqrt(x)
result = simpson(f, a, b, k)
result2 = quad(f, a, b)
print(result)
print(result2[0])
