# Part of Cosmos by OpenGenus Foundation
def merge(a, l, m, r)
  n1 = m - l + 1
  left = Array.new(n1) # Created temp array for storing left subarray
  n2 = r - m
  right = Array.new(n2) # Created temp array for storing right subarray

  for i in 0...n1 # Copy values from left subarray to temp array
    left[i] = a[l + i]
  end

  for i in 0...n2 # Copy values from Right subarray to temp array
    right[i] = a[m + 1 + i]
  end

  i = 0
  j = 0

  # Comparing and merging two sub arrays
  for k in l..r
    if i >= n1
      a[k] = right[j]
      j += 1
    elsif j >= n2
      a[k] = left[i]
      i += 1
    elsif left[i] > right[j]
      a[k] = right[j]
      j += 1
    else
      a[k] = left[i]
      i += 1
    end
  end
 end

# Merge Sort
def merge_sort(a, l, r)
  if l < r
    m = l + (r - l) / 2
    merge_sort(a, l, m)
    merge_sort(a, m + 1, r)
    merge(a, l, m, r)
   end
end
