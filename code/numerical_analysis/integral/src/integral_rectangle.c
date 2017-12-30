#include <stdio.h>

/*Part of Cosmos by OpenGenus Foundation*/

double
integral_rectangle(double a, double b, double step, double (*f)(double))
{
    double fragment = (b - a) / step;
    double res = step * (f(a) + f(b)) / 6.0;
    int i;
    for (i = 1; i <= fragment; ++i)
        res += 4.0 / 6.0 * step * f(a + step * (i - 0.5));

    for (i = 1; i <= fragment - 1; ++i)
        res += 2.0 / 6.0 * step * f(a + step * i);
    return (res);
}

int
main(void)
{
    double a, b, step, res;
    printf("Enter interval: \n");
    printf("a: \n");
    scanf("%lf", &a);
    printf("b: \n");
    scanf("%lf", &b);
    printf("Enter integration step: ");
    scanf("%lf", &step);
    res = integral_rectangle(a, b, step,
                             ({
                                  double f(double x)
                                  {
                                      return x * x + x;
                                  }
                             f;}));
    printf("Result =  %lf \n", res);
    return (0);
}
