# Part of Cosmos by OpenGenus Foundation

from functools import wraps


def memo(f):
    """Memoizing decorator for dynamic programming."""

    @wraps(f)
    def func(*args):
        if args not in func.cache:
            func.cache[args] = f(*args)
        return func.cache[args]

    func.cache = {}
    return func


@memo
def factorial(num):
    """Recursively calculate num!."""
    if num < 0:
        raise ValueError("Negative numbers have no factorial.")
    elif num == 0:
        return 1
    return num * factorial(num - 1)
