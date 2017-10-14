// Implementing automorphic numbers in C
// run code with gcc automorphicnumbers.c -lm as I use math library
#include<stdio.h>
#include<math.h>
int main()
{
    long long int n,p,count=0,q;
    unsigned long long int k;
     scanf("%lld",&n);                      //The number is given by  user for checking automorphism
    p=n;
    while(p)
    {
        count++;                            //While here we count that our number is in which range bsically we count number of digits in our number.
        p=p/10;
    }
    q=pow(10,count);                        // The ten power number just after our number for calculating mod value. 
    k=n*n;
    k=k%q;
    if(k==n)
        printf("Given number is automorphic\n");
    else
        printf("Given number is not automorphic\n");
return 0;    
}