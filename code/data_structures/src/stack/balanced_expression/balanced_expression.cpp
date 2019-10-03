#include <iostream>
#include <stack>

bool checkBalanced(string s)
{
    if (s.length() % 2 != 0)
        return false;
    std::stack <char> st;
    for (const char: s)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            st.push(s[i]);
        else
        {
            char temp = st.top();
            if (s[i] == '}' && temp == '{')
                st.pop();
            else if (s[i] == ']' && temp == '[')
                st.pop();
            else if (s[i] == ')' && temp == '(')
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    std::string s;
    std::cin >> s;
    bool res = checkBalanced(s);
    if (res)
        std::cout << "Expression is balanced";
    else
        std::cout << "Expression is not balanced";
}
