def lis(arr)
  n=arr.size
  lis=Array.new(n, 1)

  ans=-1<<30

  n.times do |i|
    i.times do |j|
      if arr[j]<arr[i]
        lis[i]=[lis[i], lis[j]+1].max
        ans=[ans, lis[i]].max
      end
    end
  end

  ans
end

arr = [10, 22, 9, 33, 21, 50, 41, 60]

puts "Size of the LIS is: #{lis(arr)}"
