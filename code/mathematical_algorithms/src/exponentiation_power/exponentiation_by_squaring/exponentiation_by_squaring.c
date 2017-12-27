#include <stdio.h>

int 
power(int num, int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1) 
		return (num);

	int temp = power(num, exp / 2);
	temp *= temp;
	if (exp % 2 == 1 )
		temp *= num;

	return (temp);
}

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