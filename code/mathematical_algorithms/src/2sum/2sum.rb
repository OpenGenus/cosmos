# Part of Cosmos by OpenGenus Foundation
# Given an array of integers, return the indices of the two numbers such that they add up to a specific target.

def two_sum(list, target)
  buffer = {}
  list.each_with_index do |val, idx|
    return [buffer[target - val], idx] if buffer.key?(target - val)
    buffer[val] = idx
  end
  [nil, nil]
end

p two_sum([3, 5, 7, 0, -3, -2, -3], 4)
p two_sum([3, 5, 0, -3, -2, -3], 4)
