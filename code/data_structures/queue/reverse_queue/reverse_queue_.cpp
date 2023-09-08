// CPP program to reverse a Queue
#include <bits/stdc++.h>
using namespace std;
 
// Utility function to print the queue
void Print(queue<int>& Queue)
{
    int temp;
    queue<int> Queue2;
    while (!Queue.empty()) {
        temp = Queue.front();
        cout << Queue.front() << " ";
        Queue.pop();
        Queue2.push(temp);
    }
    while (!Queue2.empty()) {
        Queue.push(Queue2.front());
        Queue2.pop();
    }
}
 
// Function to reverse the queue
void reverseQueue(queue<int>& Queue)
{
    stack<int> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}
 
// Driver code
int main()
{
    queue<int> Queue;
    int exit = 0;
    int input;
    char entry;
    while(!exit)
    {
        cout<<"Enter p to push into queue,r to reverse the queue,s to show the queue,x to exit: ";
        cin>>entry;
        if(entry == 'p')
        {
            cout<< "Enter number to push: ";
            cin>>input;
            Queue.push(input);
        }
        if(entry=='r')
            reverseQueue(Queue);
        
        if(entry=='s')
        {
            Print(Queue);
            cout<<endl;
        }
        if(entry=='x')
            exit=1;
    }
    
    return 0;
}
