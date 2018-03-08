// Part of cosmos from opengenus foundation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    vector<int> arr;
    cout<<"enter number of numbers : ";
    cin>>n;
    for(int i = 0 ; i < n ; i++) {
        int a;
        cin>>a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    cout<<"biggest number : "<<arr[n-1];

    return 0;
}   