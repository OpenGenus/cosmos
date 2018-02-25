def isPalindrome(str):
 
    # Run loop from 0 to len/2 
    for i in range(0, len(str) // 2): 
        if str[i] != str[len(str) - i - 1]:
            return False
    return True


if __name__ == '__main__':
	print("Give input string:")
	s = input()
	ans = isPalindrome(s)
	 
	if ans:
	    print("Yes " + s + " is a palindrome")
	else:
	    print("No " + s + " is not a palindrome")
