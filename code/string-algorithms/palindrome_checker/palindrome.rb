# Part of Cosmos by OpenGenus Foundation
def palindrome?
  self == to_s.reverse
end

puts 'test'.palindrome?
puts 'haha'.palindrome?
