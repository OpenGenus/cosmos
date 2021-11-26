# cryptography | morse cipher | morse code generator | RUBY
// Part of Cosmos by OpenGenus Foundation

=end


MORSE_CODES = {
  'a' => '.-', 'b' => '-...', 'c' => '-.-.',
  'd' => '-..', 'e' => '.', 'f' => '..-.',
  'g' => '--.', 'h' => '....', 'i' => '..',
  'j' => '.---', 'k' => '-.-', 'l' => '.-..',
  'm' => '--', 'n' => '-.', 'o' => '---',
  'p' => '.--.', 'q' => '--.-', 'r' => '.-.',
  's' => '...', 't' => '-', 'u' => '..-',
  'v' => '...-', 'w' => '.--', 'x' => '-..-',
  'y' => '-.--', 'z' => '--..', ' ' => ' ',
  '1' => '.----', '2' => '..---', '3' => '...--',
  '4' => '....-', '5' => '.....', '6' => '-....',
  '7' => '--...', '8' => '---..', '9' => '----.',
  '0' => '-----'
}.freeze

def encode(string)
  text = string.downcase.split('')
  encoded_text = []

  text.each do |c|
    morse_char = MORSE_CODES[c]
    encoded_text.push(morse_char)
  end

  encoded_text.join('')
end

# TEST!
puts encode('Hello World') # => ......-...-..--- .-----.-..-..-..
