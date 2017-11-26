#include <stdio.h>
void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int find_element(int arr[],int n,int k)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    return a[k-1];
}
int main()
{
    int n;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int k;
    printf("Enter k (nth smallest element to find) : ");
    scanf("%d",&k);
    printf("kth smallest element is %d\n",find_element(arr,n,k));
    return 0;
}
