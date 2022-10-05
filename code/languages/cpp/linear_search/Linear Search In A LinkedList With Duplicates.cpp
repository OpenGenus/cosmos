#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *nptr; // next pointer
};

struct node *hptr = NULL; // head pointer

void insert(int pos, int x)
{
    struct node *temp = new node;
    if (temp == NULL)
        cout<<"Insertion not possible\n";
    temp->data = x; // storing the value in data field
    if (pos == 1)
    {
        temp->nptr = hptr;
        hptr = temp;
    }
    else
    {
        int i = 1;
        struct node *thptr = hptr; // temporary pointer
        while (i < pos - 1)
        {
            thptr = thptr->nptr; // traversing to the position of insertion
            i++;
        }
        temp->nptr = thptr->nptr;
        thptr->nptr = temp;
    }
}

void print()
{
    struct node *temp = hptr;
    cout<<"Linked List contains : \n";
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->nptr;
    }
}
int ind;
int *linearSearch(int key, int result[])
{
    struct node *temp = hptr;
    int i = 1;
    ind = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            result[ind++] = i;
        }
        else
        {
            result[ind] = -1;
            ind++;
        }
        i++;
        temp = temp->nptr;
    }
    return result;
}

int main()
{
    int result[10];
    insert(1, 11);
    insert(2, 6);
    insert(3, 12);
    insert(4, 14);
    insert(5, 6);
    insert(6, 10);
    insert(7, 6);
    print();
    printf("\nPosition(s) of the key is : ");
    linearSearch(6, result);
    for (int i = 0; i < ind; i++)
    {
        if (result[i] != -1)
            cout<<result[i]<<" ";
    }
    return 0;
}
