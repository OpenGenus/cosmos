countingSort = (input) ->
    output = Array(input.length).fill(0)
    max = output[0]
    min = output[0]

    for i in [0...input.length]
        if input[i] > max
            max = input[i]
        else if input[i] < min
        	min = input[i]

    k = max - min + 1

    count_array = Array(k).fill(0)

    for i in [0...input.length]
        count_array[input[i] - min] += 1

    for i in [1...k]
        count_array[i] += count_array[i - 1]

    for i in [0...input.length]
        output[count_array[input[i] - min] - 1] = input[i]
        count_array[input[i] - min] -= 1

    output

input = [1, 5, 2, 7, 3, 4, 4, 1, 5]

input = countingSort input

console.log "Sorted array : " + input

### Output
Sorted array : 1,1,2,3,4,4,5,5,7
###
