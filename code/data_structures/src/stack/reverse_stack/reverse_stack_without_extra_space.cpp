/*
 * Part of Cosmos by OpenGenus Foundation
 */
#include <iostream>
#include <stack>
using namespace std;
void InputElements(stack<int> &s)
{

    //no. of elements to be inserted
    int size;
    cin >> size;

    while (size--)
    {
        int num;
        cin >> num;
        s.push(num);
    }
}
void InsertInStack(stack<int> &s, int x)
{

    if (s.empty())
    {
        s.push(x);
        return;
    }

    int cur = s.top();
    s.pop();
    InsertInStack(s, x);
    s.push(cur);
}
void ReverseStack(stack<int> &s)
{

    if (s.empty())
        return;

    int cur = s.top();
    s.pop();
    ReverseStack(s);

    InsertInStack(s, cur);
}
void PrintStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main()
{
    //Stack Decalared
    stack<int> s;
    //Inserting elements in to the stack
    InputElements(s);
    //Print stack
    PrintStack(s);
    //Reverse Stack without using any extra space
    ReverseStack(s);
    //Print again
    PrintStack(s);
    return 0;
}
