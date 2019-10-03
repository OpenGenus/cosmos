def main():
    dic = {n: 0 for n in range(1, 1000000)}

    for n in range(3, 1000000, 1):
        count = 0
        number = n

        while True:
            if n < number:
                dic[number] = dic[n] + count
                break
            if n % 2 == 0:
                n = n / 2
                count += 1
            else:
                n = (3 * n) + 1
                count += 1

    print(dic.values().index(max(dic.values())) + 1)


if __name__ == "__main__":
    main()
