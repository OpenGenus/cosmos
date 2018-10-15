#include <iostream>
#include <stack>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
// queue data structure using two stacks
class queue {
private:
    stack<int> s1, s2;
public:
    void enqueue(int element);
    int dequeue();
    void displayQueue();
};

// enqueue an element to the queue
void queue :: enqueue(int element)
{
    s1.push(element);
}

// dequeue the front element
int queue :: dequeue()
{
    // transfer all elements of s1 into s2
    if (s1.empty() && s2.empty())
        return 0;

    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    // pop and store the top element from s2

    int ret = s2.top();
    s2.pop();
    // transfer all elements of s2 back to s1
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return ret;
}

//display the elements of the queue
void queue :: displayQueue()
{
    cout << "\nDisplaying the queue :-\n";
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s1.push(s2.top());
        s2.pop();
    }
}

// main
int main()
{
    queue q;
    int exit = 0;
    int enqueue;
    char input;
    while (!exit)
    {
        cout << "Enter e to enqueue,d to dequeue,s to display queue,x to exit: ";
        cin >> input;
        if (input == 'e')
        {
            cout << "Enter number to enqueue: ";
            cin >> enqueue;
            q.enqueue(enqueue);
        }

        if (input == 'd')
            q.dequeue();

        if (input == 's')
        {
            q.displayQueue();
            cout << endl;
        }
        if (input == 'x')
            break;
    }

    return 0;
}
