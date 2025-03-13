#include <stdio.h>
#include <string.h>

int
get_map(char* a, char* map)
{
	int map_size = 0;
	
	for(int i = 0; i<26; i++)
		map[i] = 0;

	for(int i = 0; a[i]!='\n'; i++) 
	{
		char ch = (char)tolower(a[i]);
		if((ch!=' ')&&(ch!='\t')){
			map[ch-'a']++;
			map_size ++;
		}
	}

	return map_size;
}

int
main(void)
{
	char string1[1000], string2[1000], map1[26], map2[26];
	int length_string1, length_string2;

	fgets(string1, 1000, stdin);
	fgets(string2, 1000, stdin);

	length_string1 = get_map(string1, map1);
	length_string2 = get_map(string2, map2);


	/* If both strings have a different number of characters, then they are not anagrams */

	if (length_string1 != length_string2) {
		printf("%s and %s are not anagrams! \n", string1, string2);
		return (0);
	}

	/* Compare the character maps for both the strings */

	for (int i = 0; i<26; i++)
		if (map1[i] != map2[i]) {
			puts("The strings are not anagrams!");
			return (0);
		}

	puts("The strings are anagrams!");

	return (0);
}

