/* Part of Cosmos by OpenGenus Foundation */

#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

template <typename T>
struct node
{
    T n;
    node *next;
};

template <class T>
class Stack
{
private:
    node<T> *top;
public:
    Stack();
    void push(T);
    T pop();
    void display();
};

template <class T> Stack<T>::Stack()
{
    top = nullptr;
}

template <class T> void Stack<T>::push(T n)
{
    node<T> *ptr = new node<T>;
    ptr->n = n;
    ptr->next = top;
    top = ptr;
}

template <class T> T Stack<T>::pop()
{
    if (top == nullptr)
        return INT_MIN;
    node<T> *ptr = top;
    T n = ptr->n;
    top = top->next;
    delete ptr;
    return n;
}

template <class T> void Stack<T>::display()
{
    node<T> *ptr = top;
    while (ptr != nullptr)
    {
        cout << ptr->n << "-> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Stack<int> S;
    int n, choice;
    while (true)
    {
        system("cls");
        cout << "1.Push" << endl
             << "2.Pop" << endl
             << "3.Display" << endl
             << "4.Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be entered. ";
            cin >> n;
            S.push(n);
            break;
        case 2:
            S.pop();
            break;
        case 3:
            S.display();
            system("pause");
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
