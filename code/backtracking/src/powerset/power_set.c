#include <stdio.h>
#include <math.h>

void
find_power_set(char *set, int set_size)
{
	unsigned int power_set_size = 1 << set_size;
	int counter, j;

	for (counter = 0; counter < power_set_size; counter++) {
		for (j = 0; j < set_size; j++) {
			if (counter & (1 << j))
				printf("%c", set[j]);
		}
		printf("\n");
	}
}

int
main()
{
	char set[] = {'a', 'b', 'c'};
	find_power_set(set, sizeof(set) / sizeof(set[0]));
	return (0);
}
