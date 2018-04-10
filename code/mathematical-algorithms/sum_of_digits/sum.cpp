#include<iostream>
using namespace std;
int main()
{
 int n,rem;
 cout<<"Enter n:";
 cin>>n;
 int sum=0;
  while(n!=0)
    {
     rem=n%10;
     sum=sum+rem;
     n=n/10;
     }
  cout<<"Sum of digits is:"<<sum;
}
