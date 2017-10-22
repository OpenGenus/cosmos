def bogosort(arr)
  arr.shuffle! while !in_order?(arr)
  arr
end

def in_order?(arr)
  if arr.empty?
      return true
  end
  last = arr[0]
  arr[1...arr.length].each do | x |
    if x < last
      return false
    end
    last = x
  end
  return true
end

p bogosort([3, 2, 1])
