//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int M=1e9+7;
class Solution {
  public:
  vector<vector<long long > > mat_mul(vector<vector<long long > >m1,vector<vector<long long > > m2)
{
    vector<vector<long long > >m3{{0,0},{0,0}};
    for(long long  i=0;i<2;i++)
    {
        for(long long  j=0;j<2;j++)
        {
            long long  sum=0;
            for(long long  k=0;k<2;k++)
            {
                sum=((m1[i][k]*m2[k][j])%M+sum)%M;
            }
            m3[i][j]=sum%M;
        }
    }
    return m3;
}
vector<vector<long long >> mat_opti(vector<vector<long long >> mat,long long  n)
{
    if(n==1) return mat;
    vector<vector<long long >>  temp=mat_opti(mat,n/2);
    if(n%2==0) return mat_mul(temp,temp);
    else return mat_mul(mat_mul(temp,temp),mat);
}
long long  fib(long long  n)
{
    if(n==0) return 1;
    if(n==1) return 1;
    vector<vector<long long >> v=mat_opti({{1,1},{1,0}},n-1);
    return v[0][0]%M;
}

    int countStrings(long long int N) {
        return fib(N+2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int N;
        cin >> N;
        Solution obj;
        cout << obj.countStrings(N) << endl;
    }
}
// } Driver Code Ends