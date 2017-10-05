#include <bits/stdc++.h>
using namespace std;
int main(){
int a=1;
int b=1;

int n;
cout<<"Enter no. of elements of the series to be printed ";
cin>>n;
cout<<a<<endl;
cout<<b<<endl;
int c;
while (n>2)
{
c=a+b;
cout<<c<<endl;
a=b;
b=c;
n--;
}
return 0;
}