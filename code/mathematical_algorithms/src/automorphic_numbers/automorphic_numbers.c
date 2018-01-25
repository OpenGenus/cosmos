/* 
 * Part of Cosmos by OpenGenus.
 * Implementing automorphic numbers in C.
 * run code with gcc automorphicnumbers.c -lm as I use math library.
 */
#include <stdio.h>
#include <math.h>

int 
main()
{
    long long int n , p, count=0, q;
    unsigned long long int k;
    
    /* The number is given by  user for checking automorphism. */
    scanf("%lld",&n);
    p = n;
    
    while (p) {
        /* While here we count that our number is in which range bsically we count number of digits in our number. */
        count++;
        p = p / 10;
    }
    
    /* The ten power number just after our number for calculating mod value. */
    q = pow(10, count);
    k = n * n;
    k = k % q;
    
    if (k == n)
        printf("Given number is automorphic.\n");
    
    else
        printf("Given number is not automorphic.\n");
    
    return (0);    
}
