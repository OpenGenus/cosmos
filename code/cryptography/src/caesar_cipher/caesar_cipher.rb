# Part of Cosmos by OpenGenus Foundation
# Written by Michele Riva

CHARS_HASH = Hash[('a'..'z').to_a.zip((0..25).to_a)]

def caesar(string, shift)
  shift = 25 if shift > 25

  text = string.downcase.split('')
  encoded = []

  text.each do |c|
    orig_num = CHARS_HASH[c]

    if orig_num - shift > 0
      encoded_num = orig_num - shift
    else
      pre = shift - orig_num
      encoded_num = 26 - pre
    end

    encoded_char = CHARS_HASH.key(encoded_num)
    encoded.push(encoded_char)
  end

  encoded.join('')
end

# Test!
# Input your string as first argument and the shift as second argument.
puts caesar('cosmos', 5) # => xjnhjn
