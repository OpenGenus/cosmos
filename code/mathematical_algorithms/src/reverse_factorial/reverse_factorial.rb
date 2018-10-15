def inverse_factorial(num)
  num = num.to_f
  i = 2.0
  j = 0
  while i <= num
    num /= i
    j = i if num == 1
    i += 1
  end
  j
end

num = 362_880
if inverse_factorial(num) > 0
  puts inverse_factorial(num).to_s
else
  puts 'No INVERSE FACTORIAL'
end
