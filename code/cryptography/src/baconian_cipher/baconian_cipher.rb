# Written by Michele Riva

BACONIAN_CODE = {
  'a' => 'AAAAA', 'b' => 'AAAAB', 'c' => 'AAABA',
  'd' => 'AAABB', 'e' => 'AABAA', 'f' => 'AABAB',
  'g' => 'AABBA', 'h' => 'AABBB', 'i' => 'ABAAA',
  'j' => 'BBBAA', 'k' => 'ABAAB', 'l' => 'ABABA',
  'm' => 'ABABB', 'n' => 'ABBAA', 'o' => 'ABBAB',
  'p' => 'ABBBA', 'q' => 'ABBBB', 'r' => 'BAAAA',
  's' => 'BAAAB', 't' => 'BAABA', 'u' => 'BAABB',
  'v' => 'BBBAB', 'w' => 'BABAA', 'x' => 'BABAB',
  'y' => 'BABBA', 'z' => 'BABBB'
}.freeze

def encode(string)
  text = string.downcase.split('')
  encoded_text = []

  text.each do |c|
    bac_char = BACONIAN_CODE[c]
    encoded_text.push(bac_char)
  end

  encoded_text.join('')
end

# TEST!
puts encode('Hello World') # => AABBBAABAAABABAABABAABBABBABAAABBABBAAAAABABAAAABB
