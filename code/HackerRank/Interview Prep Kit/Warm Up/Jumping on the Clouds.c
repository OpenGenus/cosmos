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
    int *arr;
    arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",(arr+i));
    }
    int cnt=0;
    if(n>2)
    for(int i=0;i<n;)
    {
        if(i%2==0)
        {
            if(*(arr+i)==0)
            {
                cnt++;
                if(*(arr+i+2)==0)
                {
                    i=i+2;
                }
                else
                {
                    i=i+1;
                }
            }
        }
        else
        {
            if(*(arr+i)==0)
            {
                cnt++;
                if(*(arr+i+2)==0)
                {
                    i=i+2;
                }
                else
                {
                    i=i+1;
                }
            }
        }
    }
    else
    {
    cnt=2;
    }
    printf("%d",cnt-1);
}