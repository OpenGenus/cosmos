# part of cosmos by opengenus foundation

from __future__ import division, print_function  # if python 2.x used

def is_lapindrome(string):
	mid = len(string) // 2;
	delim = mid
	if len(string)%2 == 1:
		delim +=1    # if string has odd number of characters

	first_half = string[:mid]
	second_half = string[delim:]

	first_half = "".join(sorted(first_half))
	second_half = "".join(sorted(second_half))

	return first_half == second_half


test_case = "xyzyx"

if is_lapindrome(test_case):
	print("Lapindrome")
else:
	print("Not a Lapindrome")

