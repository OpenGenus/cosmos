import math

def comb_sort(array):
    gap = len(array)
    shrink = 1.3
    ordered = False

    while not ordered:
        gap = int(math.floor(gap / shrink))

        if gap > 1:
            ordered = False
        else:
            gap = 1
            ordered = True

        i = 0
        while i + gap < len(array):
            if array[i] > array[i+gap]:
                array[i], array[i+gap] = array[i+gap], array[i]
                ordered = False
            i += 1
