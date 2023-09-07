#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    int t;
    scanf("%d", & t);
    while (t--) 
    {
        double l, d, s, c;
        scanf("%lf %lf %lf %lf", & l, & d, & s, & c);
        double likes = s * pow((1 + c), (d - 1));
        if (likes >= l) 
        {
            printf("ALIVE AND KICKING\n");
        } 
        else 
        {
            printf("DEAD AND ROTTING\n");
        }
    }
    return 0;
}
