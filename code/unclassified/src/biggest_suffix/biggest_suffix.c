#include <stdio.h>
#include <string.h>

int equality(char *s1, char *s2, int x)
{
	if(strcmp(s1 + strlen(s1) - x, s2 + strlen(s2) - x) == 0)
		return 1;
	return 0;
}

char *biggest_suffix(char *s1, char *s2)
{
	int i;
	int shortest_string; /* Finds the number of characters that needs to traversed to check smallest substring */
	int reminder = 0; /* Keeps count of number of characters that are same in both the strings starting from back */

	if(strlen(s1) > strlen(s2))
		shortest_string = strlen(s2);
	else
		shortest_string = strlen(s1);

	for(i = 0; i <= shortest_string; i++)
	{
		if( equality(s1, s2, i) )
			reminder = i;
		else
			break;
	}

	if(reminder == 0)
		return "No suffix";
	else
		return s1 + strlen(s1) - reminder;

}

int main(void)
{
	char s1[100];
	char s2[100];
	printf("Give first string:\n");
	scanf("%s", s1);
	printf("Give second string:\n");
	scanf("%s", s2);

	printf("Biggest suffix is: %s\n", biggest_suffix(s1, s2) );


	return 0;
}
