#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

bool isOpen(char c)
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
    int t;
    cin>>t;
    while(t--)
    {
        stack<char> s;
        string str;
        cin>>str;
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
        if(s.size() != 0)
            no = 1;
        if(no)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
    }
    return 0;
}
