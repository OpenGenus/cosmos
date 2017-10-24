/* Part of Cosmos by OpenGenus Foundation */

#include <stdio.h>

int maxSum(int arr[], int N)
{
    int i , j , max = 0;
    int MSis[N];


    for(i = 0; i<=N; i++)
    {
        MSis[i] = arr[i];
    }
    /* Compute maximum sum values in bottom up manner */
    for(i=1; i < N; i++)
    {
      for(j=0; j < i; j++)
      {
          if(arr[j] < arr[i] && MSis[i] < MSis[j] + arr[i])
            MSis[i] = MSis[j] + arr[i];

      }
    }
    /*Find the max value of array MSis */
    for(i=0; i < N; i++)
    {
        if(max < MSis[i])
            max = MSis[i];
    }
    return max;
}
int main() {
	int arr[] = {4, 6, 1, 3, 8, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Sum of maximum sum increasing subsequence is %d",
           maxSum( arr, n ) );
	return 0;
}
