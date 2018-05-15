#include<stdio.h>
// Part of Cosmos by OpenGenus Foundation
// Code written by Adeen Shukla (adeen-s)

int 
countDigits(unsigned long n) 
{
	if(n == 0) {
		return (1);
	}
	int count = 0;
	while(n != 0) {
		count++;
		n /= 10;
    }
	return (count);
}

int 
main()
{
	unsigned long n;
	printf("\nEnter a number\n");	
	scanf("%lu", &n);
	printf("\nThe number of digits is --> %d\n", countDigits(n));
	return (0);
}
