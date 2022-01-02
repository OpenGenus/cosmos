#include<iostream>
using namespace std;
long long int fact(long long int n)
{
    long long int factorial=1;
    if(n==0||n==1)
    return 1;
    for(long long int i=1;i<=n;i++)
    {
        factorial*=i;
    }
    return factorial;
}
int main()
{
    long long int num,fact_sum=0,dup;
    cout<<"Enter The Number\n";
    cin>>num;
    dup=num;
    while(num)
    {
      fact_sum+=fact(num%10);
      num/=10;
    }
    if(fact_sum==dup)
      cout<<"Yes,It is a Krishnamurthy Number";
    else
      cout<<"No,It is Not a Krishnamurthy Number";
      return 0;
}

