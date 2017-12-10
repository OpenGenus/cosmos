def factorial(n)
  if n == 0
    1
  else
    n * factorial(n - 1)
  end
end

input = ARGV[0].to_i
puts factorial(input)
