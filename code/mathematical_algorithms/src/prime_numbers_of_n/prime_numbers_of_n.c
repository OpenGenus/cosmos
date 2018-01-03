# include <stdio.h>
# include <math.h>

int 
primeFactors(int number, int prime_factors[100])
{
    int i, j = -1;
    while (number % 2 == 0) {
    	++j;
    	prime_factors[j] = 2;
        number = number / 2;
    }

    for (i = 3; i <= sqrt(number); i = i + 2) {
        while (number % i == 0) {
            ++j;
            prime_factors[j] = i;
            number = number / i;
        }
    }

    if (number > 2) {
    	++j;
    	prime_factors[j] = number;
    }

    return (j);
}

int 
main()
{
    int number, prime_factors[100], i;
    printf("Enter a Natural Number \n");
    scanf("%d", &number);
    int number_of_prime_factors=primeFactors(number, prime_factors);

    printf("Prime Factors of %d are:- \n", number);
    for(i=0; i <= number_of_prime_factors; i++)
    	printf("%d ", prime_factors[i]);
    printf("\n");

    return (0);
}
