#include <stdio.h>

int add(int x, int y) 
{
    return printf("%*c%*c", x, '\r', y, '\r');
}

int main() 
{
    // test cases
    int i, j;
    for(i = 1; i <= 3; i++)
    {
        for(j = 1; j <= 3; j++)
        {
            printf("%d + %d = %d \n", i, j, add(i, j));
        }
    }   
}
