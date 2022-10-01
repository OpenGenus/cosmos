#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.size();
    char arr[len];
    strcpy(arr, s.c_str());
    arr[0] = toupper(arr[0]);
    for(int i=0;i<len;i++){
        cout << arr[i];
    }
}
