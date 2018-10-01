
def base_check(a, y):
	ans = 0
	while a ! = 0:
		ans = ans * 10 + a  %  y
		a = a // y
	return ans 

def palindrome(x):
	reverse = 0
	num = x
	while x ! = 0:
		reverse = reverse * 10 + x % 10
		x = x // 10
	if reverse = = num:
		return True
	else:
		return False

number = 1000000
base = 2
answer = 0
for i in range(1, number + 1):
	if palindrome(i) and i % base ! = 0:
		binary = base_check(i,base)
		if palindrome(binary):
			answer + = i
print(answer)




