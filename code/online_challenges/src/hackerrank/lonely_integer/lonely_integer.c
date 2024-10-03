#include <stdio.h>
int main()     
{
    int n,j=0,a,i;
    scanf("%d",&n);    
    int arr[n];
    for(i=0;i<n;++i)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;++i)
    {
        j=j^arr[i];
    }
    printf("%d",j);
    return 0;
}
