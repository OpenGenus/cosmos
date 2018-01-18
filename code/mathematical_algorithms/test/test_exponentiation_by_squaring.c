#include <stdio.h>
#include "exponentiation_by_squaring.c"

int 
main()
{
	int num, exp;
	printf("Enter Number \n");
	scanf("%d", &num);
	printf("Enter Exponent \n");
	scanf("%d", &exp);
	printf("Result: %d \n", power(num, exp));

	return (0);
}
