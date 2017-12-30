# include <stdio.h>
# include <math.h>

void 
primeFactors(int n)
{
    int i;
    while (n % 2 == 0) {
        printf("%d ", 2);
        n = n / 2;
    }

    for (i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            printf("%d ", i);
            n = n / i;
        }
    }

    if (n > 2)
        printf ("%d ", n);
}

int 
main()
{
    int n;
    printf("Enter a Natural Number \n");
    scanf("%d", &n);
    printf("Prime Factors of %d are:- \n", n);
    primeFactors(n);
    printf("\n");

    return (0);
}
