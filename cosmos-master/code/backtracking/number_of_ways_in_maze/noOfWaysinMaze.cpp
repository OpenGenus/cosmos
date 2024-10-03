#include<iostream>
using namespace std;

/*
 * Part of Cosmos by OpenGenus Foundation
*/

///i,j = current cell, m,n = destination
bool solveMaze(char maze[][10],int sol[][10],int i,int j,int m,int n,int &ways){
    ///Base Case
    if(i==m && j==n){
        sol[m][n] = 1;
        ways++;
        ///Print the soln
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        return true;
    }

    ///Rec Case
    ///Assume there is a way from this cell
    sol[i][j] = 1;

    if(j+1<=n && maze[i][j+1]!='X'){
        bool right_way = solveMaze(maze,sol,i,j+1,m,n,ways);
    }
    /// Try going Down
    if(i+1<=m && maze[i+1][j]!='X'){
        bool down_way = solveMaze(maze,sol,i+1,j,m,n,ways);
    }
    ///Backtracking!
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
    if(ways){
        cout<<"Total ways "<<ways<<endl;
    }
    else{
        cout<<"No ways"<<endl;
    }
return 0;
}

