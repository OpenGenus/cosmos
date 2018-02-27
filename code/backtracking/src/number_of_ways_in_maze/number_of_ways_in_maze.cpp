#include<iostream>
using namespace std;


//i,j = current cell, m,n = destination

bool solveMaze(char maze[][10],int sol[][10],int i,int j,int m,int n,int &ways){

	//Base Case

	if(i==m && j==n){
		sol[m][n] = 1;
		ways++;

		//Print the solution

		for(int i=0;i<=m;i++){
			for(int j=0;j<=n;j++){
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;

		}
		cout<<endl;

		return true;
	}

	//Rec Case
	//Assume there is a way from this cell

	sol[i][j] = 1;

	//Try going Right

	if(j+1<=n && maze[i][j+1]!='X'){

		bool way_from_right = solveMaze(maze,sol,i,j+1,m,n,ways);
		if(way_from_right){

			// return true;

		}
	}

	// Try going Down if there is no way from Right

	if(i+1<=m && maze[i+1][j]!='X'){

		bool way_from_down = solveMaze(maze,sol,i+1,j,m,n,ways);
		if(way_from_down){

			//return true;

		}
	}


	//If code comes to this line - Backtrack

	sol[i][j] =0;
	return false;
}


int main(){

	char maze[10][10] = {
		"00XXX",
		"00000",
		"0XX00",
		"000X0",
		"0X000"
	};

	int m = 4,n=4;

	int sol[10][10] = {0};
	int ways=0;
	solveMaze(maze,sol,0,0,m,n,ways);
	if(ways!=0)
	{
		cout<<"Total ways "<< ways <<endl;
	}
	else
	{
		cout<<"There is no way found\n";
	}



	return 0;
}
