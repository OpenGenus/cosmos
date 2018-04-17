#include <stdio.h>
int modularInverse(int number, int mod);
void extendedEuclid(int, int, int* d, int* x, int* y);
int main()
{
    int number, mod;
    scanf("%d %d", &number, &mod);
    int ans = modularInverse(number, mod);
    if (ans == -1)
        fprintf(stderr, "Couldn't calculate modular inverse!\n");
    else
        printf("%d", ans);

}
int modularInverse(int number, int mod)
{
    if (1 <= number && number <= mod - 1)
    {
        int x, y, d;
        extendedEuclid(number, mod, &d, &x, &y);
        if (d == 1)
        {
            while (x < 0)
                x += mod;
            return x;
        }
        else
            fprintf(stderr, "The number and mod need to be coprime\n");
    }
    else
        fprintf(stderr, "Number needs to be between 1 and mod!\n");
    return -1;
}
void extendedEuclid(int a, int b, int* d, int* x, int* y)
{
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        *d = a;
        return;
    }
    int x0, y0;
    extendedEuclid(b, a % b, d, &x0, &y0);
    *x = y0;
    *y = x0 - (a / b) * y0;
}
