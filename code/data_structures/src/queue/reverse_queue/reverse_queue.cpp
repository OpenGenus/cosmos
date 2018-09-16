#include <iostream>
#include <stack>
#include <queue>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
void print(queue<int> q)
{

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    stack<int> s;

    //build the queue
    for (int i = 0; i <= 5; i++)
        q.push(i);

    //print the queue
    print(q);

    //empty the queue into stack
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    //empty stack into queue
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    //print the reversed queue
    print(q);

    return 0;
}
