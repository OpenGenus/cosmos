//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool isHappy(int n,unordered_map<int,int> &m) {
        if(n==1) 
        return true;
        if(m[n]==0){
            int sum=0;
            m[n]++;
            while(n>0){
                sum+=(n%10)*(n%10);
                n=n/10;
            }
            return isHappy(sum,m);
        }
        return false;
    }
    int nextHappy(int N){
        int n=INT_MAX;
        for(int i=N+1;i<n;i++){
           unordered_map<int,int> m;
           if(isHappy(i,m)){
               return i;
           }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends