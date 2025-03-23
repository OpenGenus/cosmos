#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[100],y[100],A[100],z[100][100],h,k,G,sum1,sum2,sum3,sum4,sum5,sum6;
    int i,j,n;
    h=0.01,k=0.012,sum1=sum2=sum3=sum4=sum5=sum6=0;
    n=100;x[0]=1,y[0]=0;

    for(i=1;i<n;i++) x[i]=x[0]+i*k;
    for(i=1;i<n;i++) y[i]=y[0]+i*h;

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    z[i][j]=(2*x[j]*y[i])/((1+x[j]*x[j])*(1+y[i]*y[i]));

    for(i=0;i<n;i++)
    {
        sum1=sum2=0;
        for(j=1;j<n-1;j++)
        {
            if(j%2==0)
            sum1+=z[i][j]*2;
            else
            sum2+=z[i][j]*4;
        }
        A[i]=(k/3)*(sum1+sum2+z[i][0]+z[i][n-1]);
        printf("%9.6f\n",A[i]);
    }

    for(i=1;i<n;i++)
    {
        if(i%6==0) sum3+=A[i]*2;
        else if(i%3==0) sum4+=A[i]*6;
        else if(i%2==0) sum5+=A[i];
        else sum6+=A[i]*5;
    }

    G=((3*h)/10)*(sum3+sum4+sum5+sum6+A[0]);

    printf("\nResult\n%9.6f\n",G);
    return 0;
}
m
