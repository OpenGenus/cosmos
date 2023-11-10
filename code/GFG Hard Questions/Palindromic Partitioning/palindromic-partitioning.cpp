//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<int> dp;
public:
    bool check(string &s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
    int fun(string &s,int i){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int cut=INT_MAX;
        string temp="";
        for(int j=i;j<s.size();j++){
            temp.push_back(s[j]);
            if(check(temp)){
                cut=min(fun(s,j+1),cut);
            }
        }
        // cout<<cut<<" "<<i<<endl;
        return dp[i]=cut+1;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        dp.assign(n+1,-1);
        return fun(str,0)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends