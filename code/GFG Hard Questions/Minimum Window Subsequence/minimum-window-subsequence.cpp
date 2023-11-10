//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isSubsequence(int i,int j,int n,int m,string &a,string &b,int &last){
        while(i<n&&j<m){
            if(a[i]==b[j]){
                i++;j++;
            }
            else
            i++;
        }
        last=i-1;
        if(j==m) return true;
        return false;
    }
    string minWindow(string str1, string str2) {
        // Write your Code here
        int mini=INT_MAX;
        int x,y;
        for(int i=0;i<str1.size();i++){
            int last=0;
            if(isSubsequence(i,0,str1.size(),str2.size(),str1,str2,last)==true){
                if(last-i+1<mini){
                    x=i;
                    y=last;
                    mini=min(mini,last-i+1);
                }
            }
        }
        if(mini==INT_MAX) return "";
        return str1.substr(x,y-x+1);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends