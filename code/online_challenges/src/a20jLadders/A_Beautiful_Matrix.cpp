#include<iostream>
using namespace std;

int main(){
    int arr[5];
    int row,col,move1,move2;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> arr[j];
            if(arr[j] == 1){
                row = i+1;
                col = j+1;
            } 
        }
    }  
    if(row > 3){
        move1 = row - 3;
    }else if( row == 3){
        move1 = 0;
    }else{
        move1 = 3 - row;
    }

    if(col > 3){
        move2 = col - 3;
    }else if(col == 3){
        move2 = 0;
    }else{
        move2 = 3 - col;
    }

    cout << move1 + move2;
}

