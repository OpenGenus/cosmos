/* This project aims to demonstrate various operations on linked lists. It uses
a clean command line interface and provides a baseline to make linked list
applications in C. There are two files. The C file containing main() function and
invoking functions. The link.h header file where all functions are implemented.
*/

#include <unistd.h>     // for sleep() function
#include "link.h"       // custom header file to implement functions

void print();
void clear();
int menu();

int main()
{
	int c;
	printf("WELCOME TO THE LINKED LIST APPLICATION\n");
	clear();
	usleep(500000);

	do
	{
		c = menu();
	}while(c!=17);
}
