#include <stdio.h>

void
reverse_factorial(long long int factorial)
{
	long long int n = 1,m = 0;
	while (m < 100) {
		m += 1;
		n *= m;
		if (factorial == n) {
			printf("%lli is %lli!\n",factorial,m);
			break;
		}
		else if (m == 100)
			printf("%lli is not a factorial product of any integer\n",factorial);
	}
}

int
main()
{
	long long int factorial;
	printf("Reverse Factorial > ");
	scanf("%lli",&factorial);
	reverse_factorial(factorial);

	return (0);
}