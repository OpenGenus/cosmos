#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x[60],y[60],z[60][60],A[60],h,k,G,sum1,sum2,sum3,sum4,sum5,sum6;
    int i,j,n;
    n=60,x[0]=2,y[0]=1,k=0.03,h=0.02;
    sum1=sum2=sum3=sum4=sum5=sum6=0;


    for(i=1;i<n;i++)
        x[i]=x[0]+i*h;

    for(i=1;i<n;i++)
        y[i]=y[0]+i*k;

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        z[i][j]=1/(x[i]+y[j]);
        //z[i][j]=2*x[i]*y[j]/(1+x[i])

    for(j=0;j<n;j++)
    {
    sum1=sum2=0;
    for(i=1;i<n-1;i++)
    {
        if(i%2==0)
        sum1+=z[j][i]*2;
        else
        sum2+=z[j][i]*4;
    }
    A[j]=(k/3)*(sum1+sum2+z[j][0]+z[j][n-1]);
    printf("%9.6f\n",A[j]);
    }


    for(i=1;i<n;i++)
    {
        if(i%6==0) sum3+=A[i]*2;
        else if(i%3==0) sum4+=A[i]*6;
        else if(i%2==0) sum5+=A[i];
        else sum6+=A[i]*5;
    }

    G=((3*h)/10)*(y[0]+sum3+sum4+sum5+sum6);
    printf("\nResult\n%9.6f\n",G);


    return 0;
}
