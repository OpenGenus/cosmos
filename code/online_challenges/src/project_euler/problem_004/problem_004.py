def main():
    num = 0

    for i in range(100, 1000):
        for j in range(100, 1000):
            c = i * j
            cS = str(c)

            if cS == cS[::-1] and c > num:
                num = c

    print(num)


if __name__ == "__main__":
    main()
