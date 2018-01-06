# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int*
primeFactors(int number)
{
    int* prime_factors = (int *)malloc(100 * sizeof(int));
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

    return (prime_factors);
}

int 
main()
{
    int number, i;
    printf("Enter a Natural Number \n");
    scanf("%d", &number);
    int* result = primeFactors(number);

    printf("Prime Factors of %d are:- \n", number);
    for (i = 0; result[i] != 0; i++)
        printf("%d ", result[i]);
    printf("\n");

    return (0);
}
