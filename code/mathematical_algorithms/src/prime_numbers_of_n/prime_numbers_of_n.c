# include <stdio.h>
# include <math.h>

void 
primeFactors(int number)
{
    int i;
    while (number % 2 == 0) {
        printf("%d ", 2);
        number = number / 2;
    }

    for (i = 3; i <= sqrt(number); i = i + 2) {
        while (number % i == 0) {
            printf("%d ", i);
            number = number / i;
        }
    }

    if (number > 2)
        printf ("%d ", number);
}

int 
main()
{
    int number;
    printf("Enter a Natural Number \n");
    scanf("%d", &number);
    printf("Prime Factors of %d are:- \n", number);
    primeFactors(number);
    printf("\n");

    return (0);
}
