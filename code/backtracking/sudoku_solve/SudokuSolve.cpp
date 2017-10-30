#include<iostream>
using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
*/
int n=9;

bool isPossible(int mat[][9],int i,int j,int no){
    ///Row or col should not have no
    for(int x=0;x<n;x++){
        if(mat[x][j]==no||mat[i][x]==no){
            return false;
        }
    }

    /// Subgrid should not have no
    int sx = (i/3)*3;
    int sy = (j/3)*3;

    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(mat[x][y]==no){
                return false;
            }
        }
    }

    return true;
}
void printMat(int mat[][9]){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
            if((j+1)%3==0){
                cout<<'\t';
            }

        }
         if((i+1)%3==0){
                cout<<endl;
        }
            cout<<endl;
    }
}


bool solveSudoku(int mat[][9],int i,int j,long long int &cnt){
    ///Base Case
    if(i==9){
        cnt++;
        //Print one of the solutions
        if(cnt == 1)
          printMat(mat);
        return true;
    }

    ///Crossed the last  Cell in the row
    if(j==9){
        return solveSudoku(mat,i+1,0,cnt);
    }

    ///Skip if filled cell
    if(mat[i][j]!=0){
        return solveSudoku(mat,i,j+1,cnt);
    }
    ///White Cell
    ///Try to place every possible no
    bool canSolve = false;
    for(int no=1;no<=9;no++){
        if(isPossible(mat,i,j,no)){
            ///Place the no - assuming solution is possible with this
            mat[i][j] = no;
            canSolve |= solveSudoku(mat,i,j+1,cnt);
            ///loop will place the next no.
        }
        //Backtrack to look for more solutions
        mat[i][j] = 0;
    }

    return canSolve;
}

int main(){

	int mat[9][9] =
        	{{5,3,0,0,7,0,0,0,0},
       	 	{0,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{0,0,0,0,6,0,0,0,3},
		{0,0,0,8,0,3,0,0,1},
		{0,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};
	printMat(mat);
	cout<<"Solution "<<endl;
	long long int cnt = 0;
	solveSudoku(mat,0,0,cnt);
	cout<<"There are "<<cnt<<" ways to solve this Sudoku Puzzle"<<endl;
return 0;
}
