array = []
i = 0

#convert string array into integer array
ARGV.each do |x| 
array[i] = x.to_i
i = i + 1
end

p "Input array:"
array.each do |x| 
p x
end

for i in 0..array.length-1
# initialize to the current element
smallest = array[i]
index = i

    for j in i..array.length-1
    #find the smallest element on the RHS of current element
    if array[j] < smallest
     smallest = array[j]
        index = j
    end
    end

#swap the smallest element with the current element
tmp = array[i] 
array[i] = smallest
array[index] = tmp 
end


p "Sorted array:"
array.each do |x| 
p x.to_i
end
