#include <iostream>

using namespace std;

template<class T>
class Node                              // singly linked list node
{
    private:
        T data_;                        // data for node in linked list
        Node <T> *next_;                // next node in the list

    public:
        Node<T>();                      // constructor
        ~Node<T>() { }                  // destructor

        void setData(T data);           // set data for the node
        void setNext(Node<T> *next);    // set next node for the node
        T getData() const;              // get data from the node
        Node<T>* getNext();             // get pointer to the next node
};

template<class T>
class LinkedList
{
    private:
        Node<T>* head_;                 // head for the linked list
        const Node<T>* getHead() const; // return the head node of the list

    public:
        LinkedList<T>();                // constructor
        ~LinkedList<T>();               // destructor
        bool isEmpty() const;           // return true if list is empty
        T getFirst() const;             // return the data of the first node
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


/*
*  Class methods for the LinkedList class.
*/
template<class T>
LinkedList<T>::LinkedList()
{
    /* Constructor for the linked list. */
    head_ = NULL;     // set head_ to NULL
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* Return true if the list is empty. */
    return (head_ == NULL);
}

template<class T>
const Node<T>* LinkedList<T>::getHead() const
{
    /* Return the first node in the list. */
    return head_;
}

template<class T>
T LinkedList<T>::getFirst() const
{
    /* Return the data at the first node in the list. */
    return head_->getData();
}

template<class T>
void LinkedList<T>::addFirst(const T t)
{
    /* Add a node to the first position of the list. */

    Node<T>* new_node = new Node<T>;    // create a new node
    
    new_node->setData(t);               // set data for new node
    new_node->setNext(head_);           // set pointer to head

    head_ = new_node;                   // set new node as head of the list
}

template<class T>
void LinkedList<T>::removeFirst()
{
    /* Remove the node from the first position of the list. */

    if (head_ == NULL)                  // list is empty; nothing to remove
        return;

    Node<T> *node = head_;              // save current head
    head_ = node->getNext();            // set new head
    delete node;                        // delete the old head
}

template<class T>
void LinkedList<T>::addLast(const T t)
{
    /* Add a node to the last position of the list. */

    Node<T>* new_node = new Node<T>;    // create a new node
    
    new_node->setData(t);               // set data for new node

    if (head_ == NULL)                  // list is empty
    {
        head_ = new_node;               // set new node as head_
        return;
    }

    // find the last node in the list
    Node<T>* node = new Node<T>;
    node = head_;

    while (node->getNext() != NULL)
    {
        node = node->getNext();
    }

    node->setNext(new_node);            // set new node as the last node  
}

template<class T>
void LinkedList<T>::removeLast()
{
    /* Remove the node from the last position of the list. */

    if (head_ == NULL)                  // list is empty; nothing to remove
        return;

    // find the last node in the list
    Node<T>* node = new Node<T>;
    Node<T>* prev = new Node<T>;

    node = head_;

    if (head_->getNext() == NULL)        // one node in the list
    {
        head_ = NULL;                   // set head to NULL
        delete node;                   // delete the node at previously at head
        return;
    }

    while (node->getNext() != NULL)
    {
        prev = node;
        node = node->getNext();
    }

    prev->setNext(NULL);                // set second to last node to point NULL
    delete node;                        // delete the last node
}

template<class T>
LinkedList<T>::~LinkedList()
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
    LinkedList<int> list;

    cout << list.isEmpty() << endl;

    list.addLast(20);
    list.addLast(30);

    cout << list.getFirst() << endl;

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
