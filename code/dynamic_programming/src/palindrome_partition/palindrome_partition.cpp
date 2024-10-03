// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return the minimum cuts needed for a palindrome partitioning of s.

// TC:O(N*N)
// SC:O(N*N)

BruteForce TC:O(N^N);
SC; O(N); // Call stack Space

#include<bits/stdc++.h>
    using namespace std;

    int minCut(string s) {
       
        // Finding Palindromic Substrings in the given string
        
        vector<vector<bool>>dp(s.size()+2,vector<bool>(s.size()+1,0));
        
        for(int i=1;i<=s.size();++i){
            int k=i;
            for(int j=1;k<=s.size();++j,k++){
                
                if(k-j==0||s[k-1]==s[j-1]&&k-j==1)dp[j][k]=1;
                    
            else if(s[k-1]==s[j-1]&&dp[j+1][k-1])dp[j][k]=1;
            
            }
        }

        vector<int>mincuts(s.size()+1,0); // This is the array that keeps track of how many minimum cuts  till that particular index to form palindromes
        
  
        // When we stand at a index looking backwards what are the different length of palindromes that we can get by including current character
        
        // we can get total required partitions till that index  by getting cuts required till starting of the palindrome+1 from all find minimum and store result in 
//             mincuts array
        
         //EX:abcbab if we stand at last b we look leftwards we find bab is a palindrome can be considered as 1 partition and from min cuts array we ask what are the
        //partitions till c(before b) it's 2 so if we consider bab we get 2+1 =3 partitons but if we consider b itself a palindrome cuts required till a (before b)is 0
//         so 0+1 =1 which is much more smaller we choose minimum
        
        
        for(int i=1;i<=s.size();++i){
            int ans=INT_MAX;
            for(int j=1;j<=s.size();++j)
                if(dp[j][i]){ans=min(ans,j==1?0:1+mincuts[j-1]);}
            mincuts[i]=ans;
        }
    
        return mincuts[s.size()];
    }
main(){

cout<<minCut("abcbab");//2 
}
