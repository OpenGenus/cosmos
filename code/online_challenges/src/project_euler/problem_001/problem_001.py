def main():
    total = 0
    for i in range(0, 1000):
        total += i if (i % 3 == 0) or (i % 5 == 0) else 0

    print(total)


if __name__ == "__main__":
    main()
