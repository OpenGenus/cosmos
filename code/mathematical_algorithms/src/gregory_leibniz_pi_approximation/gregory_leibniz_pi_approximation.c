/*
 * Gregory–Leibniz series
 * Alex Day
 * Part of Cosmos by OpenGenus Foundation
 * c99 -Wall -o gregory_leibniz_pi_approximation gregory_leibniz_pi_approximation.c -lm
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double
pi(int k)
{
	double total = 0;
	for(int i = 0; i <= k; i++) {
		total += pow(-1, i) / ((2*i) + 1);
	}

	return (total * 4);
}

int
main(int argc, char* argv[])
{
	int k = 5;
	if (argc == 2)
		k = atoi(argv[1]);

	printf("Pi approximated to %d is %g",
			k,
			pi(k));
	return (EXIT_SUCCESS);
}
