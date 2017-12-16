def binary_search(arr, l, r, x)
  return -1 if x.nil?

  if r >= l
    mid = (l + r) / 2
    if arr[mid] == x
      mid
    elsif arr[mid] > x
      binary_search(arr, l, mid - 1, x)
    else
      binary_search(arr, mid + 1, r, x)
    end
  end
end

def exponential_search(arr, element)
  return 0 if arr[0] == element
  i = 1
  i *= 2 while i < arr.length && arr[i] <= element
  binary_search arr, i / 2, [i, arr.length].min, element
end

puts exponential_search([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 4)
