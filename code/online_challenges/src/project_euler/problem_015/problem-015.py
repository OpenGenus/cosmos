from math import factorial


def main(n):
    print(int(factorial(n*2)/(factorial(n)*factorial(n))))


if __name__ == '__main__':
    main(20)
