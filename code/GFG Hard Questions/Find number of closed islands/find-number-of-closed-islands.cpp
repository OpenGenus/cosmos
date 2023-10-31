//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    void dfs(vector<vector<bool> > & visited,int i,int j,int &N,int &M,vector<vector<int>>& matrix){
       if((i==N||j==M)||(i<0||j<0)){
           return;
       }
       if(visited[i][j]==true||matrix[i][j]==0){
           return ;
       }
       visited[i][j]=true;
       dfs(visited,i+1,j,N,M,matrix);
       dfs(visited,i-1,j,N,M,matrix);
       dfs(visited,i,j+1,N,M,matrix);
       dfs(visited,i,j-1,N,M,matrix);
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<bool>> visited(N,vector<bool> (M,false));
        for(int i=0;i<M;i++){
            if(matrix[0][i]==1&&visited[0][i]==false){
                 dfs(visited,0,i,N,M,matrix);
            }
        }
        for(int i=1;i<N;i++){
            if(matrix[i][0]==1&&visited[i][0]==false){
                 dfs(visited,i,0,N,M,matrix);
            }
        }
        for(int i=0;i<M;i++){
            if(matrix[N-1][i]==1&&visited[N-1][i]==false){
              dfs(visited,N-1,i,N,M,matrix);
            }
        }
        for(int i=1;i<N;i++){
            if(matrix[i][M-1]==1&&visited[i][M-1]==false){
                 dfs(visited,i,M-1,N,M,matrix);
            }
        }
        int count=0;
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(matrix[i][j]==1&&visited[i][j]==false){
                   dfs(visited,i,j,N,M,matrix);
                   count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends