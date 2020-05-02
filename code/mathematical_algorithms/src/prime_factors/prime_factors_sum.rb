def prime_factors_sum(n)
  prime_array = []    
  p = 2
  if n < 2
      return p
  end

  while p < n
    if n % p == 0
      prime_array.push(p)
    end
  p +=1
  end

  sum = 0
  prime_array.each { |a| sum+=a }
  return sum
end

n = gets.to_i
puts prime_factors_sum(n) 


=begin
Input:
18

Output:
20
=end