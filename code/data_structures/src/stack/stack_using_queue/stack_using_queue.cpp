/**
 * @brief Stack Data Structure Using the Queue Data Structure
 * @details
 * Using 2 Queues inside the Stack class, we can easily implement Stack
 * data structure with heavy computation in push function.
 * 
 * Part of Cosmos by OpenGenus Foundation
 */
#include <iostream> 
#include <queue>   
#include <cassert>
using namespace std;

class Stack
{
private:
    queue<int> main_q;         // stores the current state of the stack
    queue<int> auxiliary_q;    // used to carry out intermediate operations to implement stack
    int current_size = 0;     // stores the current size of the stack
public:
    int top();
    void push(int val);
    void pop();
    int size();
};

/**
 * Returns the top most element of the stack
 * @returns top element of the queue
 */
int Stack :: top()
{
    return main_q.front();
}

/**
 * @brief Inserts an element to the top of the stack.
 * @param val the element that will be inserted into the stack
 * @returns void
 */
void Stack :: push(int val)
{
    auxiliary_q.push(val);
    while(!main_q.empty())
    {
        auxiliary_q.push(main_q.front());
        main_q.pop();
    }
    swap(main_q, auxiliary_q);
    current_size++;
}

/**
 * @brief Removes the topmost element from the stack
 * @returns void
 */
void Stack :: pop()
{
    if(main_q.empty()) {
        return;
    }
    main_q.pop();
    current_size--;
}

/**
 * @brief Utility function to return the current size of the stack
 * @returns current size of stack
 */
int Stack :: size()
{
    return current_size;
}

int main()
{
    Stack s;
    s.push(1); // insert an element into the stack
    s.push(2); // insert an element into the stack
    s.push(3); // insert an element into the stack
  
    assert(s.size()==3); // size should be 3
    
    assert(s.top()==3); // topmost element in the stack should be 3
    
    s.pop(); // remove the topmost element from the stack
    assert(s.top()==2); // topmost element in the stack should now be 2
    
    s.pop(); // remove the topmost element from the stack
    assert(s.top()==1);
    
    s.push(5); // insert an element into the stack
    assert(s.top()==5); // topmost element in the stack should now be 5
    
    s.pop(); // remove the topmost element from the stack
    assert(s.top()==1); // topmost element in the stack should now be 1
    
    assert(s.size()==1); // size should be 1
    return 0;
}
