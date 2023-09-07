#include<iostream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<string>

void
toggle_char(std::string &str)
{

	/* loop through every character of string */
	for (int i = 0; str[i] != '\0'; i++) {
		/* if character index is not a letter, skip it */
		if (!isalpha(str[i])) continue;
	
		/* changes lower to upper and upper to lower */
		str[i] = (islower(str[i])) ? toupper(str[i]) : tolower(str[i]);
	}
}


int 
main ()
{
	std::string str;
	std::cout << "Enter a string : ";
	std::getline(std::cin, str);

	toggle_char(str);
	
	std::cout << "Resultant string : " << str << std::endl;
}
