# mathematical algorithms | sum of digits | sum of digits | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


## Part of Cosmos by OpenGenus Foundation
def sum_of_digits(num)
  num = num.abs
  sum = 0
  while num > 0
    sum += num % 10
    num /= 10
  end
  sum
end
