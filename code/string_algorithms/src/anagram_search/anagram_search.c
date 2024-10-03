#include <stdio.h>
#include <string.h>

void swap(char*, char*);
void sort(char*, char*);

int
main(void)
{
	char string1[80], string2[80];
	int length_string1;

	scanf("%s", string1);
	scanf("%s", string2);

	length_string1 = strlen(string1);


	/* If both strings are of different length, then they are not anagrams */

	if (length_string1 != strlen(string2)) {
		printf("%s and %s are not anagrams! \n", string1, string2);
		return (0);
	}

	/* lets sort both strings first */
	sort(string1, string2);

	/* Compare both strings character by character */

	for (int i = 0; i<length_string1; i++)
		if (string1[i] != string2[i]) {
			puts("Strings are not anagrams!");
			return (0);
		}

	puts("Strings are anagrams!");

	return (0);
}

void swap(char* ch1, char* ch2)
{
	char tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

void sort(char* string1, char* string2)
{
	int length_string1 = strlen(string1);
	for (int i = 0; i < length_string1-1; i++)
		for (int j = i+1; j < length_string1; j++) {
			if (string1[i] > string1[j]) {
				swap(&string1[i], &string1[j]);
			}
			if (string2[i] > string2[j]) {
				swap(&string2[i], &string2[j]);
			}
		}
}