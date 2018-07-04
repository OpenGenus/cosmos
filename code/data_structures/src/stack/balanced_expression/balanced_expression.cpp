#include <iostream>
#include <stack>

inline bool isOpen(char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool isBalanced(char popped, char now)
{
    return (popped == '(' && now ==')') ||
    (popped == '[' && now ==']') ||
    (popped == '{' && now =='}');
}

int main()
{
    /* The code takes a string str as input from stdin and prints "YES" 
    if str is a balanced expression else it prints "NO".*/
    std::stack<char> s;
    std::string str;
    std::cin >> str;
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
        std::cout<<"NO\n";
    else
        std::cout<<"YES\n";
return 0;
}
