def sum_of_proper_divisors(num)
  (1..(num / 2)).select { |i| num % i == 0 }.inject(:+)
end

def ami_check(num1, num2)
  if num1 == num2
    false
  else
    sum_of_proper_divisors(num1) == num2 && sum_of_proper_divisors(num2) == num1
  end
end

puts ami_check(66_928, 66_992)
