#include <iostream>
// Part of Cosmos by OpenGenus Foundation
using namespace std;

int main()
{

    struct node
    {
        int info;
        node *next;
    }*ptr, *head, *start;

    int c = 1, data;

    ptr = new node;
    ptr->next = NULL;

    start = head = ptr;

    while (c < 3 && c > 0)
    {
        cout << "1.Insert\n2.Link List\n";
        cin >> c;

        switch (c){
        case 1:
            cout << "Enter Data\n";
            cin >> data;

            ptr = new node;
            ptr->next = start;
            ptr->info = data;

            head->next = ptr;
            head = ptr;

            break;

        case 2:
            ptr = start->next;

            while (ptr != start && ptr != NULL)
            {
                cout << ptr->info << "->";
                ptr = ptr->next;
            }
            cout << "\n";
            break;

        default:
            cout << "Wrong Choice\nExiting...\n";
        }

    }

    return 0;
}
