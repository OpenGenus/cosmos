/* Part of Cosmos by OpenGenus Foundation. */

#include <stdio.h>

/* 
 * Returns value of Binomial Coefficient C(n, k). 
 */
unsigned long int 
binomial_Coeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
    int i ;
 
    /* Since C(n, k) = C(n, n-k) */
    if (k > n - k)
        k = n - k;
 
    /* Calculate value of nCk */
    for (i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return (res);
}
 
/*
 * A Binomial coefficient based function to find nth catalan
 * O(n) time Solution.
 */
unsigned long int 
catalan(unsigned int n)
{
    /* Calculate value of 2nCn */
    unsigned long int c = binomial_Coeff(2 * n, n);
 
    /* return 2nCn/(n+1) */
    return (c / (n+1));
}
 
/* Driver program to test above functions. */
int 
main()
{
    unsigned int n;
    
    printf("Input n \nNth Catalan you want :");
    scanf("%d", &n);
    
    printf("Nth Catalan number is: %lu", catalan(n));
    
    return (0);
}
