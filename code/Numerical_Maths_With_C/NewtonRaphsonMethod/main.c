//Newton Raphson Method
//roots of x^3+1.2x^2-4x-4.8=0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    //return pow(x,3)+1.2*pow(x,2)-4*x-4.8;
    return x*log10(x)-1.2;
}

float df(float x)
{
    //return 3*pow(x,2)+2.4*x-4;
    return x+log10(x);
}

int main()
{
    float x0,x1,err,h;
    int i;
    printf("Enter the values of x,error\n");
    scanf(" %f%f",&x0,&err);

    i=1;
    while(i<1000)
    {
        h=f(x0)/df(x0);
        x1=x0-h;

        printf("%d\t%f\n",i++,x1);
        if(fabs(h)<err){printf("\n\nSOL is %f",x1);return 0;}
        else
            x0=x1;
    }
    printf("Solution does not converge");
    return 0;
}
