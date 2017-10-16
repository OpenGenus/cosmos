def sum_of_digits(num)
  num = num.abs
  sum = 0
  while num > 0
    sum += num % 10
    num /= 10
  end
  sum
end
