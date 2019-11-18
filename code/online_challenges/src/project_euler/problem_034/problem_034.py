# Returns the factorial of the given non-negative integer.
def factorial(n):
    assert n >= 0
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result


def compute():
    """ As stated in the problem, 1 = 1! and 2 = 2! are excluded.
	# If a number has at least n >= 8 digits, then even if every digit is 9,
	# n * 9! is still less than the number (which is at least 10^n)."""
    ans = sum(i for i in xrange(3, 10000000) if i == factorial_digit_sum(i))
    return str(ans)


def factorial_digit_sum(n):
    result = 0
    while n >= 10000:
        result += FACTORIAL_DIGITS_SUM_WITH_LEADING_ZEROS[n % 10000]
        n //= 10000
    return result + FACTORIAL_DIGITS_SUM_WITHOUT_LEADING_ZEROS[n]


FACTORIAL_DIGITS_SUM_WITHOUT_LEADING_ZEROS = [
    sum(factorial(int(c)) for c in str(i)) for i in xrange(10000)
]
FACTORIAL_DIGITS_SUM_WITH_LEADING_ZEROS = [
    sum(factorial(int(c)) for c in str(i).zfill(4)) for i in xrange(10000)
]


if __name__ == "__main__":
    print(compute())
