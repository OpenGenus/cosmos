def main():
    n = 600851475143
    h = 0
    c = 2

    while n != 1:
        if n % c == 0 and c > h:
            h = c
            n /= c
        c += 1

    print(h)


if __name__ == "__main__":
    main()
