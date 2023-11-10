// Part of Cosmos by OpenGenus Foundation

#include <bits/stdc++.h>
using namespace std;

bool ValidOperator(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string PostfixToPrefix(string post_exp)
{
    stack<string> s;

    int length = post_exp.size();

    for (int i = 0; i < length; i++)
    {

        if (ValidOperator(post_exp[i]))
        {

            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = post_exp[i] + op2 + op1;

            s.push(temp);
        }

        else
        {

            s.push(string(1, post_exp[i]));
        }
    }

    return s.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string post_exp = "HACKT+O*BER/-COS/MOS-*";
    cout << "Prefix : " << PostfixToPrefix(post_exp);
    return 0;
}