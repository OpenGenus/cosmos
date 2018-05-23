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
