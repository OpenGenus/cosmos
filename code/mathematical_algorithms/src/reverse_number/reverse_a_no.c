#include<stdio.h>
int main()
{
int n,rev=0,a;
printf("Enter a number");
scanf("%d",&n);
while(n>0)
{
a=n%10;
rev=(rev*10)+a;
n=n/10;
}
printf("\nReverse number is  %d",rev);
return 0;
}

