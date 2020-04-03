#include <stdio.h>

int main(void) 
{
    int t;
    scanf("%d", & t);
    int i, k = 0;
    for (i = 0; i < t; i++) 
    {
        int x1, x2, x3, y1, y2, y3;
        scanf("%d%d%d%d%d%d", & x1, & y1, & x2, & y2, & x3, & y3);
        float a = pow(x1 - x2, 2) + pow(y1 - y2, 2);
        float b = pow(x2 - x3, 2) + pow(y2 - y3, 2);
        float c = pow(x3 - x1, 2) + pow(y3 - y1, 2);
        if (a + b == c || b + c == a || c + a == b)
            k++;
    }
    printf("%d", k);
    return 0;
}
