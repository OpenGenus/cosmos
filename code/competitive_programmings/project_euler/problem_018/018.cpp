/*
* Part of Cosmos Organisation
* Author: RISHAV PANDEY.
*/

#include <bits/stdc++.h>
using namespace std;
 
vector<int> A[100],M[100];
 
int maxSum(int i,int j,int N)
{
  if(M[i][j])
    return M[i][j];
  if (i==N-1)
    M[i][j]=A[i][j];
  else
    M[i][j]=A[i][j]+max(maxSum(i+1,j,N),maxSum(i+1,j+1,N));
  return M[i][j];
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int T,N,n;
     cin>>T;
     while(T--)
     {
       for(int i=0;i<100;++i)
       {
        A[i].clear();
        M[i].clear();
        for(int j=0;j<=i;++j)
          M[i].push_back(0);
       }
       cin >> N;
       for(int i=0;i<N;++i)
       {
         for(int j=0;j<=i;++j)
         {
          cin>>n;
          A[i].push_back(n);
         }
       }
       cout<<maxSum(0,0,N)<<endl;
     }
    return 0;
}