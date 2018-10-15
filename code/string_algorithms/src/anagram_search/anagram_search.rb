FIRST_TWENTY_SIX_PRIMES = [
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,
  37, 41, 43, 47, 53, 59, 61, 67, 71, 73,
  79, 83, 89, 97, 101 ].freeze

def anagram_number(word)
  word.downcase.chars.map do |letter|
    letter.ord - 'a'.ord
  end.reject do |index|
    index < 0 || index >= FIRST_TWENTY_SIX_PRIMES.size
  end.map do |index|
    FIRST_TWENTY_SIX_PRIMES[index]
  end.inject(:*)
end

def anagrams?(first_word, second_word)
  anagram_number(first_word) == anagram_number(second_word)
end

anagrams?('anagram', 'nag a ram') # true
anagrams?('William Shakespeare', 'I am a weakish speller') # true
anagrams?('Madam Curie', 'Radium came') # true
anagrams?('notagram', 'notaflam') # false
