#include <stdio.h>

/*
 * Part of Cosmos by OpenGenus Foundation
 */

int
isPalindromeIterative(char *input, int length)
{
	int start = 0, end = length - 1;
	while (start < end)
		if (input[start++] != input[end--])
			return (0);
	return (1);
}

int
is_palindrome_recursive(char *input, int length)
{
	if (length <= 1)
		return (1);
	else if (input[0] != input[length - 1])
		return (0);
	else
		return (is_palindrome_recursive(input + 1, length - 2));
}

int
main(void)
{
	printf("Is hello a palindrome (iterative): %d\n", isPalindromeIterative("hello", 5));
	printf("Is racecar a palindrome (iterative): %d\n", isPalindromeIterative("racecar", 7));
	printf("Is aba a palindrome (iterative): %d\n", isPalindromeIterative("aba", 3));
	printf("Is hello a palindrome (recursive): %d\n", is_palindrome_recursive("hello", 5));
	printf("Is racecar a palindrome (recursive): %d\n", is_palindrome_recursive("racecar", 7));
	printf("Is aba a palindrome (recursive): %d\n", is_palindrome_recursive("aba", 3));

	return (0);
}
