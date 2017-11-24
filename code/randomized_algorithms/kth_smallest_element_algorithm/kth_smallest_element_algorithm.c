#include <stdio.h>
void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int find_element(int a[],int n,int k)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
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
    int a[n];
    printf("Enter Elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    int k;
    printf("Enter k (nth smallest element to find) : ");
    scanf("%d",&k);
    int result = find_element(a,n,k);
    printf("kth smallest element is %d\n",result);
    return 0;
}
