#include <cassert>
#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

template <class T>
class Queue
{
private:
    class Node
    {
    public:
        Node(const T &data, Node *next)
            : data(data), next(next)
        {
        }

        T data;
        Node *next;
    };

public:
    Queue(void);
    ~Queue();

    void enqueue(const T &data);
    T dequeue(void);

    bool empty(void) const;
    int size(void) const;
    T &front(void);

private:
    Node *head;
    Node *back;
    int items;
};

template <class T>
Queue<T>::Queue(void) : head(NULL)
{
    items = 0;
}

template <class T>
Queue<T>::~Queue()
{
    while (head != NULL)
    {
        Node *tmpHead = head;
        head = head->next;
        delete tmpHead;
    }
}

template <class T>
void Queue<T>::enqueue(const T &data)
{
    Node *newNode = new Node(data, NULL);
    if (empty())
        head = (back = newNode);
    else
    {
        back->next = newNode;
        back = back->next;
    }

    items++;
}

template <class T>
T Queue<T>::dequeue(void)
{
    assert(!empty());
    Node *tmpHead = head;
    head = head->next;
    T data = tmpHead->data;
    items--;
    delete tmpHead;
    return data;
}

template <class T>
bool Queue<T>::empty(void) const
{
    return head == NULL;
}

template <class T>
int Queue<T>::size(void) const
{
    return items;
}

template <class T>
T &Queue<T>::front(void)
{
    assert(!empty());
    return head->data;
}

int main()
{
    Queue<int> queue;
    queue.enqueue(34);
    queue.enqueue(54);
    queue.enqueue(64);
    queue.enqueue(74);
    queue.enqueue(84);

    cout << queue.front() << endl;
    cout << queue.size() << endl;

    while (!queue.empty())
        cout << queue.dequeue() << endl;

    cout << queue.size() << endl;

    cout << endl;

    return 0;
}
