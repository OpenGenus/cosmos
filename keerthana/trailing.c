#include<stdio.h>

int main()
{
        int num=20, count, total = 0;
        for(count = 5; (num/count) >= 1; count = count*5)
        {
            total = total + num/count;
        }
        printf("Total Number of Trailing Zeroes:%d", total);
        printf("\n");
        return 0;
}
