#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int c=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        c=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j] && arr[i]!=0)
            {
                c++;arr[j]=0;
            }
        }
        if(c>=2)
        cnt=cnt+c/2;
    }
    printf("%d",cnt);
}
