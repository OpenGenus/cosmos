/*Question:- 
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
1 - 
2 - abc
3 - def
4 - ghi
5 - jkl
6 - mno
7 - pqrs
8 - tuv
9 - wxyz
0 -
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string &str, vector<string> &ans, string output, string mapping[], int n, int index){
    //base case
    if(index>=n){
        ans.push_back(output);
        return;
    }

    //to get the number because we are taking no as a string so we have to get the integer value from string
    int num = str[index]-'0';
    string value = mapping[num];

    for(int i = 0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(str, ans, output, mapping, n, index+1);
        output.pop_back();
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

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string output = "";
    int n = str.length();
    int index = 0;

    solve(str, ans, output, mapping, n, index);
    print(ans);
 return 0;
}