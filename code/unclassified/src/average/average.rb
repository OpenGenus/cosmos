# Part of Cosmos by OpenGenus Foundation
def sum(*nums)
  nums.inject(&:+).fdiv(nums.size)
end
