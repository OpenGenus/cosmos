/*
Problem Statement :
Clear all MSB's except for the first i LSB's of a number n.
MSB -> Most Significant Bit
LSB -> Most Significant Bit
*/

#include <stdio.h>

int clear_bits_from_msb(int n, int i)
{
	int mask = (1 << i) - 1;
	return n & mask;
}

int main()
{
	int n, i;
	printf("Enter n and i : ");
	scanf("%d %d", &n, &i);

	n = clear_bits_from_msb(n, i);
	printf("\nResult : %d", n);

	return 0;
}

/*
Enter n and i : 14 3

Result : 6
*/
