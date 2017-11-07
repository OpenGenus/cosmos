#     Part of Cosmos by OpenGenus Foundation

def insertion_sort(arr)
  n = arr.length
  i = 1
  while i < n
    key = arr[i]
    j = i - 1
    while (j >= 0) && (key < arr[j])
      arr[j + 1] = arr[j]
      j -= 1
    end
    arr[j + 1] = key
    i += 1
  end
  arr
end

arr = [3, 1, 5, 8, 11, 10, 23, 24, -1]

puts "Unsorted Array: #{arr}"
puts "Sorted Array after Insertion Sort: #{insertion_sort(arr)}"
