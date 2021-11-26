# unclassified | average | average | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


# Part of Cosmos by OpenGenus Foundation
def sum(*nums)
  nums.inject(&:+).fdiv(nums.size)
end
