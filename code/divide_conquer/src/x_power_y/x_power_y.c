#include <stdio.h>
 
float 
power(float x, int y)
{
    if (y == 0)
       return (1);

    float temp = power(x, y / 2);

    if (y % 2 == 0)
        return (temp * temp);

    else {
        if (y > 0)
            return (x * temp * temp);
        else
            return (temp * temp / x);
    }
}  
 

int 
main()
{
    float x;
    printf("Enter x (float): ");
    scanf("%f", &x);

    int y;
    printf("Enter y (int): ");
    scanf("%d", &y);

    printf("%f^%d == %f\n", x, y, power(x, y));

    return (0);
}
