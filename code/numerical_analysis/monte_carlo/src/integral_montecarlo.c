#include <stdio.h>
#include <stdlib.h>

/*Part of Cosmos by OpenGenus Foundation*/

double
integral_monte_carlo(double a, double b, double point_count, double (*f)(double))
{
    double x, y = 0;
    int i;
    for (i = 0; i < point_count; ++i){
        x = ((b - a) * ((double)random() / RAND_MAX)) + a;
        y += f(x);
    }
    return ((b - a) * (y / point_count));
}

int
main(void)
{
    double a, b, point_count, res;
    printf("Enter interval: \n");
    printf("a: \n");
    scanf("%lf", &a);
    printf("b: \n");
    scanf("%lf", &b);
    printf("Enter point count: ");
    scanf("%lf", &point_count);
    res = integral_monte_carlo(a, b, point_count, ({
                                                       double f(double x)
                                                       {
                                                           return (x * x + x);
                                                       }
                                                   f;}));
    printf("Result =  %lf \n", res);
    return (0);
}
