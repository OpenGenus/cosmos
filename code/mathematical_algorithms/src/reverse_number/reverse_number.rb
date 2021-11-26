# mathematical algorithms | reverse number | reverse number | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


''"
Author: ryanml
Path of Cosmos by OpenGenus Foundation
"''

class NumReverse
  def reverse(n)
    n.to_s.chars.reverse.join.to_i
  end
end

def tests
  reverser = NumReverse.new
  puts reverser.reverse(2425)
  puts reverser.reverse(9999)
  puts reverser.reverse(5)
  puts reverser.reverse(123_456)
end

tests
