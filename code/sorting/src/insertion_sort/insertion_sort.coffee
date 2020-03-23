insertionSort = (array) ->
    for i in [0...array.length]
        temp = array[i]
        j = i - 1

        while j >= 0 and array[j] > temp
            array[j + 1] = array[j]
            j--

        array[j + 1] = temp
    array

array = [8, 4, 3, 1, 6, 2, 5]

console.log insertionSort(array)

### Output
[ 1, 2, 3, 4, 5, 6, 8 ]
###
