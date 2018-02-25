#include <stdio.h>
#define true 1
#define false 0

/*
 * Utilises 'iattempt' palindrome.c implementation.
 * Part of Cosmos by OpenGenus Foundation.
*/

int
isPalindromeIterative(char *input, int length)
{
	int start = 0, end = length;
	while (start < end)
		if (input[start++] != input[end--])
			return false;
	return true;
}

int
countPalindromeSubstrings(char *input, int length)
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
	printf("Number of Possible Palindrome Substrings: %d\n", countPalindromeSubstrings("abaab", 5));
	return (0);
}