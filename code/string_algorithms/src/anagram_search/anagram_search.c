#include <stdio.h>
#include <string.h>

int
main(void)
{
	char string1[1000], string2[1000], temp;
	int length_string1, length_string2;

	scanf("%s", string1);
	scanf("%s", string2);

	length_string1 = strlen(string1);
	length_string2 = strlen(string2);


	/* If both strings are of different length, then they are not anagrams */

	if (length_string1 != length_string2) {
		printf("%s and %s are not anagrams! \n", string1, string2);
		return (0);
	}

	/* lets sort both strings first */

	for (int i = 0; i < length_string1-1; i++)
		for (int j = i+1; j < length_string1; j++) {
			if (string1[i] > string1[j]) {
				temp  = string1[i];
				string1[i] = string1[j];
				string1[j] = temp;
			}
			if (string2[i] > string2[j]) {
				temp = string2[i];
				string2[i] = string2[j];
				string2[j] = temp;
			}
		}

	/* Compare both strings character by character */

	for (int i = 0; i<length_string1; i++)
		if (string1[i] != string2[i]) {
			puts("Strings are not anagrams!");
			return (0);
		}

	puts("Strings are anagrams!");

	return (0);
}

