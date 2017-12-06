def is_palindrome(arr):
	length = len(arr)
	i = 0
	for i in range(int(length / 2)):
		if arr[i] != arr[length - i - 1]:
			return False
	return True


if __name__ == '__main__':
	# test empty
	assert is_palindrome('') == True

	# test odd length
	assert is_palindrome('a') == True
	assert is_palindrome('aba') == True

	# test even length
	assert is_palindrome('abba') == True
	assert is_palindrome('abaaba') == True

	assert is_palindrome([]) == True
	assert is_palindrome([1, 2, 1]) == True
	
	assert is_palindrome('ab') == False
	assert is_palindrome('abab') == False