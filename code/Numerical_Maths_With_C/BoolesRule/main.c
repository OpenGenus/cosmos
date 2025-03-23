#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[15000],y[15000],h,sum1,sum2,sum3;
    int i,n;
    sum1=sum2=sum3=0;
    h=0.0001,n=12000,x[0]=0.0,y[0]=0;
    for(i=0;i<=n;i++)
        x[i]=x[0]+h*i;

    for(i=0;i<=n;i++)
        y[i]=exp(x[i]*x[i]*cos(x[i]));

    for(i=1;i<n;i++)
    {
        if(i%4==0) sum1+=14*y[i];
        else if(i%2==1) sum2+=32*y[i];
        else sum3+=12*y[i];

        if(i==n-4) sum1-=7*y[i];
    }

    printf("the integral value is:%9.6f\n",((2*h)/45)*(sum1+sum2+sum3));
    return 0;
}
