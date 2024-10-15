#include <iostream>
using namespace std;

class Stack {
    int top;
    int* arr;
    int size;
public:
    Stack(int s) {
        size = s;
        arr = new int[s];
        top = -1;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
