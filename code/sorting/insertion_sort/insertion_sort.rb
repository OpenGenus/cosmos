=begin
    Part of Cosmos by OpenGenus Foundation
=end

def InsertionSort(arr)
    n = arr.length
    i = 1
    while i < n
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j]
            arr[j+1] = arr[j]
            j -= 1
        end
        arr[j+1] = key
        i += 1
    end
    return arr
end

arr = [3, 1, 5, 8, 11, 10, 23, 24, -1]

puts "Unsorted Array: #{arr}"
puts "Sorted Array after Insertion Sort: #{InsertionSort(arr)}"
