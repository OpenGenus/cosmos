#include<iostream>
#include<cstring>
using namespace std;


int main(){
    string s;
    int upper=0;
    int lower=0;
    cin >> s;
    int len = s.size();
    char arr[len]; 
    strcpy(arr, s.c_str());

    for(int i=0;i<len;i++){
        if(isupper(arr[i])){
            upper += 1;
        }else{
            lower += 1;
        }
    }

    if(lower > upper){
        for(int i=0;i<len;i++){
            arr[i] = tolower(arr[i]);
        }
    }else if(lower < upper){
        for(int i=0;i<len;i++){
            arr[i] = toupper(arr[i]);
        }
    }else{
        for(int i=0;i<len;i++){
            arr[i] = tolower(arr[i]);
        }
    }

    for(int j=0;j<len;j++){
        cout << arr[j];
    }
}