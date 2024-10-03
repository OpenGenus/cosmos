def main():
    factorial = 1
    for i in range(100):
        factorial *= i + 1
    digit_sum = 0

    while factorial > 0:
        digit_sum += factorial % 10
        factorial = factorial // 10

    print(digit_sum)


if __name__ == "__main__":
    main()
