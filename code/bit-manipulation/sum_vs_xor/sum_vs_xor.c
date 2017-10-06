#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int solve(long int n) {
    long c = 0;
    while(n){
         c += n%2?0:1;
         n/=2; 
    }
    c=pow(2,c);
    return c;
}

int main() {
    long int n; 
    scanf("%li", &n);
    long int result = solve(n);
    printf("%ld\n", result);
    return 0;
}
