import itertools


def compute():
    ans = 0
    for num in itertools.permutations(list(range(10))):
        if is_substring_divisible(num):
            ans += int("".join(map(str, num)))
    return str(ans)


DIVISIBILITY_TESTS = [2, 3, 5, 7, 11, 13, 17]


def is_substring_divisible(num):
    for i in range(7):
        x = num[i + 1] * 100 + num[i + 2] * 10 + num[i + 3]
        if x % DIVISIBILITY_TESTS[i] != 0:
            return False
    return True


if __name__ == "__main__":
    print(compute())
