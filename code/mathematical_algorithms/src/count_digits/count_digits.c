// Program to count the number of digits in a number
#include<stdio.h>
// Part of Cosmos by OpenGenus Foundation
// Code written by Adeen Shukla (adeen-s)

// Function to count the number of digits
int countDigits(unsigned long n)
{
	// if input is equal to 0 then,
	// return 1
	if(n == 0)
	{
		return (1);
	}
	// intializing a variable count to 0
	// for counting the number of digits
	int count = 0;
        // divide the number continuously by 10
	// while incrementing count until the number
	// becomes equal to zero
	while(n != 0)
	{
		count++;
		n /= 10;
  }
	return (count);
}

int main()
{
	unsigned long n;
	printf("\nEnter a number\n");
	scanf("%lu", &n);
	// Printing the number of digits in the number by
	// using countDigits function
	printf("\nThe number of digits is --> %d\n", countDigits(n));
	return (0);
}
