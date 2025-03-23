#include <stdio.h>
#include <stdlib.h>

int main()
{
    float sum1,sum2,x[1201],y[1201],h;
    int i,n;
    sum1=sum2=0;x[0]=0,y[0]=0;
    h=0.001,n=1200;

    for(i=0;i<n;i++)
        x[i]=x[0]+i*h;

    for(i=0;i<n;i++)
        y[i]=exp(x[i]*x[i]*cos(x[i]));

    for(i=0;i<n;i++)
    {
        if(i%3==0) sum1+=y[i]*2;
        else sum2+=y[i]*3;
    }

    printf("%9.6f",(3*h/8)*(sum1+sum2));

    return 0;
}
