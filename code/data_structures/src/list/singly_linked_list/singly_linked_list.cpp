#ifndef _LINKED_LIST_CPP_
#define _LINKED_LIST_CPP_

#include <iostream>

template <typename T>
struct Node
{
    T date;
    Node* pNext;
};

template <typename T>
class Linkedlist
{
public:
    Linkedlist();
    Linkedlist(const Linkedlist<T> &list);
    Linkedlist<T>& operator= (const Linkedlist<T> &rhs);
    ~Linkedlist();

    void headAdd(const T& date);
    void rearAdd(const T& date);
    int size() const;
    bool isEmpty() const;
    void print() const;
    T getPos(int pos) const;
    void insert(int pos, const T& data);
    void deletePos(int pos);
    void modify(int pos, const T& date);
    int find(const T& date);
    void sort();
    void destroy();

private:
    Node<T>* header;
    int length;
};

template <typename T>
Linkedlist<T>::Linkedlist() : header(nullptr), length(0)
{
};

template <typename T>
Linkedlist<T>::Linkedlist(const Linkedlist<T> &list) : header(nullptr), length(0)
{
    int i = 1;
    while (i <= list.size())
    {
        rearAdd(list.getPos(i));
        i++;
    }
}

template <typename T>
Linkedlist<T>& Linkedlist<T>::operator= (const Linkedlist<T> &rhs)
{
    if (this == &rhs)
        return *this;
    destroy();
    for (int i = 1; i <= rhs.size(); ++i)
        rearAdd(rhs.getPos(i));
    return *this;
}

template <typename T>
Linkedlist<T>::~Linkedlist()
{
    destroy();
}

template <typename T>
void Linkedlist<T>::headAdd(const T& date)
{
    Node<T> *pNode = new Node<T>;
    pNode->date = date;
    pNode->pNext = nullptr;
    if (header == nullptr)
        header = pNode;
    else
    {
        pNode->pNext = header;
        header = pNode;
    }
    length++;
}

template <typename T>
void Linkedlist<T>::rearAdd(const T& date)
{
    Node<T> *pNode = new Node<T>;
    pNode->date = date;
    pNode->pNext = nullptr;
    if (header == nullptr)
        header = pNode;
    else
    {
        Node<T>* rear = header;
        while (rear->pNext != nullptr)
            rear = rear->pNext;
        rear->pNext = pNode;
    }
    length++;
}

template <typename T>
int Linkedlist<T>::size() const
{
    return length;
}

template <typename T>
bool Linkedlist<T>::isEmpty() const
{
    return header == nullptr;
}

template <typename T>
void Linkedlist<T>::print() const
{
    Node<T> *pTemp = header;
    int count = 0;
    while (pTemp != nullptr)
    {
        std::cout << pTemp->date << "\t";
        pTemp = pTemp->pNext;
        count++;
        if (count % 5 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
T Linkedlist<T>::getPos(int pos) const
{
    if (pos < 1 || pos > length)
        std::cerr << "get element position error!" << std::endl;
    else
    {
        int i = 1;
        Node<T> *pTemp = header;
        while (i++ < pos)
            pTemp = pTemp->pNext;
        return pTemp->date;
    }
}

template <typename T>
void Linkedlist<T>::insert(int pos, const T& date)
{
    if (pos < 1 || pos > length)
        std::cerr << "insert element position error!" << std::endl;
    else
    {
        if (pos == 1)
        {
            Node<T> *pTemp = new Node<T>;
            pTemp->date = date;
            pTemp->pNext = header;
            header = pTemp;
        }
        else
        {
            int i = 1;
            Node<T> *pTemp = header;
            while (++i < pos)
                pTemp = pTemp->pNext;
            Node<T> *pInsert = new Node<T>;
            pInsert->date = date;
            pInsert->pNext = pTemp->pNext;
            pTemp->pNext = pInsert;
        }
        length++;
    }
    return;
}

template <typename T>
void Linkedlist<T>::deletePos(int pos)
{
    if (pos < 0 || pos > length)
        std::cerr << "delete element position error!" << std::endl;
    else
    {
        Node<T> *deleteElement;
        if (pos == 0)
        {
            deleteElement = header;
            header = header->pNext;
        }
        else
        {
            int i = 0;
            Node<T> *pTemp = header;
            while (++i < pos)
                pTemp = pTemp->pNext;
            deleteElement = pTemp->pNext;
            pTemp->pNext = deleteElement->pNext;
        }
        delete deleteElement;
        length--;
    }
    return;
}

template <typename T>
void Linkedlist<T>::modify(int pos, const T& date)
{
    if (pos < 1 || pos > length)
        std::cerr << "modify element position error!" << std::endl;
    else
    {
        if (pos == 1)
            header->date = date;
        else
        {
            Node<T> *pTemp = header;
            int i = 1;
            while (i++ < pos)
                pTemp = pTemp->pNext;
            pTemp->date = date;
        }
    }
    return;
}

template <typename T>
int Linkedlist<T>::find(const T& date)
{
    int i = 1;
    int ret = -1;
    Node<T> *pTemp = header;
    while (!pTemp)
    {
        if (pTemp->date == date)
        {
            ret = i;
            break;
        }
        i++;
        pTemp = pTemp->pNext;
    }
    return ret;
}

template <typename T>
void Linkedlist<T>::sort()
{
    if (length > 1)
    {
        for (int i = length; i > 0; --i)
            for (int j = 1; j < i; j++)
            {
                T left = getPos(j);
                T right = getPos(j + 1);
                if (left > right)
                {
                    modify(j, right);
                    modify(j + 1, left);
                }
            }
    }
    return;
}

template <typename T>
void Linkedlist<T>::destroy()
{
    while (header != nullptr)
    {
        Node<T> *pTemp = header;
        header = header->pNext;
        delete pTemp;
    }
    length = 0;
}

#endif // _LINKED_LIST_CPP_

int main()
{
    Linkedlist<int> link;
    for (int i = 10; i > 0; --i)
        link.rearAdd(i);
    link.print();
    std::cout << link.size() << std::endl;
    Linkedlist<int> link1(link);
    link1 = link1;
    link1.print();
    link1.deletePos(100);
    link1.modify(5, 100);
    link1.insert(3, 50);
    std::cout << link1.size() << std::endl;
    link1.print();

    link1.sort();
    link1.print();
    link1.destroy();
    std::cout << link1.size() << std::endl;
    return 0;
}
