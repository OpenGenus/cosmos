def neville(x, xi, f):
    q = []
    n = len(xi)
    x = float(x)

    for i in range(n):
        q.append([])
        for j in range(n):
            q[i].append(0)

    for i in range(n):
        q[i][0] = f[i]

    print("i\txi", end="\t")
    for i in range(n):
        print(f"q[i][{i}]", end="\t")
    print()

    for i in range(1, n):
        for j in range(1, i + 1):
            q[i][j] = (
                (x - xi[i - j]) * q[i][j - 1] - (x - xi[i]) * q[i - 1][j - 1]
            ) / (xi[i] - xi[i - j])

    for i in range(n):
        print("{}\t{:.4f}".format(i, xi[i]), end="\t")
        for j in range(n):
            print("{:.4f}".format(q[i][j]), end="\t")
        print()

    return q


"""
If you want to do an aproximation only with numbers with neville method:
Remember that "q" is the neville matrix and Q[n - 1][n - 1] is an aproximation for P(x)
"""

f = [16.94410, 17.56492, 18.50515, 18.82091]
q = neville(x=8.4, xi=[8.1, 8.3, 8.6, 8.7], f=f)
print("{:.8f}".format(q[len(q) - 1][len(q) - 1]))
print("----------------------")


"""
If you want to do an aproximation with a function with neville method:
"""


def g(x):
    return float(3 ** (x))


f = [g(x) for x in [-2, -1, 0, 1, 2]]

q = neville(x=(1.0 / 2.0), xi=[-2, -1, 0, 1, 2], f=f)
print("{:.8f}".format(q[len(q) - 1][len(q) - 1]))
print("----------------------")
