def bogosort(arr)
  arr.shuffle! until in_order?(arr)
  arr
end

def in_order?(arr)
  return true if arr.empty?
  last = arr[0]
  arr[1...arr.length].each do |x|
    return false if x < last
    last = x
  end
  true
end

p bogosort([3, 2, 1])
