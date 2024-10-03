#include <iostream>

using namespace std;

template<class T>
class Node                              // doubly linked list node
{
    private:
        T data_;                        // data for node in linked list
        Node <T> *next_;                // next node in the list
        Node <T> *prev_;                // prev node in the list

    public:
        Node<T>();                      // constructor
        ~Node<T>();                     // destructor

        void setData(T data);           // set data for the node
        void setNext(Node<T> *next);    // set next node for the node
        void setPrev(Node<T> *prev);    // set prev node for the node
        T getData() const;              // get data from the node
        Node<T>* getNext();             // get pointer to the next node
        Node<T>* getPrev();             // get pointer to the prev node
};

template<class T>
class DoublyLinkedList
{
    private:
        Node<T>* head_;                 // head for the linked list
        Node<T>* tail_;                 // tail for the linked list
        const Node<T>* getHead() const; // return the head node of the list
        const Node<T>* getTail() const; // return the tail node of the list

    public:
        DoublyLinkedList<T>();          // constructor
        ~DoublyLinkedList<T>();         // destructor
        bool isEmpty() const;           // return true if list is empty
        T getFirst() const;             // return the data of the first node
        T getLast() const;              // return the data of the last node
        void addFirst(const T t);       // add to first position in the list
        void addLast(const T t);        // add to last position in the list
        void removeFirst();             // remove node from first position of list
        void removeLast();              // remove node from last position of list
};

/*
*  Class methods for the Node class.
*/

template<class T>
Node<T>::Node()
{
    /* Constructor for the Node. */
    next_ = NULL;
    prev_ = NULL;
}

template<class T>
Node<T>::~Node()
{
    /* Destructor for the Node. */
}

template<class T>
void Node<T>::setData(T data)
{
    /* Accessor method to set data for the node. */
    data_ = data;
}

template<class T>
void Node<T>::setNext(Node<T> *next)
{
    /* Accessor method to set next node for the node. */
    next_ = next;
}

template<class T>
void Node<T>::setPrev(Node<T> *prev)
{
    /* Accessor method to set previous node for the node. */
    prev_ = prev;
}

template<class T>
T Node<T>::getData() const
{
    /* Accessor method to get data for the node. */
    return data_;
}

template<class T>
Node<T>* Node<T>::getNext()
{
    /* Accessor method to get pointer to next node for the node. */
    return next_;
}

template<class T>
Node<T>* Node<T>::getPrev()
{
    /* Accessor method to get pointer to previous node for the node. */
    return prev_;
}

/*
*  Class methods for the DoublyLinkedList class.
*/
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    /* Constructor for the linked list. */
    head_ = NULL;     // set head_ to NULL
    tail_ = NULL;     // set tail_ to NULL
}

template<class T>
bool DoublyLinkedList<T>::isEmpty() const
{
    /* Return true if the list is empty. */
    return (head_ == NULL);
}

template<class T>
const Node<T>* DoublyLinkedList<T>::getHead() const
{
    /* Return the first node in the list. */
    return head_;
}

template<class T>
const Node<T>* DoublyLinkedList<T>::getTail() const
{
    /* Return the last node in the list. */
    return tail_;
}

template<class T>
T DoublyLinkedList<T>::getFirst() const
{
    /* Return the data at the first node in the list. */
    return head_->getData();
}

template<class T>
T DoublyLinkedList<T>::getLast() const
{
    /* Return the data at the first node in the list. */
    return tail_->getData();
}

template<class T>
void DoublyLinkedList<T>::addFirst(const T t)
{
    /* Add a node to the first position of the list. */

    Node<T>* new_node = new Node<T>;    // create a new node
    
    new_node->setData(t);               // set data for new node
    new_node->setNext(head_);           // set head as next for new node
    head_->setPrev(new_node);           // set new node as prev for head

    head_ = new_node;                   // set new node as head of the list

    if (tail_ == NULL)                  // list was empty; now has one node
        tail_ = head_;                  // set head and tail to point same node
}

template<class T>
void DoublyLinkedList<T>::removeFirst()
{
    /* Remove the node from the first position of the list. */

    if (head_ == NULL)                  // list is empty; nothing to remove
        return;

    Node<T>* node = new Node<T>;

    node = head_;                       // save the head node

    if (head_ == tail_)                 // only one node in the list
    {
        head_ = tail_ = NULL;           // set both head and tail to NULL
        delete node;                    // delete the only node
        return;
    }

    head_ = node->getNext();            // set new head
    head_->setPrev(NULL);               // set prev of head to NULL
    delete node;                        // delete the old head
}

template<class T>
void DoublyLinkedList<T>::addLast(const T t)
{
    /* Add a node to the last position of the list. */

    Node<T>* new_node = new Node<T>;    // create a new node
    
    new_node->setData(t);               // set data for new node

    if (head_ == NULL)                  // list is empty
    {
        head_ = tail_ = new_node;       // set new node as head and tail
        return;
    }

    tail_->setNext(new_node);           // set next of tail to new node
    new_node->setPrev(tail_);           // set previous of new node to tail
    tail_ = new_node;                   // make new node the tail node
}

template<class T>
void DoublyLinkedList<T>::removeLast()
{
    /* Remove the node from the last position of the list. */

    if (head_ == NULL)                  // list is empty; nothing to remove
        return;

    Node<T>* node = new Node<T>;

    if (head_ == tail_)                 // one node in the list
    {
        node = head_;                   // save the only node
        head_ = tail_ = NULL;           // set head and tail to NULL
        delete node;                    // delete the node at previously at head
        return;
    }

    node = tail_;                       // save node at tail
    tail_ = tail_->getPrev();           // set new tail to be prev of tail
    tail_->setNext(NULL);               // set next of tail to NULL
    delete node; 
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    /* Destructor for the linked list. */

    // Remove all the nodes until list is empty.
    while(!isEmpty())
    {
        removeFirst();
    }
}

int main()
{
    DoublyLinkedList<int> list;

    cout << list.isEmpty() << endl;

    list.addLast(20);
    list.addLast(30);

    cout << list.getFirst() << endl;
    cout << list.getLast() << endl;

    list.addFirst(10); 

    cout << list.getFirst() << endl;

    cout << list.isEmpty() << endl;

    list.removeLast();
    list.removeFirst();

    cout << list.getFirst() << endl;

    list.removeLast();

    cout << list.isEmpty() << endl;

    return 0;
}
