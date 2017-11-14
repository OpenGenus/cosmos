#include <stdio.h>

/*
 * This can be similarly implemented for other data types
 */
void
xor_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;

	return;
}

int main()
{
	int a = 10, b = 15;

	printf("Before swapping: A = %d and B = %d\n", a, b);

	xor_swap(&a, &b);

	printf("After swapping: A = %d and B = %d\n", a, b);

	return 0;
}