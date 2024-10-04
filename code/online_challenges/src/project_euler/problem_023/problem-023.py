# TODO: Find a faster algorithm
def is_abundant(n):
    return sum(i for i in range(1, n) if n % i == 0) > n


if __name__ == '__main__':
    abundants = set()
    for i in range(12, 28123):
        if is_abundant(i):
            abundants.add(i)

    total = 0
    for i in range(24, 28123):
        in_result = True
        for j in abundants:
            if i - j in abundants:
                in_result = False
                break
        if in_result:
            total += i
    print(total)
