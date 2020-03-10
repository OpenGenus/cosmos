#include <stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int d,count=0;
long long int n,b;
scanf("%lld",&n);
b=n;
while(b>0)
{
d=b%10;
if(d>0)
{
if(n%d==0)
{
    count++;
}}
b=b/10;
}
printf("%d\n",count);
}
return 0;
}



