//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    
    int M=1e9+7;
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    unordered_map<char,int> m;
	    vector<int> dp(s.size()+1,0);
	    dp[0]=1;
	    int n=s.size();
	    for(int i=1;i<=n;i++){
	        dp[i]=((dp[i-1]*1LL*2)-(m.find(s[i-1])!=m.end()?dp[m[s[i-1]]-1]:0)+M)%M;
	        m[s[i-1]]=i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends