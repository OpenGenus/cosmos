#include <stdio.h>

int power(int num, int exp)
{
    if(exp==0)
        return 1;
    else if(exp==1)
        return num;
    int result=1;
    while (exp>0){
        result *= num;
        exp--;
    }
    return result;
}

int main()
{
    	int num,exp;
    printf("Input Number\n");
    scanf("%d",&num);
    printf("Input Exponent\n");
    scanf("%d",&exp);
    printf("The result is %d\n",power(num,exp));
    }
