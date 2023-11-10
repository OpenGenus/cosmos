import math


def check_is_square(input):
    return math.sqrt(input) == math.floor(math.sqrt(input))


if __name__ == "__main__":
    print(check_is_square(0))  # True
    print(check_is_square(1))  # True
    print(check_is_square(2))  # False
    print(check_is_square(4))  # True
    print(check_is_square(8))  # False
    print(check_is_square(16))  # True
    print(check_is_square(32))  # False
    print(check_is_square(64))  # True
