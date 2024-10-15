#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;
public:
    Queue(int s) {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enqueue(int value) {
        if (rear == size - 1) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = value;
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Dequeued: " << arr[front++] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
