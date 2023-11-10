#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}


    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void printForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printBackward() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;

    cout << "Enter the number of nodes in linked list: ";
    cin >> n;

    int x;
    cout << "Enter element no. 0: ";
    cin >> x;
    dll.insertAtHead(x);

    for(int i=1; i<n; i++)
    {
        int x;
        cout << "Enter element no. " << i << ": ";
        cin >> x;
        dll.insertAtTail(x);
    }

    std::cout << "Forward: ";
    dll.printForward(); // Output: 0 1 2 3

    std::cout << "Backward: ";
    dll.printBackward(); // Output: 3 2 1 0

    return 0;
}
