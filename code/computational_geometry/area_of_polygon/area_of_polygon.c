/* computational geometry | area of polygon | C
 * @Author: Ayush Garg 
 * @Date: 2017-10-13 01:20:26 
 * @Last Modified by: Ayush Garg
 * @Last Modified time: 2017-10-13 01:31:03
 * Part of Cosmos by OpenGenus Foundation
 */

#include <stdio.h>

typedef struct
{
    double x, y;
} point;

double calcArea(point a, point b, point c)
{
    double tmp = ((a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x)) / 2;
    return (tmp < 0) ? (-tmp) : tmp;
}

int main()
{
    double ans = 0;
    int n;
    printf("Enter number of vertices \n");
    scanf("%d", &n);
    point points[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for (int i = 2; i < n; i++)
    {
        ans += calcArea(points[0], points[i - 1], points[i]);
    }

    printf("\n Answer is: %lf\n", ans);
}
