#include <iostream>
using namespace.std;
int power(int a,int b)
{
int i,p=1;
for(i=1;i<=b;i++)
{
p=p*a;
}
return p;
}
int main()
{
int x,y,pw;
cout<<"\n Enter the value of x";
cin>>x;
cout<<"\n Enter value of y";
cin>>y;
pw=power(x,y);
cout<<"\n Value of x raised to power y is"<<pw;
return 0;
}

