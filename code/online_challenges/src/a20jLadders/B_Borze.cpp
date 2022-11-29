#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    char arr[200];
    strcpy(arr, s.c_str());
    for(int i=0;i<len;i++){
        if(arr[i]=='.'){
            cout << 0;
        }else if(arr[i]=='-'){
            if(arr[i+1]=='-'){
                cout << 2;
                i += 1;
            }else if(arr[i+1]=='.'){
                cout << 1;
                i += 1;
            }
        }
    }
}
