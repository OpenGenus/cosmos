//Question:- You are given a stirng. Print all the possible non-empty subsequences of the string

#include<bits/stdc++.h>
using namespace std;

void subsets(string &str, vector<string> &ans, string output, int index, int n){
    //base case
    if(index >= n){
        if(output.length()>0)
            ans.push_back(output);
        return;
    }

    //recursive call
    //exclude
    subsets(str, ans, output, index+1, n);

    //include
    char ch = str[index];
    output.push_back(ch);
    subsets(str, ans, output, index+1, n);
}

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
    string output;
    int index = 0;
    subsets(str, ans, output, index, n);
    print(ans);
 return 0;
}