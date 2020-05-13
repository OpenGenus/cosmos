#include <stdio.h>
#include <stdlib.h>

// structure to represent an activity 
struct activity
{
	int start, finish;
};

// function to compare finish time of two activities 
int 
comparator(const void* s1, const void* s2)
{
	return ((struct activity *)s1)->finish > ((struct activity *)s2)->finish;
}

// function to select the activities
void
print_max_activities(struct activity arr[], int n)
{
	// sorting the activities on the basis of finishing time
	qsort(arr, n, sizeof(arr[0]), comparator);
	printf("Following activities are selected:-");

	int i = 0, j;
	// choosing the first activty from the sorted array
	printf("(%d, %d), ", arr[i].start, arr[i].finish);

	// for the rest of activities
	for (j = 1; j < n; j++) {
		// choosing the next compatible activities
		if (arr[j].start >= arr[i].finish) {
			printf("(%d, %d), ", arr[j].start, arr[j].finish);
			i = j;			
		}
	}
	printf("\n");
}

int
main()
{
	// initializing a list of activities
	struct activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                       {5, 7}, {8, 9}};
        // no. of activities
	int n = sizeof(arr) / sizeof(arr[0]);
        // printing the selected activities 
	print_max_activities(arr, n);

    return (0);
}
