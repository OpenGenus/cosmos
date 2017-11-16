/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int T,N,F[200],m,temp,i,j,x;
  cin >> T;
  while(T--)
  {
    cin >> N;
    F[0]=1;
    m=1;
    for (i=2;i<=N;++i)
    {
      temp=0;
      for (j=0;j<m;++j)
      {
        x=F[j]*i+temp;
        F[j]=x%10;
        temp=x/10;
      }
      while(temp)
      {
        F[m++]=temp%10;
        temp/=10;
      }
    }
      long ans=0;
    for (i=m-1;i>=0;--i)
    ans+=F[i];
    cout<<ans<<endl;
  }
  return 0;
}