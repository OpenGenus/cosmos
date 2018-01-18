#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Part of Cosmos by OpenGenus Foundation*/

struct xy{
    double x;
    double y;
};

struct xy *
runge_kutt(struct xy start_conditions,
           double start_interval,
           double finish_interval,
           double step,
           int *size_array,
           double (*f)(double, double))
{
    double k1, k2, k3, k4;
    int number_steps = (finish_interval - start_interval) / step;
    *size_array = number_steps + 1;
    struct xy *res = malloc(sizeof(struct xy) * (*size_array));
    res[0] = start_conditions;
    int i;
    for (i = 1; i < (*size_array); ++i){
        k1 = step * f(start_conditions.x, start_conditions.y);
        k2 = step * f(start_conditions.x + step / 2.0, start_conditions.y + k1 / 2.0);
        k3 = step * f(start_conditions.x + step / 2.0, start_conditions.y + k2 / 2.0);
        k4 = step * f(start_conditions.x + step, start_conditions.y + k3);
        start_conditions.y += (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        start_conditions.x += step;
        res[i] = start_conditions;
    }
    return (res);
}

int
main(void)
{
    struct xy start_conditions;
    double start_interval, finish_interval, step;
    int size_array = 0;
    printf("Enter start conditions: ");
    printf("X = ");
    scanf("%lf", &start_conditions.x);
    printf("Y = ");
    scanf("%lf", &start_conditions.y);
    printf("Enter interval: ");
    printf("Start = ");
    scanf("%lf", &start_interval);
    printf("Finish = ");
    scanf("%lf", &finish_interval);
    printf("Enter step: ");
    scanf("%lf", &step);
    struct xy *res = runge_kutt(start_conditions,
                                start_interval,
                                finish_interval,
                                step,
                                &size_array,
                                ({
                                     double f(double x, double y)
                                     {
                                         return (pow(x, 2) * (3 * y + exp(pow(x, 3))));
                                     }
                               f;}));
    int i;
    for (i = 0; i < size_array; ++i){
        printf("X = %lf   Y = %lf \n", res[i].x, res[i].y);
    }
    return (0);
}

