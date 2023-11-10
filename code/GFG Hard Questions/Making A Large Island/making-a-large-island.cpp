//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
public:
    int fun(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &grid,vector<vector<int>> &values,vector<vector<pair<int,int>>> &parent,int x,int y){
        if(i<0||j<0||i>=grid.size()||j>=grid.size()||visited[i][j]==true||grid[i][j]==0) return 0;
        visited[i][j]=true;
        int ans=0;
        for(auto &dir: directions){
            ans+=fun(i+dir[0],j+dir[1],visited,grid,values,parent,x,y);
        }
        parent[i][j]={x,y};
        return ans+1;
    }
    void fun2(int i,int j,vector<vector<bool>> &visited,vector<vector<int>> &grid,vector<vector<int>> &values,int &val){
        if(i<0||j<0||i>=grid.size()||j>=grid.size()||visited[i][j]==true||grid[i][j]==0) return ;
        visited[i][j]=true;
        values[i][j]=val;
        for(auto &dir: directions){
            fun2(i+dir[0],j+dir[1],visited,grid,values,val);
        }
        return ;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool> (n,false));
        vector<vector<int>> values(n,vector<int> (n,0));
        vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>> (n,{-1,-1}));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]!=true){
                    values[i][j]=fun(i,j,visited,grid,values,parent,i,j);
                    parent[i][j]={i,j};
                    ans=max(ans,values[i][j]);
                }
            }
        }
        
        visited.assign(n,vector<bool> (n,false));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]!=true){
                   fun2(i,j,visited,grid,values,values[i][j]); 
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                   int a=0,b=0,c=0,d=0;
                   if(i+1<n){
                       a=values[i+1][j];
                   }
                   if(j+1<n&&(i+1>=n||parent[i][j+1]!=parent[i+1][j])){
                       b=values[i][j+1];
                   }
                   if(i-1>=0&&(i+1>=n||parent[i-1][j]!=parent[i+1][j])&&(j+1>=n||parent[i-1][j]!=parent[i][j+1])){
                       c=values[i-1][j];
                   }
                   if(j-1>=0&&(i+1>=n||parent[i][j-1]!=parent[i+1][j])&&(j+1>=n||parent[i][j-1]!=parent[i][j+1])&&(i-1<0||parent[i][j-1]!=parent[i-1][j])){
                       d=values[i][j-1];
                   }
                   ans=max(ans,a+b+c+d+1);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends