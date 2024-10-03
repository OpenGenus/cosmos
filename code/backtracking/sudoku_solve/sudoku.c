/*
** Backtracking 
** Code for solving a 9X9 sudoku 

** Part of Cosmos by OpenGenus Foundation
*/

#include <stdio.h>
#define UND 0
#define N 9
bool findUnassignedPlaces(int arr[N][N], int &row, int &col);

bool isSafe(int arr[N][N], int row, int col, int num);

bool solveSudoku(int arr[N][N]){
	int row, col;
	if(!findUnassignedPlaces(arr, row, col)){
		return true;
	};
	int i;
	for(i=1;i<=N;i++){
		if(isSafe(arr, row, col, i)){
			arr[row][col]=i;
			if(solveSudoku(arr)){
				return true;
			}
			arr[row][col]=UND;
		}
	}
	return false;
}

bool findUnassignedPlaces(int arr[N][N], int &row,  int &col){
	for (row = 0; row < N; row++){
        for (col = 0; col < N; col++){
            if (arr[row][col] == UND){
                return true;
            }
        }
	}
    return false;
}
  bool usedInRow(int arr[N][N], int row, int num){
  	int col;
  	for(col=0;col<N;col++){
  		if(arr[row][col]==num){
  			return true;
  		}
  	}
 return false; 
 }

bool usedInCol(int arr[N][N], int col, int num){
	int row;
	for(row=0;row<N;row++){
		if(arr[row][col]==num){
			return true;
		}
	}
return false;
}

bool UsedInBox(int arr[N][N], int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 3; row++){
        for (int col = 0; col < 3; col++){
            if (arr[row+boxStartRow][col+boxStartCol] == num){
                return true;
            }
        }
    }
    return false;
}


bool isSafe(int arr[N][N], int row, int col, int num){
    return ((!usedInRow(arr, row, num)) && (!usedInCol(arr, col, num)) && (!UsedInBox(arr, row - row%3 , col - col%3, num)));
}
 

void printGrid(int arr[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%2d",arr[i][j]);
		}
		printf("\n");
	}
}


int main(){
	int arr[N][N];
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	if(solveSudoku(arr)==true){
		printGrid(arr);
	}
	else{
		printf("No Possible solution :P");
	}
return 0;
}