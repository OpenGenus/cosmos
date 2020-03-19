interpolation = (array, search_item) ->
    high = array.length - 1
    low = 0

    while low <= high and search_item >= array[low] and search_item <= array[high]
        rise = high - low
        run = array[high] - array[low]
        x = search_item - array[low]
        pos = low + (rise / run) * x

        return pos if array[pos] is search_item

        if search_item < array[pos]
            high = pos - 1
        else
            low = pos + 1

    -1

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
search_item = 8
index = interpolation array, search_item

if index is -1
    console.log "Element not found"
else
    console.log "Found at position " + index

### Ouput
Found at position 7
###
