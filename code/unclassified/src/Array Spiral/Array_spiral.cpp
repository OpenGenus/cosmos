//Code for Array-Spiral Print Anticlockwise in C++
#include<iostream>
using namespace std;

   void create_array(int a[][10],int n,int m){
           for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
           }
   }

    void spiral(int a[][10],int n,int m){
        int startCol = 0,endCol = m-1,startRow = 0,endRow = n-1;

           while(startCol<=endCol && startRow<=endRow){
            for(int i=startRow;i<=endRow;i++){
                cout<<a[i][startCol]<<", ";
            }
            startCol++;

            for(int j=startCol;j<=endCol;j++){
                cout<<a[endRow][j]<<", ";
            }
            endRow--;

             if(startCol<endCol){
            for(int i=endRow;i>=startRow;i--){
                cout<<a[i][endCol]<<", ";
            }
            endCol--;
             }

           if(startRow<endRow){
            for(int j=endCol;j>=startCol;j--){
                cout<<a[startRow][j]<<", ";
            }
            startRow++;
               }
           }
           cout<<"END";

    }

 int main(){
     int n,m;
     cin>>n>>m;
     int a[10][10];
        create_array(a,n,m);
        spiral(a,n,m);

     return 0;
 }