//Question:- You are give an array. Print all the permutation of the array

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<vector<int>> &ans, int index, int n){
    //base case
    if(index>=n){
        ans.push_back(arr);
        return;
    }

    //recursive call
    for(int i = index; i<n; i++){
        swap(arr[i], arr[index]);
        solve(arr, ans, index+1, n);
        //backtrack;
        swap(arr[i], arr[index]);
    }
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
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    vector<vector<int>> ans;
    int index = 0;

    solve(arr, ans, index, n);
    print(ans);

 return 0;
}