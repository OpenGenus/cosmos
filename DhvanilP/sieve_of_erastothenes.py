from math import sqrt


def main():
    n = int(input("Enter n : "))
    boolArr = [True for i in range(n + 1)]
    boolArr[0] = boolArr[1] = False

    for i in range(2, int(sqrt(n) + 1)):
        if boolArr[i] is True:
            for j in range(i * i, n + 1, i):
                # print(boolArr)
                boolArr[j] = False

    for i in range(2, n + 1):
        if boolArr[i] is True:
            print(i)


if __name__ == '__main__':
    main()
