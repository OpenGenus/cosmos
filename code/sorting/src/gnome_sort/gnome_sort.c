#include <stdio.h>

void 
swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void 
gnomeSort(int arr[], int n)
{
    int index = 0;
 
    while (index < n) {
        if (index == 0)
            ++index;

        if (arr[index] >= arr[index - 1])
            ++index;

        else {
            swap(&arr[index], &arr[index - 1]);
            --index;
        }
    }
    
    return;
}

int 
main()
{
    int n;
    printf("Enter size of Array \n");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d Integers \n", n);
    int i;
    for (i = 0; i < n; ++i)
    	scanf("%d", &arr[i]);
 
    gnomeSort(arr, n);

    printf("Array after sorting: \n");
 	for (i = 0; i < n; ++i)
    	printf("%d ", arr[i]);
    printf("\n");   
 
    return (0);
}
