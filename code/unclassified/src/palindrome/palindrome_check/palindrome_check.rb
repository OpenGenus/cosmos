# careful using any variables named word, scoping gets weird
def is_palindrome_recursive(word)
  # set both indices for iterating through the word
  word_start = 0
  word_end = word.length - 1

  # check that the word is not one character or empty
  if word_end != word_start

    # check that the word start index is less than the word end index
    if word_start < word_end

      # check if the characters at each index are the same
      return false if word[word_start] != word[word_end]

      # trim the word
      word[word_start] = ''
      word[word_end - 1] = ''

      # send the word back for another loop
      return is_palindrome_recursive(word)

    end

  end

  # if it gets to this statement, it's a palindrome
  true
end

def is_palindrome_iterative(word)
  # set both indices for iterating through the word
  word_start = 0
  word_end = word.length - 1

  # check that the word is not one character or empty
  if word_end != word_start

    # breaks when the indices reach one another

    while word_start < word_end

      # check if the characters at each index are the same
      return false if word[word_start] != word[word_end]

      # iterate both indices, bringing them towards the middle of the word
      word_start += 1
      word_end -= 1

    end

    return true

  end

  false
end

def is_palindrome(word)
  # use the iterative method as the default
  is_palindrome_iterative(word)
end
