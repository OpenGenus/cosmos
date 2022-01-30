#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class LinkedList
{
  public:
    struct Node
    {
      T data;
      Node* next = nullptr;
      Node* prev = nullptr;
    };
    Node* headNode = nullptr;
    Node* tailNode = nullptr;
    int numberOfNodes = 0;

    LinkedList();
    ~LinkedList();

    bool isEmpty();
    void PrintForward() const;
    void PrintReverse() const;
    unsigned int NodeCount() const;
    void AddHead(const T& data);
    void AddTail(const T& data);
    Node* GetNode(unsigned int index);
    void InsertAt(const T& data, unsigned int index);
    bool RemoveAt(unsigned int index);
    void Clear();
};

template <typename T>
 LinkedList<T>::LinkedList()
 {
  numberOfNodes = 0;
  headNode = nullptr;
  tailNode = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node* tracker = headNode;
  Node* newTracker = nullptr;
  while (tracker != nullptr) {
        newTracker = tracker->next;
        delete tracker;
        tracker = newTracker;
    }
  numberOfNodes = 0;
  headNode = nullptr;
  tailNode = nullptr;
  tracker = nullptr;
}

template <typename T>
LinkedList<T>::isEmpty()
{
  return head == nullptr;
}

template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
  Node* newHead = new Node;
  newHead->data = data;
  newHead->prev = nullptr;
  if (headNode == nullptr)
  {
    newHead->next = nullptr;
    headNode = newHead;
    tailNode = newHead;
  }
  else
  {
    headNode->prev = newHead;
    newHead->next = headNode;
    headNode = newHead;
  }
  numberOfNodes += 1;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
  Node* newTail = new Node;
  newTail->data = data;
  newTail->next = nullptr;
  if (tailNode == nullptr)
  {
    newTail->prev = nullptr;
    headNode = newTail;
    tailNode = newTail;
  }
  else
  {
    tailNode->next = newTail;
    newTail->prev = tailNode;
    tailNode = newTail;
  }
  numberOfNodes += 1;
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
  return numberOfNodes;
}

template <typename T>
void LinkedList<T>::PrintForward() const
{
  Node* tracker = headNode;
  for (int i = 0; i < numberOfNodes; i++)
  {
    std::cout << tracker->data << std::endl;
    tracker = tracker->next;
  }
}

template <typename T>
void LinkedList<T>::PrintReverse() const
{
  Node* tracker = tailNode;
  for (int i = 0; i < numberOfNodes; i++)
  {
    std::cout << tracker->data << std::endl;
    tracker = tracker->prev;
  }
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
  unsigned int nodes = this->numberOfNodes;
  if (index >= nodes)
  {
    throw std::out_of_range("Value is outside of range!");
  }
  else
  {
    Node* tracker = headNode;
    for (unsigned int i = 0; i < index; i++)
    {
      tracker = tracker->next;
    }
    return tracker;
  }
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
  unsigned int nodes = this->numberOfNodes;
  if (index > nodes)
  {
    throw std::out_of_range("Value is outside of range!");
  }
  else if (index == nodes)
  {
    this->AddTail(data);
  }
  else if (index == 0)
  {
    this->AddHead(data);
  }
  else
  {
    this->InsertBefore(this->GetNode(index), data);
  }
}

template <typename T>
bool LinkedList<T>::RemoveHead()
{
  if (headNode->next == nullptr && headNode->prev == nullptr)
  {
    delete headNode;
    headNode = nullptr;
    tailNode = nullptr;
    numberOfNodes -= 1;
    return false;
  }
  else
  {
    Node* newHead = headNode->next;
    headNode->next->prev = nullptr;
    headNode->next = nullptr;
    delete headNode;
    headNode = newHead;
    numberOfNodes -= 1;
    return true;
  }
}

template <typename T>
bool LinkedList<T>::RemoveTail()
{
  Node* newTail = tailNode->prev;
  tailNode->prev->next = nullptr;
  tailNode->prev = nullptr;
  delete tailNode;
  tailNode = newTail;
  numberOfNodes -= 1;
  if (tailNode->next == nullptr && tailNode->prev == nullptr)
  {
    delete tailNode;
    headNode = nullptr;
    tailNode = nullptr;
    numberOfNodes -= 1;
    return false;
  }
  return true;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
  unsigned int nodes = this->numberOfNodes;
  if (index > nodes)
  {
    return false;
  }
  else if (index == nodes)
  {
    return this->RemoveTail();
  }
  else if (index == 0)
  {
    return this->RemoveHead();
  }
  else
  {
    Node* queueDelete = this->GetNode(index);
    queueDelete->next->prev = queueDelete->prev;
    queueDelete->prev->next = queueDelete->next;
    delete queueDelete;
    numberOfNodes -= 1;
    return true;
  }
}

template <typename T>
void LinkedList<T>::Clear()
{
  Node* tracker = headNode;
  Node* newTracker = nullptr;
  while (tracker != nullptr)
  {
        newTracker = tracker->next;
        delete tracker;
        tracker = newTracker;
    }
  numberOfNodes = 0;
  headNode = nullptr;
  tailNode = nullptr;
  tracker = nullptr;
}
