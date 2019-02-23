def main():
    # Variables to keep track of Fibonacci numbers
    p2 = 0
    p1 = 0
    current = 1
    total = 0

    while current <= 4000000:
        # Add even fibonacci numbers
        total += current if current % 2 == 0 else 0

        # Update fibonacci numbers
        p2 = p1
        p1 = current
        current = p2 + p1

    print(total)


if __name__ == "__main__":
    main()
