#include<stdio.h>
int main()
{
 int a,b=0;                                                   //variable to get number
 printf("enter a value to be reversed");
 scanf("%d",&a);
 while(a>0)
 {
  b=b*10+a%10;
  a=a/10;
 }
 printf("%d is reverse number");
 return 0;
}
