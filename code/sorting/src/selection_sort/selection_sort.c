/* Part of Cosmos by OpenGenus Foundation */
#include <stdio.h>
int main()
{
    int n,i,j,temp,a[1000];
    printf("\n Enter the number of Elements: ");
    scanf("%d",&n);
    printf("\n Enter the Elements of array");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            }
    }}
    printf("\n The Sorted array is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
