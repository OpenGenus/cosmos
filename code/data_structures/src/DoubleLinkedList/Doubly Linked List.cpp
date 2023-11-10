#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DLL {
private:
    Node* ptr;

public:
    DLL() {
        ptr = nullptr;
    }

    void Insert(int data) {
        Node* newnode = new Node(data);

        if (ptr == nullptr) {
            ptr = newnode;
        }
        else {
            Node* current = ptr;
            Node* prev = nullptr;
            Node* nextptr = current->next;

            while (current != nullptr && current->data < newnode->data) {
                prev = current;
                current = current->next;
            }

            if (current == nullptr) {
                prev->next = newnode;
                newnode->prev = prev;
            }
            else if (prev == nullptr) {
                newnode->next = ptr;
                ptr = newnode;
            }
            else {
                prev->next = newnode;
                newnode->next = current;
                newnode->prev = prev;
                current->prev = newnode;
            }
        }
    }

    void Display() {
        Node* temp = ptr;
        while (temp != nullptr) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "Null" << std::endl;
    }

    void Delete(int data) {
        if (ptr == nullptr) {
            std::cout << "List is Empty" << std::endl;
            return;
        }
        else {
            Node* current = ptr;
            Node* prev = nullptr;

            while (current != nullptr && current->data != data) {
                prev = current;
                current = current->next;
            }

            if (current != nullptr) {
                if (prev == nullptr) {
                    ptr = current->next;
                    if (ptr != nullptr)
                        current->prev = ptr;
                }
                else {
                    prev->next = current->next;
                    if (current->next != nullptr)
                        current->next->prev = prev;
                }
            }
            else {
                std::cout << "Item not found in List" << std::endl;
            }
        }
    }

    bool Empty() {
        return ptr == nullptr;
    }
};

int main() {
    DLL dll;

    while (true) {
        int choice;
        std::cout << "\n1.Insert\n2.Delete\n3.Check Empty\n4.Exit\nEnter Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int value;
            std::cout << "Enter element to Insert: ";
            std::cin >> value;
            dll.Insert(value);
            dll.Display();
        }
        else if (choice == 2) {
            int value;
            std::cout << "Enter element to Delete: ";
            std::cin >> value;
            dll.Delete(value);
            dll.Display();
        }
        else if (choice == 3) {
            std::cout << dll.Empty() << std::endl;
        }
        else if (choice == 4) {
            break;
        }
    }

    std::cout << "Program End" << std::endl;

    return 0;
}
