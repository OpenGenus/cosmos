def prime_factors(n)
  prime_array = []    
  p = 2
  if n < 2
      return p
  end

  while p < n
    if n % p == 0
      prime_array.push(p)
    end
  p += 1
  end

  return prime_array
end

n = gets.to_i
puts prime_factors(n)

=begin
Input:
30

Output:
2
3
5
6
10
15
=end