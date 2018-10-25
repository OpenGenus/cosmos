func is_palindrome(str: string): bool =
    let length = str.len - 1
    for i in 0..(length mod 2):
      if str[i] != str[length - i]:
        return false
    true
  
func test() =
    assert("madam".is_palindrome)
    assert(not is_palindrome("nimrod"))

# Run test
# test()
  