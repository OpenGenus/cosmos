#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void push(Node*& head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; 
}

int main() {
    Node* head = new Node(10);
    push(head, 11);
    push(head, 12);
    push(head, 13);
    push(head, 14);
    push(head, 15);
    cout << "Original List: "<<endl;
    print(head);

    head = reverse(head); 
    cout << "Reversed List: "<<endl;
    print(head);

    return 0;
}
