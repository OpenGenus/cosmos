/* Part of Cosmos by OpenGenus Foundation */

#include<stdio.h>

int main(){
    int num,f;
    printf("enter the number\n"); //an integer number
    scanf("%d",&num);

    f=factorial(num);
    printf("factorial of %d is: %d",num,f);
    return 0;
}

int factorial(int n){       //defining the recursion function
    int fact=1;
    if(n==0 || n==1)
        fact==1;
    else
        fact=n*factorial(n-1);

return fact;
}