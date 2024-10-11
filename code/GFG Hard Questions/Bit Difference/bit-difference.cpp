//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int M=1e9+7;
class Solution{
public:
    int countBits(int N, long long int A[])
    {
        // code here
        vector<long long > a(64,0);
        for(int i=0;i<N;i++){
            for(int j=0;j<64;j++){
                if((A[i]>>j)&1){
                    a[j]=(a[j]+1)%M;
                }
            }
        }
        long long  count=0;
         for(int i=0;i<N;i++){
            for(int j=0;j<64;j++){
                if(((A[i]>>j)&1)==0&&a[j]!=0){
                    count=((count+a[j]))%M;
                   
                }
            }
        }
         for(int i=0;i<N;i++){
            for(int j=0;j<64;j++){
                if(((A[i]>>j)&1)==0&&a[j]!=0){
                    count=((count+a[j]))%M;
                   
                }
            }
        }
        // cout<<M<<endl;
        return (int)count;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends