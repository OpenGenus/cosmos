if __name__ == '__main__':

    total = 0

    for i in range(1, 1001):
        total += int(str(i**i)[-10:])

    print(str(total)[-10:])
