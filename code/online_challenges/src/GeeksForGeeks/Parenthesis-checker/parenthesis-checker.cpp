#include<iostream>
#include<string>
#include<stack>
using namespace std;
//Harshita Sahai

bool areParenthesisBalanced(char opening, char closing)
{
    if(opening == '(' && closing == ')')
        return true;
    else if(opening == '{' && closing == '}')
        return true;
    else if(opening == '[' && closing == ']')
        return true;
    else
        return false;
}

bool balanced(string s)
{
    stack<char>sta;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '(' || s[i]=='{'|| s[i]=='[')
        {
            sta.push(s[i]);
        }
        else if(s[i]==')' || s[i]=='}'||s[i]==']')
        {
            if(sta.empty() || !areParenthesisBalanced(sta.top(), s[i]))
            {
                return false;
            }
            else
            {
                sta.pop();
            }
        }
    }
    return sta.empty();
}

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
	
     	string s;
     	cin >> s;
	
	    if(balanced(s))
	      cout << "balanced";
	    else
	     cout << "not balanced";
	     cout<<endl;
	}
	return 0;
}
