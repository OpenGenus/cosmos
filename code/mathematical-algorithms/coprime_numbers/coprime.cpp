#include<iostream>
using namespace std;
int main()
{
  int a,b,k=0,m=0;
  cout<<"enter numbers to be checked";
  cin>>a>>b;     //initialize two input
  for(int i=2;i<=(a>b?a:b)/2;i++)   //(a>b?a:b) is used to find largest of 2 by using ternary operator
  {
     if(a%i==0)
     k=1;
     if(b%i==0)
     m=1;
   }
  if(k==0 && m==0 && a==b+1 || b==a+1)
   cout<<"coprime numbers"<< (a>b?a:b)<<" "<<(a<b?a:b);
  else
   cout<<"not coprime";
}
