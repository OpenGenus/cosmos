# Made by adeen-s
# Part of cosmos by OpenGenus

nums = "" # The string containing the sequence of numbers
i = 0 # Used for iteration

while len(nums) < 1000002: # Loop to add the sequence of numbers to the list
    nums = nums + str(i) 
    i = i + 1

answer = 1 # Initialising answer which will store final computed answer
i = 1 # Reset value for use in next loop

while i <= 1000000: # Loop to generate the answer
    answer = answer * int(nums[i])
    i = i * 10
    
print(answer)
