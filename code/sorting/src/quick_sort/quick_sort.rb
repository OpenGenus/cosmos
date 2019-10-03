# Part of Cosmos by OpenGenus Foundation
def quick_sort(array, beg_index, end_index)
  if beg_index < end_index
    pivot_index = partition(array, beg_index, end_index)
    quick_sort(array, beg_index, pivot_index - 1)
    quick_sort(array, pivot_index + 1, end_index)
  end
  array
end

# returns an index of where the pivot ends up
def partition(array, beg_index, end_index)
  # current_index starts the subarray with larger numbers than the pivot
  current_index = beg_index
  i = beg_index
  while i < end_index
    if array[i] <= array[end_index]
      swap(array, i, current_index)
      current_index += 1
    end
    i += 1
  end
  # after this swap all of the elements before the pivot will be smaller and
  # after the pivot larger
  swap(array, end_index, current_index)
  current_index
end

def swap(array, first_element, second_element)
  temp = array[first_element]
  array[first_element] = array[second_element]
  array[second_element] = temp
end

puts quick_sort([2, 3, 1, 5], 0, 3).inspect # will return [1, 2, 3, 5]
