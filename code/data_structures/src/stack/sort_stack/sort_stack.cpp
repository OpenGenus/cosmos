/* Part of Cosmos by OpenGenus Foundation */

/* Sort a stack */

#include <iostream>
#include <stack>
using namespace std;
void InputElements(stack<int> &s)               //////////// Function to insert the elements in stack
{   //no. of elements to be inserted
    int size;
    cin >> size;

    while (size--)
    {
        int num;
        cin >> num;
        s.push(num);
    }
}
void PrintStack(stack<int> s)           //////////// Function to print the contents of stack
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
void SortedInsert(stack<int> &s, int num)  ////////// Function to insert a element at its right position in sorted way
{
    if (s.empty() || s.top() > num)
    {
        s.push(num);
        return;
    }
    int top_element = s.top();
    s.pop();
    SortedInsert(s, num);
    s.push(top_element);
}
void SortStack(stack<int> &s)            //////////// Function to sort the stack
{
    if (s.empty())
        return;
    int top_element = s.top();
    s.pop();
    SortStack(s);
    SortedInsert(s, top_element);
}
int main()
{
    stack<int> s;
    //Inserting elements in to the stack
    InputElements(s);
    //Print stack before sorting
    PrintStack(s);
    //Sort the stack
    SortStack(s);
    //Print stack after sorting
    PrintStack(s);
    return 0;
}
