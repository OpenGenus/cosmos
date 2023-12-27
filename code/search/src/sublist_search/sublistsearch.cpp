#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

bool isPresent(Node* list_pointer, Node* sub_pointer)
{
    Node* curr1 = list_pointer, *curr2 = sub_pointer;


    if (list_pointer == NULL && sub_pointer == NULL)
        return true;

    if ( sub_pointer == NULL || (sub_pointer != NULL && list_pointer == NULL))
        return false;

    while (list_pointer != NULL)
    {
        curr1 = list_pointer;

        while (curr2 != NULL)
        {
            if (curr1 == NULL)
                return false;


            else if (curr2->data == curr1->data)
            {
                curr2 = curr2->next;
                curr1 = curr1->next;
            }

            else
                break;
        }
        if (curr2 == NULL)
            return true;

        curr2 = sub_pointer;

        list_pointer = list_pointer->next;
    }

    return false;
}

int main()
{

    Node *list = new Node(8);
    list->next = new Node(2);
    list->next->next = new Node(3);
    list->next->next->next = new Node(4);
    list->next->next->next->next = new Node(6);
    list->next->next->next->next->next = new Node(9);

    Node *sub_list = new Node(3);
    sub_list->next = new Node(4);
    sub_list->next->next = new Node(6);

    if (isPresent(list, sub_list))
        cout << "true";
    else
        cout << "false";

    return 0;
}
