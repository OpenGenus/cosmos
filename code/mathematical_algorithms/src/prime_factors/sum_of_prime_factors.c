// A C program to find the sum of all the primes factors of given number .
#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long int i,j,sum=0;
    int *primes,num;
    int z = 1;
    printf("Enter the Number:");
    scanf("%d",&num);
    primes = malloc(sizeof(int) * num);

    for (i = 2;i <= num; i++)
        primes[i] = 1;

    for (i = 2;i <= num; i++)
        if (primes[i])
            for (j = i;i * j <= num; j++)
                primes[i * j] = 0;

    printf("\nPrime numbers are: \n");
    for (i = 2;i <= num; i++)
        if (primes[i]&& num%i==0)
          sum+=i;
            printf("%lld\n", sum);

return 0;
}
