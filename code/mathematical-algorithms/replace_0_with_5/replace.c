// Part of Cosmos by OpenGenus Foundation
#include<stdio.h>

int convert0To5Rec(int num)
{

    if (num == 0)
        return 0;


    int digit = num % 10;
    if (digit == 0)
        digit = 5;


    return convert0To5Rec(num/10) * 10 + digit;
}


int convert0To5(int num)
{
    if (num == 0)
        return 5;
    else
        return convert0To5Rec(num);
}


int main()
{
    int num = 10120;
    printf("%d", convert0To5(num));
    return 0;
}
