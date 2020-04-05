#include<stdio.h>

int main() 
{
    int t, n;
    scanf("%d", & t);
    while (t--) 
	{
        scanf("%d", & n);
        if (360 % n == 0)
            printf("y ");
        else
            printf("n ");
        if (n <= 360)
            printf("y ");
        else
            printf("n ");
        if (n <= 26)
            printf("y \n");
        else
            printf("n \n");
    }
}
