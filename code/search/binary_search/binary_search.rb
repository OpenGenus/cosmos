#   Part of Cosmos by OpenGenus Foundation

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

arr = [3, 5, 12, 56, 92, 123, 156, 190, 201, 222]

number = 12

puts "Position of #{number} is #{binary_search(arr, 0, arr.length - 1, number)}"
