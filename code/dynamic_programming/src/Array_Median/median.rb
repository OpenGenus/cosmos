# Part of Cosmos by OpenGenus Foundation

def median(*nums)
  nums.sort!
  if nums.size.odd?
    nums[(nums.size + 1) / 2 - 1]
  else
    (nums[nums.size / 2 - 1] + nums[nums.size / 2]).fdiv(2)
  end
end
