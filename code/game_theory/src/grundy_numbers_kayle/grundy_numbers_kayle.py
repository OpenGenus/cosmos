def SGsom(a, b):
    """Returns recurrence Calulation for a and b"""
    x = 0
    y = 2
    while a != 0 or b != 0:
        if a % y == b % y:
            w = 0
        else:
            w = 1
        x += w * (y / 2)
        a -= a % y
        b -= b % y
        y *= 2
    return x


def quickSort(array, left, right):
    """ A simple Quick Sorting program"""
    i = left
    j = right
    pivot = array[(left + right) / 2]
    while i <= j:

        while array[i] < pivot:
            i += 1

        while array[j] > pivot:
            j -= 1

        if i <= j:
            array[i], array[j] = array[j], array[i]
            i += 1
            j -= 1
    if left < j:
        quickSort(array, left, j)

    if i < right:
        quickSort(array, i, right)


def main():
    """Main Program for printing Grundy Numbers"""
    m = input("How Many Sprague Grundy Value do you want to know?")
    n = m + 1
    main_arr = [0 for i in range(n)]
    main_arr[1] = 1
    temp_arr = [0 for i in range(n)]
    for i in range(2, n):
        k = 0
        l = 1
        for j in range(((i - 1) / 2) + 1):
            temp_arr[j] = SGsom(main_arr[j], main_arr[i - j - 1])

    for j in range(((i - 2) / 2) + 1):
        temp_arr[j + (i + 1) / 2] = SGsom(main_arr[j], main_arr[i - j - 2])

    temp_arr[i] = i + 1
    quickSort(temp_arr, 0, i - 1)

    while k != 1:
        if temp_arr[0] != 0:
            k += 1
            main_arr[i] = 0

        elif temp_arr[l] - temp_arr[l - 1] <= 1:
            l += 1

        else:
            k += 1
            main_arr[i] = temp_arr[l - 1] + 1

    for i in range(m + 1):
        print(str(i) + "---" + str(main_arr[i]))


main()
