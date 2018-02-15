/* Part of Cosmos by OpenGenus Foundation */
#include<iostream>
using namespace std;

void spiralPrint(int a[][100],int m,int n){
    int startRow=0,endCol = n-1;
    int startCol =0, endRow = m-1;

    while(startRow<=endRow && startCol<=endCol){

        ///Print the start row
        for(int i=startCol;i<=endCol;i++){
            cout<<a[startRow][i]<<" ";
        }
        startRow++;

        ///Print the end col
        for(int i=startRow;i<=endRow;i++){
            cout<<a[i][endCol]<<" ";
        }
        endCol--;

        ///Print the end row
        if(endRow>startRow){
        for(int i=endCol;i>=startCol;i--){
            cout<<a[endRow][i]<<" ";
        }
        endRow--;
        }



        ///Print the start col
        if(startCol<endCol){
        for(int i=endRow;i>=startRow;i--){
            cout<<a[i][startCol]<<" ";
        }
        startCol++;
        }
    }


}

int main(){
     int m,n; ///Dimensions of 2D array
    
    cout << "Input the Dimensions of the 2-D array" << endl;
    cin >> m >> n;
    int a[m][n];
    // Take the array as input from the users
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    spiralPrint(a,m,n);





return 0;
}
