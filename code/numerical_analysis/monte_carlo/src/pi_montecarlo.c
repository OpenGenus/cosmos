#include <stdio.h>
#include <stdlib.h>

/*Part of Cosmos by OpenGenus Foundation*/

double
pi_monte_carlo(double point_count)
{
    double circle_points, pi, x, y;
    circle_points = 0;
    for (int i = 0; i < point_count; ++i)
    {
        x = (double)random() / RAND_MAX;
        y = (double)random() / RAND_MAX;
        if (x * x + y * y < 1)
            circle_points++;
    }
    pi = (circle_points / point_count) * 4;
    return (pi);
}

int
main(void)
{
    double point_count, pi;
    printf("Enter point count: ");
    scanf("%lf", &point_count);
    pi = pi_monte_carlo(point_count);
    printf("Pi =  %lf \n", pi);
    return (0);
}
