#include <bits/stdc++.h>
using namespace std;

string removedupstar(string &p){
    vector<int>ans;
    for(int i=0;i<p.size();){
        ans.push_back(p[i]);
        if(p[i]=='*')
        {   
            i++;
            while(i<p.size() && p[i]=='*')
                i++;
        }
        else{
            i++;
        }
    
    }
    string finans(ans.begin(),ans.end());
    return finans;
}

int find(string &s,string &p,vector<vector<int> >&dp,int i,int j,int m,int n){
    if(i==m &&j==n){
        return true;
    }
    if(i==m){
        if(j+1==n && p[j]=='*')
            return true;
        else
            return false;
    }
    if(j==n){
        return false;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=0;
    if(s[i]==p[j]){
        dp[i][j]=find(s,p,dp,i+1,j+1,m,n);
    }
    else{
        if(p[j]=='*')
            dp[i][j]=find(s,p,dp,i+1,j+1,m,n)||find(s,p,dp,i+1,j,m,n)||find(s,p,dp,i,j+1,m,n);
        else if(p[j]=='?')
            dp[i][j]=find(s,p,dp,i+1,j+1,m,n);
    }
    return dp[i][j];
}

bool isMatch(string s, string p) {
    p=removedupstar(p);
    if(s=="" && p.size()==1 && p[0]=='*')
        return true;
    if(s==p)
        return true;
    vector<vector<int> >dp(s.length(),vector<int>(p.length(),-1));
    return find(s,p,dp,0,0,s.length(),p.length())==0?false:true;
}

int main(){
    cout<<isMatch("adceb","*a*b");
}