# Part of Cosmos by OpenGenus Foundation


def selection_sort(array):
    for i in range(len(array) - 1):
        minimumValue = i
        for j in range(i + 1, len(array)):
            if array[j] < array[minimumValue]:
                minimumValue = j
        temp = array[minimumValue]
        array[minimumValue] = array[i]
        array[i] = temp
    return array
