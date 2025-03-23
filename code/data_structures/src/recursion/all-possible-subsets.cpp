//Question:- You are given an array. Print all the possible subsets of the array (power set)

#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int> &arr, vector<vector<int>> &ans, vector<int> output, int index, int n){
    //base case
    if(index >= n){
        ans.push_back(output);
        return;
    }

    //recursive call
    //exclude
    subsets(arr, ans, output, index+1, n);

    //include
    int elm = arr[index];
    output.push_back(elm);
    subsets(arr, ans, output, index+1, n);
}

void print(vector<vector<int>> &ans){
    for(int i = 0; i<ans.size(); i++){
        cout<<"[";
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<",";
        }
        cout<<"], ";
    }
    cout<<endl;
}

int main(){
    int n;  cin>>n;
    vector<int> arr(n);
    for(int i= 0; i<n; i++)
        cin>>arr[i];

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    subsets(arr, ans, output, index, n);
    print(ans);
 return 0;
}