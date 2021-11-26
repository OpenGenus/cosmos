/*

// mathematical algorithms | fibonacci number | fast fibonacci | C
// Part of Cosmos by OpenGenus Foundation

*/


#include <stdio.h>

typedef unsigned long long llu;

llu Fibo(llu n)//finds nth Fibonacci term
{
    return (llu)((pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5)+0.5);
}
