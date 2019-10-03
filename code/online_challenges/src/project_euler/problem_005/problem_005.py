def gcd(n1, n2):
    remainder = 1
    while remainder != 0:
        remainder = n1 % n2
        n1 = n2
        n2 = remainder
    return n1


def lcm(n1, n2):
    return (n1 * n2) / gcd(n1, n2)


def main():
    num = 1
    for i in range(1, 21):
        num = lcm(num, i)
    print(num)


if __name__ == "__main__":
    main()
