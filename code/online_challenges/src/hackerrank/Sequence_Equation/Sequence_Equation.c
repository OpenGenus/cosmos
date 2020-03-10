#include <stdio.h>
int main()
{
    int n,x,i,y;
    scanf("%d",&n);
    int p[n];
    for(i=1;i<=n;i++)
    {
    scanf("%d",&p[i]);
    }
    for(x=1;x<=n;x++)
    {
        for(y=1;y<=n;y++)
    
    {
        if((p[p[y]])==x)
        {
            printf("%d\n",y);
        }
    }}
    return 0;
}
