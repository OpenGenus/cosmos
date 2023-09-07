#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class DoublyLinkedList
{
public:

    struct Node{
        T data;    // data being stored
        Node *next;    // pointer to the next node
        Node *prev;    // pointer to the previous node
    };

    // CONSTRUCTION AND DESTRUCTION
    DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList<T>& list);
    ~DoublyLinkedList();

    // OPERATORS
    const T& operator[](unsigned int index) const;
    T& operator[](unsigned int index);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& rhs);
    // BEHAVIORS
    void PrintForward() const;
    void PrintReverse() const;
    // ACCESSORS
    unsigned int NodeCount() const;
    void FindAll(std::vector<Node*>& outData, const T& value) const;
    const Node* Find(const T& data) const;
    Node* Find(const T& data);
    const Node* GetNode(unsigned int index) const;
    Node* GetNode(unsigned int index);
    // INSERTION
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);

private:
    Node* head;    // pointer to the head
    Node* tail;    // pointer to the tail
    unsigned int nodeCount;    // node count
};

template<typename T>
typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::Find(const T &data) {
    Node *iter = head;
    while (true)
    {
        for (unsigned int i = 0; i < nodeCount; i++)
        {
            if (iter->data == data)
            {
                iter = data;
                break;
            }
            else
            {
                iter = nullptr;
                break;
            }
        }
        return iter;
    }
}

// CONSTRUCTORS
template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    nodeCount = 0; //set node count to 0
    head = nullptr; //initialize pointers to null
    tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &list)
{
    head = list.head;
    tail = nullptr;
    nodeCount = list.nodeCount;
    Node* current = head;
    while(current != nullptr)
    {
        AddTail(current->data);
        current = current->next;
    }
    tail->next= nullptr;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node *temp = head;
    head = tail = nullptr;
    while (temp)
    {
        Node *forward = temp->next;
        delete temp;
        temp = forward;
    }
}

template<typename T>
unsigned int DoublyLinkedList<T>::NodeCount() const
{
    return nodeCount;
}

template<typename T>
void DoublyLinkedList<T>::AddHead(const T &data)
{
    Node *newNode = new Node;    // allocate new node
    newNode->data = data;    // point to data
    newNode->next = head;    // make next the head node
    newNode->prev = nullptr;    // make prev null
    if(head != nullptr)
        head->prev = newNode; //previous of head node to new node

    if(tail == nullptr)
        tail = head;

    head = newNode; //head point to new node
    nodeCount++;
}

template<typename T>
void DoublyLinkedList<T>::AddTail(const T &data)
{
    Node *lastOne = head;    // creating node pointer to head/start of list
    Node *current = new Node;    // allocating space for new node soon to be tail
    current->data = data;    // new node pointing to passed in data
    current->next = nullptr;    // set the current next node pointer to null to indicate end
    current->prev = tail;    // set the tail(soon to be old) prev to the current pointer (soon to be new tail)
    if (head == nullptr || tail == nullptr)    // if head or tail are null
    {
        head = current;    // set head to current node
        head->prev = nullptr;    // set prev of head node to indicate it is head
        head->next = tail;    // the next node after the head should be tail, since only one element
        lastOne = current;    // the lastNode is the head which is now the current node we are trying to add
    }

    while (lastOne->next != nullptr)    // if its not nullptr
        lastOne = lastOne->next;    // iterate through the next node after each other until we reach null

    lastOne->next = current;    // now the next of the lastNode is the node we are trying to add
    tail = current;    // the tail is now the current node we are trying to add
    tail->next = nullptr;    // and next after tail should be null to indicate end
    nodeCount++;
}

template<typename T>
void DoublyLinkedList<T>::AddNodesHead(const T *data, unsigned int count)
{
    int index = (int)count-1;
    for(int i = index; i >= 0; i--)
        AddHead(data[i]);
}

template<typename T>
void DoublyLinkedList<T>::AddNodesTail(const T *data, unsigned int count)
{
    for(unsigned int i=0;i<count;i++)
        AddTail(data[i]);
}

template<typename T>
void DoublyLinkedList<T>::PrintForward() const
{
    Node *iter = head;
    while(iter != nullptr)
    {
        std::cout << iter->data << std::endl;
        iter = iter->next;
    }
}

template<typename T>
void DoublyLinkedList<T>::PrintReverse() const
{
    Node *iter = tail;
    while(iter != nullptr)
    {
        std::cout << iter->data << std::endl;
        iter = iter->prev;

    }
}

template<typename T>
T &DoublyLinkedList<T>::operator[](unsigned int index)
{
    if (index > nodeCount)
        throw std::out_of_range("Incorrect Index");
    else
    {
        unsigned int count = 0;
        Node *iter = head;
        while (count != index)
        {
            iter = iter->next;
            count++;
        }
        return iter->data;
    }
}

template<typename T>
const T &DoublyLinkedList<T>::operator[](unsigned int index) const
{
    if (index > nodeCount)
        throw std::out_of_range("Incorrect Index");
    else {
        unsigned int count = 0;
        Node *iter = head;
        while (count != index)
        {
            iter = iter->next;
            count++;
        }
        return iter->data;
    }
}

template<typename T>
void DoublyLinkedList<T>::FindAll(std::vector<Node *> &outData, const T &value) const {
    Node *iter = head;
    for(unsigned int i=0;i < nodeCount; i++)
    {
        if(iter->data == value)
            outData.push_back(iter);

        iter = iter->next;
    }
}

template<typename T>
DoublyLinkedList<T> &DoublyLinkedList<T>::operator=(const DoublyLinkedList<T> &rhs)
{
    Node *temp = head;
    head = tail = nullptr;
    while(temp)
    {
        Node *forward = temp->next;
        delete temp;
        temp = forward;
    }
    head = rhs.head;
    tail = nullptr;
    nodeCount = rhs.nodeCount;
    Node* current = head;
    while(current != nullptr)
    {
        AddTail(current->data);
        current = current->next;
    }
    tail->next= nullptr;
    delete current;
    return *this;
}

template<typename T>
const typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::GetNode(unsigned int index) const {
    try {
        if (index > nodeCount)
            throw std::out_of_range("Incorrect index");
        else {
            unsigned int count = 0;
            Node *iter = head;
            while (count != index) {
                iter = iter->next;
                count++;
            }
            return iter;
        }
    }
    catch (std::out_of_range &excpt)
    {
        std::cout << excpt.what() << std::endl;
    }

}

template<typename T>
typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::GetNode(unsigned int index)
{
    try
    {
        if ((index) >= nodeCount)
            throw "Incorrect index";
        else
        {
            unsigned int count = 0;
            Node *iter = head;
            while (count != index)
            {
                iter = iter->next;
                count++;
            }
            return iter;
        }
    }
    catch (const char* str) {
        std::cout << str << std::endl;
    }
}

template<typename T>
const typename DoublyLinkedList<T>::Node *DoublyLinkedList<T>::Find(const T &data) const
{
    Node *iter = head;
    while(true)
    {
        for (unsigned int i = 0; i < nodeCount; i++)
        {
            if (iter->data == data)
            {
                iter = data;
                break;
            }
            else
            {
                iter = nullptr;
                break;
            }
        }
        return iter;
    }
}









