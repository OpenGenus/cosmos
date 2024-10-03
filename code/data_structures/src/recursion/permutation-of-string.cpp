//Question:- You are give an array. Print all the permutation of the array

#include<bits/stdc++.h>
using namespace std;

void solve(string &str, vector<string> &ans, int index, int n){
    //base case
    if(index>=n){
        ans.push_back(str);
        return;
    }

    //recursive call
    for(int i = index; i<n; i++){
        swap(str[i], str[index]);
        solve(str, ans, index+1, n);
        //backtrack;
        swap(str[i], str[index]);
    }
}

//to print the output
void print(vector<string> &ans){
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<", ";
    }
    cout<<endl;
}

int main(){
    string str; cin>>str;
    int n = str.length();

    vector<string> ans;
    int index = 0;

    solve(str, ans, index, n);
    print(ans);

 return 0;
}