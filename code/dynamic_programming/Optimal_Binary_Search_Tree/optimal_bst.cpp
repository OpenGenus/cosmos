#include <stdio.h>
#include <limits.h>

int sum(int freq[], int i, int j);
int ans[10005][10005];

int optCost(int freq[], int i, int j)
{
   if (ans[i][j]!=0)   //answer is already computed
     return ans[i][j];
   if (j < i)          // no elements in this subarray
     return 0;
   if (j == i)         // one element in this subarray
     return freq[i];
 
   
   int fsum = sum(freq, i, j);
 
   int min = INT_MAX;
 
   for (int r = i; r <= j; ++r)
   {
       int cost = optCost(freq, i, r-1) + optCost(freq, r+1, j);
       if (cost < min)
          min = cost;
   }
   // Save value for future reference
   ans[i][j]=min+fsum;
   return ans[i][j];
}
 

int optimalSearchTree(int keys[], int freq[], int n)
{
     return optCost(freq, 0, n-1);
}
 
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = 3;
    printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));
    return 0;
}
