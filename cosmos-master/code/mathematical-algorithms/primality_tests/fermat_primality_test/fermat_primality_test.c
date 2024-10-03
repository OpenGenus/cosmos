/**
 * C program to implement Fermat's Primality Test
 * based on Fermat's little theorem
 * Part of Cosmos by OpenGenus Foundation
**/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ITERATIONS 100// number of iterations to run the test

//function to calculate modulo using exponential squaring technique
long long expMod(long long base, long long exp, long long c) {
    long long res=1;
    while(exp>0) {
        if(exp%2==1) res=(res*base)%c;
        base=(base*base)%c;
        exp/=2;
    }
    return res%c;
}

//function to run fermat's test
bool fermatTest(long int p, int k) {
    int i;

    if (p==1)
        return false;

    for (i=0; i<k; i++) {
        long long a = rand() % (p - 1) + 1;
        if (expMod(a, p - 1, p) != 1)
            return false;
    }

    return true;
}

/**
 * driver function taking number to be tested
 * and number of iterations as inputs
**/
int main(void) {

    int i;
    for(i = 15; i>1; i--){
        if(fermatTest(i, ITERATIONS))
            printf("%d is prime\n",i);
        else
            printf("%d is composite\n",i);
    }

    return 0;
} 
