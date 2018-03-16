nums = ""
i = 0

while len(nums) < 1000002:
    nums = nums + str(i)
    i = i + 1

answer = 1
i = 1

while i <= 1000000:
    answer = answer * int(nums[i])
    i = i * 10
    
print(answer)
