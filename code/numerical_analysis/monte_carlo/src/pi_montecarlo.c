#include <stdio.h>
#include <stdlib.h>

/*Part of Cosmos by OpenGenus Foundation*/

double
pi_monte_carlo(double point_count)
{
    double pi, x, y, circle_points = 0;
    int i;
    for (i = 0; i < point_count; ++i){
        x = (double)random() / RAND_MAX;
        y = (double)random() / RAND_MAX;
        if (x * x + y * y < 1)
            ++circle_points;
    }
    pi = (circle_points / point_count) * 4;
    return (pi);
}

int
main(void)
{
    double point_count = 0;
    printf("Enter point count: ");
    scanf("%lf", &point_count);
    printf("Pi =  %lf \n", pi_monte_carlo(point_count));
    return (0);
}
