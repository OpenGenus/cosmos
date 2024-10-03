//program to find the given integration using weddle's rule.
//from 0 to 1.2
//h=0.1
//f(x)=exp(x*x*cosx)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float h,sum1,sum2,sum3,sum4,x[1201],y[1201],Y;
    int n,i;
    sum1=sum2=sum3=sum4=0.0;
    n=1200,x[0]=0,x[n]=1.2,h=0.001;

    for(i=1;i<=n;i++)
        x[i]=x[0]+i*h;

    for(i=1;i<=n;i++)
        {
        y[i]=exp(x[i]*x[i]*cos(x[i]));
        printf("x: %f  ||  y: %f\n",x[i],y[i]);
        }


    for(i=1;i<n;i++)
    {
        if(i%6==0)
            sum1=sum1+2*y[i];
        else if(i%3==0)
            sum2=sum2+6*y[i];
        else if(i%2==0)
            sum3=sum3+y[i];
        else
            sum4+=5*y[i];
    }

    Y=((3*h)/10)*(y[0]+sum1+sum2+sum3+sum4);

    printf("\none value of integral is %9.6f",Y);

    return 0;
}
