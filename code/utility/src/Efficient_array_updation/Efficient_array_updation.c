#include<stdio.h>
long long int a[100007]={0},b[100008]={0};
int main()
{
        long long int n,q,l,r,i,x,j,s=0;
        printf("Enter the number of elements in the array and number of queries: \n");
        scanf("%lld %lld",&n,&q);
         printf("Enter the elements in the array: \n");
        for(i=0;i<n;i++)
        {
                scanf("%lld",&a[i]);
                if(i==0)
                        b[i]=a[i];
                else
                        b[i] = a[i]-a[i-1];
        }
        for(i=0;i<q;i++)
        {
                printf("Enter the left index,right index and the number you want to add to all numbers betwwen these indices: \n");
                scanf("%lld %lld %lld",&l,&r,&x);
                b[r+1] -= x;
                b[l] += x;
        }
        for(i=0;i<n;i++)
        {
                if(i==0)
                        a[0]=b[0];
                else
                        a[i]=b[i]+a[i-1];
        }
        printf("The updated array: \n");
        for(i=0;i<n;i++)
        {
                printf("%lld ",a[i]);
        }
        printf("\n");

        return 0;
}

