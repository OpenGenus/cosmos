# Part of Cosmos by OpenGenus Foundation
puts 'Enter text you want to encrypt: '
text = gets.chomp

puts text.tr('A-Za-z', 'N-ZA-Mn-za-m')
