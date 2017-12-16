/*
 * Pangram is a sentence containing every alphabet.
 * Part of Cosmos by OpenGenus Foundation
 */
#include<stdio.h>

int
main()
{
	/*
	 * s: stores the sentence.
	 * letter: Keep track of each alphabet.
	 * count: Keep track of the count.
	 */
	char s[10000];
	int i, letter[26] = { 0 }, count = 0;

	puts("\n Enter the String:");
	scanf("%[^\n]s", s);

	for (i = 0; s[i] != '\0'; i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			if (letter[s[i] - 'a'] == 0) {
				letter[s[i]-'a'] = 1;
				count++;
			}
		} else if('A' <= s[i] && s[i] <= 'Z') {
			if (letter[s[i]-'A'] == 0) {
				`letter[s[i]-'A'] = 1;
				count++;
			}
		}
	}

	if (count == 26)
		printf("\n String %s is a Pangram.",s);
	else
		printf("\n String %s is NOT a Pangram.",s);

	return (0);
}
