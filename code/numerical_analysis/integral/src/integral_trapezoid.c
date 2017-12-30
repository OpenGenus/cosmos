#include <stdio.h>

/*Part of Cosmos by OpenGenus Foundation*/

double
integral_trapezoid(double a, double b, double step, double (*f)(double))
{
    double fragment = (b - a) / step;
    double res = step * (f(a) + f(b)) / 2.0;
    int i;
    for (i = 1; i <= fragment - 1; ++i)
        res = res + step * f(a + step * i);
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
    res = integral_trapezoid(a, b, step,
                             ({
                                  double f(double x)
                                  {
                                      return x * x + x;
                                  }
                            f;}));
    printf("Result =  %lf \n", res);
    return (0);
}
