#
# Python-3
#
# For running on Python-2, replace // with /.
#
# Many researchers found similar identities:
#   Vajda-11, Dunlap I7, Lucas(1878),
#   B&Q(2003) I13 and I14,
#   Hoggatt I11 and I10.
# See http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/fibFormulae.html

import timeit


def fib_iter(n):
    if n <= 0:
        return 0

    f0, f1 = 0, 1
    while n >= 2:
        f0, f1 = f1, f0 + f1
        n -= 1

    return f1


# Lucas's identities:
#   F(2k)    = (2*F(k-1) + F(k)) * F(k)
#   F(2*k-1) = F(k) * F(k) + F(k-1) * F(k-1)
def fib_lucas(n):
    if n <= 1:
        return n

    k = (n + 1) // 2
    fk, fk_1 = fib_lucas(k), fib_lucas(k - 1)
    return fk * fk + fk_1 * fk_1 if n % 2 else (2 * fk_1 + fk) * fk


def fib_lucas_mem(n):
    cache = {0: 0, 1: 1}

    def fib(n):
        if n in cache:
            return cache[n]

        k = (n + 1) // 2
        fk, fk_1 = fib(k), fib(k - 1)
        fn = fk * fk + fk_1 * fk_1 if n % 2 else (2 * fk_1 + fk) * fk

        cache[n] = fn
        return fn

    return fib(n)


# Measures the time for computing func(n) number times.
def test_it(func, n, number=1):
    func_name = func.__name__
    stmt = "{}({})".format(func_name, n)
    setup = "from __main__ import {}".format(func_name)
    print(func_name, timeit.timeit(stmt=stmt, setup=setup, number=number))


if __name__ == "__main__":
    n = 1000000
    number = 1

    res = set()
    for f in [fib_iter, fib_lucas, fib_lucas_mem]:
        test_it(f, n, number)
        res.add(f(n))

    assert len(res) == 1
    M = 1000 ** 3 + 7
    print(res.pop() % M)

# Example of the output:
# fib_iter 10.709764141996857
# fib_lucas 0.49604503500449937
# fib_lucas_mem 0.047084556994377635
# 918091266
