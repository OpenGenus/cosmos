#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned int i = 1;
	char *x = (char*)&i;

	if(*x)
	{
		printf("Little Endian\n");
	}
	else
	{
		printf("Big Endian\n");
	}

	return 0;
}