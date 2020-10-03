#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        int p, s;
        scanf("%d%d", & p, & s);
        double x1 = (p + sqrt(p * p - (24 * s))) / 12;
        double x2 = (p - sqrt(p * p - (24 * s))) / 12;
        double y1 = (p - (8 * x1)) / 4;
        double y2 = (p - (8 * x2)) / 4;
        double v1 = x1 * x1 * y1;
        double v2 = x2 * x2 * y2;
        printf("%.2f\n", (v1 > v2) ? v1 : v2);
    }
    return 0;
}
