#include <iostream>
using namespace std;

class DequeEmptyException
{
public:
    DequeEmptyException()
    {
        cout << "Deque empty" << endl;
    }
};

// Each node in a doubly linked list
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
};

class Deque
{
private:
    Node* front;
    Node* rear;
    int count;

public:
    Deque()
    {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    void InsertFront(int element)
    {
        // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = rear = tmp;
        }
        else {
            // Prepend to the list and fix links
            tmp->next = front;
            front->prev = tmp;
            front = tmp;
        }

        count++;
    }

    int RemoveFront()
    {
        if ( isEmpty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the front node
        int ret = front->data;

        // Delete the front node and fix the links
        Node* tmp = front;
        if ( front->next != NULL )
        {
            front = front->next;
            front->prev = NULL;
        }
        else
        {
            front = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }

    void InsertBack(int element)
    {
        // Create a new node
        Node* tmp = new Node();
        tmp->data = element;
        tmp->next = NULL;
        tmp->prev = NULL;

        if ( isEmpty() ) {
            // Add the first element
            front = rear = tmp;
        }
        else {
            // Append to the list and fix links
            rear->next = tmp;
            tmp->prev = rear;
            rear = tmp;
        }

        count++;
    }

    int RemoveBack()
    {
        if ( isEmpty() ) {
            throw new DequeEmptyException();
        }

        //  Data in the rear node
        int ret = rear->data;

        // Delete the front node and fix the links
        Node* tmp = rear;
        if ( rear->prev != NULL )
        {
            rear = rear->prev;
            rear->next = NULL;
        }
        else
        {
            rear = NULL;
        }
        count--;
        delete tmp;

        return ret;
    }

    int Front()
    {
        if ( isEmpty() )
            throw new DequeEmptyException();

        return front->data;
    }

    int Back()
    {
        if ( isEmpty() )
            throw new DequeEmptyException();

        return rear->data;
    }

    int Size()
    {
        return count;
    }

    bool isEmpty()
    {
        return count == 0 ? true : false;
    }
};

int main()
{
    // Stack behavior using a general dequeue
    Deque q;
    try {
        if ( q.isEmpty() )
        {
            cout << "Deque is empty" << endl;
        }

        // Push elements
        q.InsertBack(100);
        q.InsertBack(200);
        q.InsertBack(300);

        // Size of queue
        cout << "Size of dequeue = " << q.Size() << endl;

        // Pop elements
        cout << q.RemoveBack() << endl;
        cout << q.RemoveBack() << endl;
        cout << q.RemoveBack() << endl;
    }
    catch (...) {
        cout << "Some exception occured" << endl;
    }

    // Queue behavior using a general dequeue
    Deque q1;
    try {
        if ( q1.isEmpty() )
        {
            cout << "Deque is empty" << endl;
        }

        // Push elements
        q1.InsertBack(100);
        q1.InsertBack(200);
        q1.InsertBack(300);

        // Size of queue
        cout << "Size of dequeue = " << q1.Size() << endl;

        // Pop elements
        cout << q1.RemoveFront() << endl;
        cout << q1.RemoveFront() << endl;
        cout << q1.RemoveFront() << endl;
    }
    catch (...) {
        cout << "Some exception occured" << endl;
    }
}
