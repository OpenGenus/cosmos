/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>

int 
maxSum(int arr[], int n)
{
    int i, j, max = 0;
    int MSis[n];


    for (i = 0; i <= n; i++)
        MSis[i] = arr[i];
    /* Compute maximum sum values in bottom up manner */
    for (i = 1; i < n; i++)
		for(j = 0; j < i; j++)
			if(arr[j] < arr[i] && MSis[i] < MSis[j] + arr[i])
            	MSis[i] = MSis[j] + arr[i];

    /*Find the max value of array MSis */
    for (i = 0; i < n; i++)
        if (max < MSis[i])
            max = MSis[i];

    return (max);
}

int 
main() 
{
	int arr[] = {4, 6, 1, 3, 8, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of maximum sum increasing subsequence is %d \n", maxSum(arr, n));

	return (0);
}
