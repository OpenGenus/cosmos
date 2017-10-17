// Program to mergesort linked list

#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *next;
} node;


node* insert(node *root, int data)
{

    node *tail = malloc(sizeof(node));
    tail->data = data;
    tail->next = NULL;

    if (!root)
    {
        root = tail;
        return root;
    }
    node *temp = root;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = tail;
    return root;
}

void print(node *root)
{
    node *temp = root;
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node* merge(node *lroot, node *rroot)
{
    node *root, *temp;

    if (lroot->data <= rroot->data)
    {
        root = temp = lroot;
        lroot = lroot->next;
    }
    else
    {
        root = temp = rroot;
        rroot = rroot->next;
    }

    while (lroot && rroot)
    {
        if (lroot->data <= rroot->data)
        {
            temp->next = lroot;
            temp = temp->next;
            lroot = lroot->next;
        }
        else
        {
            temp->next = rroot;
            temp = temp->next;
            rroot = rroot->next;
        }
    }

    while (lroot)
    {
        temp->next = lroot;
        temp = temp->next;
        lroot = lroot->next;
    }

    while (rroot)
    {
        temp->next = rroot;
        temp = temp->next;
        rroot = rroot->next;
    }

    return root;
}

node* merge_sort(node *root, int len)
{
    node *temp = root, *prev;
    int llen = 0;

    if (len == 1)
    {
        return root;
    }

    while (llen < len / 2)
    {
        prev = temp;
        temp = temp->next;
        llen++;
    }
    prev->next = NULL;

    node *lroot = merge_sort(root, llen);
    node *rroot = merge_sort(temp, len - llen);

    temp = merge(lroot, rroot);

    return temp;
}


int main()
{
    node *root = NULL, *temp;
    int len = 0;

    root = insert(root, 2);
    root = insert(root, 1);
    root = insert(root, 13);
    root = insert(root, 42);
    root = insert(root, -2);
    root = insert(root, 67);
    root = insert(root, 22);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 12);
    print(root);

    temp = root;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    printf("\n");
    root = merge_sort(root, len);
    print(root);
    return 0;
}
