#include<stdio.h>

 
void Sieve(int n)
{
   
    int  arr[n+1],i,p;
   for(i=1;i<=n;i++)
      arr[i]=1;
    for ( p=2; p*p<=n; p++)
    {
        
        if (arr[p] ==1)
        {
           
            for ( i=p*2; i<=n; i += p)
                arr[i] = 0;
        }
    }
 
   
    for ( p=2; p<=n; p++)
       if (arr[p])
         printf("%d ",p);
}
 

int main()
{
    int n = 40;
    printf("Following are the prime numbers smaller than or equal to n \n");
    Sieve(n);
    return 0;
}
