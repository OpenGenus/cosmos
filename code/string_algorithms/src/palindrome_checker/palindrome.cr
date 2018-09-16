# Part of Cosmos by OpenGenus Foundation
class String
  def palindrome?
    self == to_s.reverse
  end
end

puts "test".palindrome?
puts "hahah".palindrome?
