/* This project aims to demonstrate various operations on linked lists. It uses
a clean command line interface and provides a baseline to make linked list
applications in C. There are two files. The C file containing main() function and
invoking functions. The link.h header file where all functions are implemented.
*/

#include "link.h"       /* custom header file to implement functions */

/* For clearing screen in Windows and UNIX-based OS */
#ifdef _WIN32
	#define CLEAR "cls"
#else 		/* In any other OS */
	#define CLEAR "clear"
#endif

/* For cross-platform delay function for better UI transition */
#ifdef _WIN32
	#include <Windows.h>
#else
	#include <unistd.h>		/* for sleep() function */
#endif

void
msleep(int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void print();
void clear();
int menu();

int
main()
{
	int c;

	do
	{
		c = menu();
	}while(c!=17);
}

void
print()
{
	printf("1. Insert at beginning\n");
	printf("2. Insert at end\n");
	printf("3. Insert at a particular location\n");
	printf("4. Insert after a particular value\n");
	printf("5. Delete from beginning\n");
	printf("6. Delete from end\n");
	printf("7. Delete a particular node\n");
	printf("8. Delete a particular value\n");
	printf("9. Replace a value at a particular node\n");
	printf("10. Replace a particular value in the list\n");
	printf("11. Delete all duplicate values and sort\n");
	printf("12. Display\n");
	printf("13. Reverse\n");
	printf("14. Sort(Ascending)\n");
	printf("15. Write to File\n");
	printf("16. Read from a file\n");
	printf("17. Quit\n");
}

int
menu()
{
	clear();
	msleep(500);		/* for delay effect 500ms */

	print();

	int n, a, b;
	char *filename = (char *) malloc(MAX_LENGTH*sizeof(char));		/* For writing and reading linked list data from file */
	printf("Select the operation you want to perform (17 to Quit): ");
	scanf("%d", &n);

	switch(n)
	{
		case 1:
			printf("Enter the number you want to insert: ");
			scanf("%d", &a);
			insert_beg(a);
			break;
		case 2:
			printf("Enter the number you want to insert: ");
			scanf("%d", &a);
			insert_end(a);
			break;
		case 3:
			printf("Enter the number you want to insert: ");
			scanf("%d", &a);
			printf("Enter the location in which you want to insert: ");
			scanf("%d", &b);
			insert_at_loc(a, b);
			break;
		case 4:
			printf("Enter the number you want to insert: ");
			scanf("%d", &a);
			printf("Enter the value after which to insert: ");
			scanf("%d", &b);
			insert_after_value(a, b);
			break;
		case 5:
			delete_beg();
			break;
		case 6:
			delete_end();
			break;
		case 7:
			printf("Enter the location of node to delete: ");
			scanf("%d", &a);
			delete_node(a);
			break;
		case 8:
			printf("Enter the value you want to delete: ");
			scanf("%d", &a);
			delete_value(a);
			break;
	  	case 9:
			printf("Enter the location of node you want to replace: ");
			scanf("%d", &b);
			printf("Enter the new number: ");
			scanf("%d", &a);
			replace_node(a, b);
			break;
		case 10:
			printf("Enter the value you want to replace: ");
			scanf("%d", &a);
			printf("Enter the new number: ");
			scanf("%d", &b);
			replace_value(b, a);
			break;
		case 11:
			delete_dup_vals();
			break;
		case 12:
			display();
			msleep(5000);
			break;
	    case 13:
			reverse();
			break;
		case 14:
			sortlist();
			break;
		case 15:
			printf("Enter the name of file to write to: ");
			scanf("%s", filename);
			writefile(filename);
			break;
		case 16:
			listfile();
			printf("Enter the name of file to read from: ");
			scanf("%s", filename);
			readfile(filename);
			break;
		case 17:
			return (n);
	}
	return (0);
}

void
clear(void)
{
	system(CLEAR);		/* Cross-platform clear screen */
}
