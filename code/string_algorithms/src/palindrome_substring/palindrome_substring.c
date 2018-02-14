#include <stdio.h>

/*
 * Utilises 'iattempt' palindrome.c implementation.
 * Part of Cosmos by OpenGenus Foundation.
*/

int isPalindromeIterative(char *input, int length)
{
	int start = 0, end = length;
	while (start < end)
		if (input[start++] != input[end--])
			return (0);
	return (1);
}

int list_palindrome_substrings(char *input, int length)
{
	int start = 0, end = 0;
	int response = 0;
	int original_end = length - 1;

	while(start < original_end){
		for(end = 1; end <= (original_end - start); ++end)
			response += isPalindromeIterative(&input[start], end);
		++start;
	}
	return response;
}

int main(void)
{
	printf("Number of Possible Palindrome Substrings: %d\n", list_palindrome_substrings("abaab", 5));
	return (0);
}