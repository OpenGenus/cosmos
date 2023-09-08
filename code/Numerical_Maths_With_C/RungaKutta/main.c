//RungaKutta Methodbich
#include <stdio.h>
#include <stdlib.h>

float f(float x,float y)
{
    //return x+y*y;
    return x*x+y*y;
    //return (y-x)/(y+x);
}

int main()
{
    float x,y,x0,y0,h,xn,k1,k2,k3,k4,k;
    printf("Enter x0,y0,h,xn");
    scanf(" %f%f%f%f",&x0,&y0,&h,&xn);

    x=x0,y=y0;
    while(1)
    {
        if(x>=xn) break;
        else
        {
            k1=h*f(x,y);
            k2=h*f(x+h/2,y+k1/2);
            k3=h*f(x+h/2,y+k2/2);
            k4=h*f(x+h,y+k3);
            k=(k1+k4+2*(k2+k3))/6;
            x+=h;y+=k;
            printf("\nx: %f\ty: %f",x,y);
        }
    }

    printf("\nResult:\nx: %f\ty: %f\n",x,y);
    return 0;
}
