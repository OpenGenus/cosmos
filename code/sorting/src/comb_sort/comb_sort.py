def combsort(array):
    gap = len(array)
    swap = True
    while gap > 1 or swap:
        gap = max(1, int(gap / 1.25))
        swap = False
        for i in range(len(array) - gap):
            j = i + gap
            if array[i] > array[j]:
                array[i], array[j] = array[j], array[i]
                swap = True


numbers = [3, 4, 7, 2, 4, 1, 6, 8, 9, 10]
print(numbers)

combsort(numbers)
print(numbers)
