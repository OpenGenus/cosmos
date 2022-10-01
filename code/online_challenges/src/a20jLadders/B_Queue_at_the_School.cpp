#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n,sec;
    cin >> n >> sec;
    string s;
    char arr[n];
    cin >> s;
    strcpy(arr, s.c_str());

    for(int j=0;j<sec;j++){
        for(int i=0;i<n;i++){
            if(arr[i] == 'B' && arr[i+1] == 'G'){
                arr[i] = 'G';
                arr[i+1] = 'B';
                i += 2;
            }
        }
         for(int i=0;i<n;i++){
            cout << arr[i];
    }cout << "\n";
    } 
}

    

