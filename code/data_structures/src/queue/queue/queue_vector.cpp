#include <iostream>
#include <vector>

using namespace std;
// Part of Cosmos by OpenGenus Foundation
class Queue
{
private:
// Vector for storing all of the values
    vector<int> _vec;

public:
    void enqueue(int & p_put_obj); // Puts object at the end of the queue
    void dequeue(int & p_ret_obj); // Returns object at the start of the queue and removes from queue
    void peek(int & p_peek_obj);  // Returns object at the start of the queue but doesn't remove it
    bool is_empty();              // Checks if the queue is full
};

// Purpose: Put a value onto the end of the queue
// Params : p_put_obj - reference to the object you want to enqueue
void Queue::enqueue(int & p_put_obj)
{
    // Use the inbuild push_back vector method
    _vec.push_back(p_put_obj);
}

// Purpose: Gets the value from the front of the queue
// Params : p_ret_obj - Reference to an empty object to be overwritten by whatever is dequeued
void Queue::dequeue(int & p_ret_obj)
{
    // Set the value to what's in the start of the vector
    p_ret_obj = _vec[0];
    // Delete the first value in the vector
    _vec.erase(_vec.begin());
}

// Purpose: Checks if the queue is empty
// Returns: True if the queue is empty
bool Queue::is_empty()
{
    return _vec.empty();
}

// Purpose: Returns the value at the front of the queue, without popping it
// Params : p_peek_obj - reference to the object to be overwritten by the data in the front of the queue
void Queue::peek(int &p_peek_obj)
{
    p_peek_obj = _vec[0];
}

int main()
{
    Queue q;

    int i = 0;
    int j = 1;

    q.enqueue(i);
    cout << "Enqueueing " << i << " to the queue" << endl;
    q.enqueue(j);
    cout << "Enqueueing " << j << " to the queue" << endl;

    int k, l, m;

    q.peek(m);
    cout << "Peeking into the queue, found " << m << endl;
    q.dequeue(k);
    cout << "Dequeueing, found " << k << endl;
    q.dequeue(l);
    cout << "Dequeueing, found " << l << endl;
    if (q.is_empty())
        cout << "The queue is now empty" << endl;
    else
        cout << "The queue is not empty" << endl;
}
