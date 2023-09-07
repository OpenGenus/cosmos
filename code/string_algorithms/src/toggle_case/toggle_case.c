#include <stdio.h>

void
toggle_case(char *str_to_toggle) 
{
	/* lower and upper case characters are separated by 32 on the ASCII table
	 * This algorithm determines whether the current character is upper or  
	 *    lower case and then adds or subtracts 32 from the ASCII value to convert
	 */ 
	
	int i = 0;
	while (str_to_toggle[i] != '\0') {
		/* if statements check that ASCII value is char */
		if (str_to_toggle[i] > 64 && str_to_toggle[i] < 91) {
		/* char is upper case, convert to lower */
			str_to_toggle[i] += 32;
		} else if (str_to_toggle[i] > 96 && str_to_toggle[i] < 123) {
		/* char is lower case, convert to upper */
			str_to_toggle[i] -= 32;
		}

		i++;
	}
}

int 
main () 
{
	char str[256];
	printf("Enter string: ");
	fgets(str, 256, stdin);
	toggle_case(str);
	printf("Resultant string: %s\n", str);
	return (0);
}
