/*
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]  


Approach:
only add open paraenthesis if open < n
only add close parenthesis if close < open
stop- valid parenthesis if close == open == n
TC/SC - O(4^n)


*/
#include<bits/stdc++.h>
using namespace std;
vector<string> res;
       
void backtrack(int open, int close, string s,int n)
    {
            if(open == n and close == n)
            {
                res.push_back(s);
                return;
            }
            
            if(open < n)
            {
                backtrack(open+1, close, s+'(', n);
            }
            if(close < open)
            {
                backtrack(open, close+1, s +')', n);
            }
            
    }
vector<string> generateParenthesis(int n) 
{
        backtrack(0, 0, "", n);
        return res;
}

int main()
{
    vector<string> res;
    int n = 3;
    res = generateParenthesis(n);
    for(auto x : res)
    cout << x << " ";

    return 0;
}
