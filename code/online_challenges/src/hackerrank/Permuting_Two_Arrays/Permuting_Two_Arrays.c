#include <stdio.h>
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,i,j,temp,ma,c=0,f;
        long int k;
        scanf("%d %ld",&n,&k);
        long int a[n],b[n];
        for(i=0;i<n;i++)
        {
            scanf("%ld",&a[i]);
        }
         for(i=0;i<n;i++)
         {
             scanf("%ld",&b[i]);
         }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(b[i]<b[j])
                {
                    ma=b[j];
                    b[j]=b[i];
                    b[i]=ma;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if((a[i]+b[i])>=k)
            {   f=0;
               c=c+1; 
            }
            else if((a[i]+b[i])<k)
            {
               f=1;
               printf("NO\n");
               break;
            }
        }
        if(f==0&&c==n)
        {
            printf("YES\n");
        }
    }
    return 0;
}
