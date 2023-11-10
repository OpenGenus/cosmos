#include <stdio.h>
#include <stdlib.h>

struct activity
{
	int start, finish;
};

int 
comparator(const void* s1, const void* s2)
{
	return ((struct activity *)s1)->finish > ((struct activity *)s2)->finish;
}

void
print_max_activities(struct activity arr[], int n)
{
	qsort(arr, n, sizeof(arr[0]), comparator);
	printf("Following activities are selected:-");

	int i = 0, j;
	printf("(%d, %d), ", arr[i].start, arr[i].finish);

	for (j = 1; j < n; j++)
		if (arr[j].start >= arr[i].finish) {
			printf("(%d, %d), ", arr[j].start, arr[j].finish);
			i = j;			
		}
	printf("\n");
}

int
main()
{
	struct activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                       {5, 7}, {8, 9}};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_max_activities(arr, n);

    return (0);
}
