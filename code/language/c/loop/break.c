#include <stdio.h>
int main()
{
     int num =0;
     while(num<=100)
     {
        printf("value of variable num is: %d\n", num);
        if (num==2)
        {
            break;
        }
        num++;
     }
     printf("Out of while-loop");
     return 0;
}

/*
value of variable num is: 0
value of variable num is: 1
value of variable num is: 2
Out of while-loop
*/
