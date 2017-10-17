function isPalindrome(myString)
    return myString == string.reverse(myString)
  end
   
  -- Tests
  print(isPalindrome("racecar")) -- should return true
  print(isPalindrome("madam")) -- should return true
  print(isPalindrome("something")) -- should return false
  print(isPalindrome("computer")) -- should return false