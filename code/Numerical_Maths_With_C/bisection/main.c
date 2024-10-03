//to find root of a given equation
//Bisection Method
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float a)
{
    float h;
    h=pow(a,3)-8*pow(a,2)+7*a-10;
    return h;
}

int main()
{
    float x0,x1,x2,p,q,r,error=0.0001;
    int i=0;
    a15:printf("Enter values of x0 and x1\n");
    scanf(" %f%f",&x0,&x1);

    if(f(x0)*f(x1)>0)
       {
           printf("Wrong values entered.ENTER Again\n");
           goto a15;
       }
    else
        printf("The root lies between %f and %f ",x0,x1);
    printf("\ni\t x0\t\tx1\t\t x2\t\tf(x0)\t\tf(x1)\t\tf(x2)\n");

    b15: x2=(x0+x1)/2;
    p=f(x0),q=f(x1),r=f(x2);
    i++;

    printf("%d\t %f\t %f\t %f\t %f\t %f\t %f\n",i,x0,x1,x2,p,q,r);

    if(f(x0)*f(x2)<0) x1=x2;
    else x0=x2;

    if(fabs((x1-x0)/x1)<=error)
    {
      printf("The root of the equation is :%6.4f",x2);
      getch();
      exit(0);
    }
    else
    goto b15;


    return 0;
}
