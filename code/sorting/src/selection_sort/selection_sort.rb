# Part of Cosmos by OpenGenus Foundation
def SelectionSort(arr)
  n = arr.length - 1
  i = 0
  while i <= n - 1
    smallest = i
    j = i + 1
    while j <= n
      smallest = j if arr[j] < arr[smallest]
      j += 1
    end
    arr[i], arr[smallest] = arr[smallest], arr[i] if i != smallest
    i += 1
  end
end

arr = [95, 39.5, 35, 75, 85, 69].shuffle
SelectionSort(arr)
puts "After Sorting from Selection Sort.Sorted array is: #{arr.inspect}"
