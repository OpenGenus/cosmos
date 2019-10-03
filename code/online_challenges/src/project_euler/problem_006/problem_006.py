def main():
    sum_of_squares = 0
    square_of_sum = 0

    for n in range(1, 101):
        sum_of_squares += n * n
        square_of_sum += n

    square_of_sum *= square_of_sum

    print(square_of_sum - sum_of_squares)


if __name__ == "__main__":
    main()
