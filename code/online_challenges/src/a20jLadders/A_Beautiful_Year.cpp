#include<iostream>
#include<stdlib.h>
#include<set>
using namespace std;

int main(){
    int year;
    int arr[4];
    set<int> s;
    cin >> year;
    
    year +=1;
    
    bool run = true;
    while(run){
        int temp_year = year;
        for (int i =3; i >= 0; i--) {
        arr[i] = temp_year % 10;
        temp_year /= 10;
        }
        for (int i = 0; i < 4; i++) {
            s.insert(arr[i]);
        }
        
        if(s.size() == 4){
            cout << year;
            break;
        }else{
            year +=1;
        }
    }
    
}