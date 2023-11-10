#include <stdio.h>

void
collatz_conjecture_sequence(int n)
{
	printf("%d ", n);
	while (n != 1) {
		if(n % 2 == 0)
			n = n / 2;
		else
			n = (3 * n) + 1;
		printf("%d ", n);
	}
	printf("\n");
}

int
main()
{
	int n = 15;
	collatz_conjecture_sequence(n);

	return (0);
}
