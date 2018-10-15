# Part of Cosmos by OpenGenus Foundation
def radix_sort(number, maxNumber):
    length = len(number)
    k = 0
    n = 1
    temp = []
    for i in range(length):
        temp.append([0] * length)
    order = [0] * length
    while n <= maxNumber:
        for i in range(length):
            lsd = (number[i] // n) % 10
            temp[lsd][order[lsd]] = number[i]
            order[lsd] += 1
        for i in range(length):
            if order[i] != 0:
                for j in range(order[i]):
                    number[k] = temp[i][j]
                    k += 1
            order[i] = 0
        n *= 10
        k = 0


number = [34, 3212, 51, 52, 612, 456, 12, 31, 412, 123, 1, 3]

print("before radix_sorting", number)
radix_sort(number, max(number))
print("after radix_sorting", number)
