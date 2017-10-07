def gcd(a, b):

    while a > 0:

        b, a = a, b % a

    return b


def lcm(a, b=None):

    if not b:
        assert len(a) >= 2

        l = lcm(*a[:2])

        for x in a[2:]:

            l = lcm(l, x)

        return l

    return int((a * b) / gcd(a, b))


if __name__ == "__main__":
    print(lcm([int(x) for x in input().split()]))
