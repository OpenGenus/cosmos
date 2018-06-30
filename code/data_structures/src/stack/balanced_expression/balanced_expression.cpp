#include <iostream>
#include <stack>

using namespace std;

inline bool isOpen(char c)
{
    if(c == '(' || c == '{' || c == '[')
        return true;
    return false;
}

bool isBalanced(char popped, char now)
{
    if(popped == '(' && now ==')')
        return true;
    if(popped == '[' && now ==']')
        return true;
    if(popped == '{' && now =='}')
        return true;
    return false;
}

int main()
{
    /* The code takes a string str as input from stdin and prints "YES" 
    if str is a balanced expression else it prints "NO".*/
    stack<char> s;
    string str;
    cin >> str;
    int no = 0;
    for(int i = 0; i < str.length(); i++)
    {
        char now = str[i];
        if(isOpen(now))
            s.push(now);
        else
        {
            char popped;
            if(s.size() > 0)
            {
                popped = s.top();
                s.pop();
            }
            else
            {
                no = 1;
                break;
            }
            if(isBalanced(popped, now))
                continue;
            else
            {
                no = 1;
                break;
            }
        }
    }
    if(!s.empty())
        no = 1;
    if(no)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
    }
return 0;
}
