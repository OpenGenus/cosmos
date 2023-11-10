//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
        int n=s.size();
         vector<vector<bool>> dp(n,vector<bool> (n,false));
    for(int i=0;i<n;i++){
        int r=0,c=i;
        while(r<n&&c<n){
            if(i==0){
                dp[r][c]=true;
            }
            else if(i==1){
                if(s[r]==s[c]){
                    dp[r][c]=true;
                }
            }
            else{
                if(s[r]==s[c]){
                    dp[r][c]=dp[r+1][c-1];
                }
            }
            r++;
            c++;
        }
    }
    unordered_map<string,int> m;
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(dp[i][j]){
                string temp=s.substr(i,j+1-i);
                m[temp]++;
            }
           
        }
    }
    return m.size();
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends