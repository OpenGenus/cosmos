import math


def main():
    i = 1
    triangle_number = 0
    divisor_count = 0

    while divisor_count < 500:
        triangle_number += i
        i += 1
        divisor_count = 0

        for z in range(1, int(math.sqrt(triangle_number))):
            if triangle_number % z == 0:
                divisor_count += 2

    print(triangle_number)


if __name__ == "__main__":
    main()
