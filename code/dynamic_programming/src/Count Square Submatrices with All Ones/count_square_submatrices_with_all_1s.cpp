#include<bits/stdc++.h>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
        int result = 0;
        
        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(i > 0 && j > 0 && matrix[i][j]>0)
                    matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i][j-1])) + 1;
                
                result += matrix[i][j];
            }
        }
        
        return result;
    }

int main(){
	int row ,col;
    cin>>row>>col;
	vector<vector<int>> mat( row , vector<int> (col, 0));
	for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin>>mat[i][j];
        }    
        
    }
    cout<<countSquares(mat);

	
}

/*
in:
3 4
0 1 1 1
1 1 1 1
0 1 1 1

out:
15
*/

//contributed by Sourav Naskar
