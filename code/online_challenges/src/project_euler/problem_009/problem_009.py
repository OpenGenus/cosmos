def main():
    sum_total = 1000

    for c in range(sum_total):
        for b in range(c):
            for a in range(b):
                if (a + b + c == sum_total) and (a ** 2 + b ** 2 == c ** 2):
                    print(a * b * c)


if __name__ == "__main__":
    main()
