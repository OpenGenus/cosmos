#include <stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int n,p,height=0;
scanf("%d",&n);
for(p=0;p<=n;p++)
{
    if(p%2==0)
        height=(height+1);
    else if(p%2!=0)
    height=(height*2);
}
printf("%d\n",height);

}
return 0;
}
