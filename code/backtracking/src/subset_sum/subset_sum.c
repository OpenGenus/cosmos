// Part of Cosmos by OpenGenus Foundation

#include <stdio.h>
// Recursive Solution
// Driver program to test above function


// Returns true if there is a subset of set[] with sun equal to given sum
int isSubsetSum(int set[], int n, int sum)
{
   // Base Cases
   if (sum == 0)
     return 1;
   if (n == 0 && sum != 0)
     return 0;
 
   // If last element is greater than sum, then ignore it
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element   */
   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main()
{
    int n,i,sum;
    printf("Input number of elements\n");
    scanf("%d",&n);
    int set[n];
    printf("Input array elements\n");
    for(i = 0; i < n;i++)
    scanf("%d",&set[i]);
    printf("Enter Sum to check\n");
    scanf("%d",&sum);
    if (isSubsetSum(set, n, sum) == 1)
     printf("Found a subset with given sum\n");
    else
     printf("No subset with given sum\n");
    return 0;
}
