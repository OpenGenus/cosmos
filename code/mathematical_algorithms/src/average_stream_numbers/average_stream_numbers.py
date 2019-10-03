# Part of Cosmos by OpenGenus Foundation
def newAvg(prevAvg, newN, newX):
    return (prevAvg * (newN - 1) + newX) / newN


def main():
    L = [1, 9, 20, 13, 45]
    avg = 0
    for i in range(len(L)):
        avg = newAvg(avg, (i + 1), L[i])
        print(avg)


main()
