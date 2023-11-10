//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool check(int val,int i,int j,int grid[9][9]){
        for(int k=0;k<9;k++){
            if(grid[k][j]==val) return false;
        }
         for(int k=0;k<9;k++){
            if(grid[i][k]==val) return false;
        }
        if(i>=0&&i<3&&j>=0&&j<3){
            i=0;j=0;
        }
        if(i>=3&&i<6&&j>=0&&j<3){
            i=3;j=0;
        }
        if(i>=6&&i<9&&j>=0&&j<3){
            i=6;j=0;
        }
        if(i>=0&&i<3&&j>=3&&j<6){
            i=0;j=3;
        }
        if(i>=3&&i<6&&j>=3&&j<6){
            i=3;j=3;
        }
        if(i>=6&&i<9&&j>=3&&j<6){
            i=6;j=3;
        }if(i>=0&&i<3&&j>=6&&j<9){
            i=0;j=6;
        }
        if(i>=3&&i<6&&j>=6&&j<9){
            i=3;j=6;
        }
        if(i>=6&&i<9&&j>=6&&j<9){
            i=6;j=6;
        }
        for(int k=i;k<i+3;k++){
            for(int l=j;l<j+3;l++){
                if(grid[k][l]==val) return false;
            }
        }
        return true;
    }
    bool my_helper(int i,int j,int grid[9][9]){
            if(i>=9&&j>=9) return true;
            bool ans=false;
            if(j>=9){
                if(i==8){
                    return true;
                }
                ans=my_helper(i+1,0,grid);
                return ans;
            }
                if(grid[i][j]==0){
                    for(int val=1;val<=9;val++){
                    if(check(val,i,j,grid)){
                     grid[i][j]=val;
                     ans=my_helper(i,j+1,grid);
                    if(ans==true) return true;
                    }
                    }
                    grid[i][j]=0;
                }
                else{
                    ans=my_helper(i,j+1,grid);
                    if(ans==true) return true;
                }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return my_helper(0,0,grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends