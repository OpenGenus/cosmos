def sum(*nums)
  nums.inject(&:+).fdiv(nums.size)
end
