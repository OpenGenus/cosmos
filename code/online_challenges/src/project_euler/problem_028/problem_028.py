from math import sqrt


def is_perfect_square(integer):
    sqrt_num = int(sqrt(integer))
    return sqrt_num * sqrt_num == integer


def main():
    limit = 1001 * 1001
    increment_rate = 0
    diagonal_number_sum = 0

    i = 1
    while i <= limit:
        diagonal_number_sum += i
        if i % 2 == 1 and is_perfect_square(i):
            increment_rate += 2

        i += increment_rate

    print(diagonal_number_sum)


if __name__ == "__main__":
    main()
