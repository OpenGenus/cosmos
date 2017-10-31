#include<stdio.h>
 
int main()
{
    int i,j,n,loc,temp,min,a[30];
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("\nEnter the elements\n");
 
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
    printf("\nSorted list is as follows\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
 
    return 0;
}
