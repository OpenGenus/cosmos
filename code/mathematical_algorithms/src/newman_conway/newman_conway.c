#include <stdio.h>

void
newman_conway_sequence(int number_of_terms)
{
	int array[number_of_terms + 1];
	array[0] = 0;
	array[1] = 1;
	array[2] = 1;

	int i;
	for (i = 3; i <= number_of_terms; i++)
		array[i] = array[array[i - 1]] + array[i - array[i - 1]];

	for (i = 1; i <= number_of_terms; i++)
		printf("%d ",array[i]);
	printf("\n");
}

int 
main()
{
	int number_of_terms = 20;
	newman_conway_sequence(number_of_terms);

	return (0);
}
