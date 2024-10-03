#include <stdio.h>
// Part of Cosmos by OpenGenus Foundation
// Code written by Adeen Shukla (adeen-s)

int countDigits(unsigned long n)
{
	//If n=0 Stop the execution and return 1 as number of digit is 1
	if (n == 0)
	{
		return (1);
	}

	//Intilialize the count to 0
	int count = 0;

	//Until n is not 0 keep dividing the number to eliminate the last digit and increase the count by 1
	while (n != 0)
	{
		count++;
		n /= 10;
	}

	//Return the number of digits
	return (count);
}

int main()
{
	unsigned long n;
	printf("\nEnter a number\n");
	scanf("%lu", &n);
	printf("\nThe number of digits is --> %d\n", countDigits(n));
	return (0);
}
