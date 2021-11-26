# mathematical algorithms | count digits | counts digits | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


def count_num(num)
  count = 0
  while num > 0
    num /= 10
    count += 1
  end
  count
end

print count_num(2765).to_s
