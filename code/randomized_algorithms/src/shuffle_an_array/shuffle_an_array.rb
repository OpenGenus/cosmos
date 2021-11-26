# randomized algorithms | shuffle an array | shuffle an array | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


# Implementation of the algo
# Stdlib has #shuffle, use that instead
def randomize(arr, n)
  n -= 1
  n.downto(1).each do |i|
    j = rand(i + 1)
    arr[i], arr[j] = arr[j], arr[i]
  end
  arr
end

p randomize([1, 2, 3], 3)
