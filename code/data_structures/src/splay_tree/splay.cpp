#include <iostream>
#include <stdlib.h>

struct Node
{
    int value;
    Node *left;
    Node *right;
    Node *parent;
};
Node *g_root;

void inOrder(Node *cur, std::string &s)
{
    if(cur==NULL)
        return;
    if(cur->left)
        inOrder(cur->left, s);
    s += std::to_string(cur->value) + " ";
    if(cur->right)
        inOrder(cur->right, s);
}
void rightRotate(Node *z)
{
    Node *l = z->left;
    Node *c = l->right;
    Node *p = z->parent;
    if (p != NULL)
    {
        if (p->left == z)
            p->left = l;
        else 
            p->right = l;
    }
    l->parent = p;
    l->right = z;
    z->parent = l;
    z->left = c;
    if (c != NULL)
        c->parent = z;
}

void leftRotate(Node *z)
{
    Node *r = z->right;
    Node *c = r->left;
    Node *p = z->parent;
    if (p != NULL)
    {
        if (p->left == z)
            p->left = r;
        else 
            p->right = r;
    }
    r->parent = p;
    r->left = z;
    z->parent = r;
    z->right = c;
    if (c != NULL)
        c->parent = z;
}

void splay(Node *z)
{
    if (z == NULL)
        return;
    while (true)
    {
        Node *par = z->parent;
        if (par == NULL)
        {
            // z is the root
            break;
        }
        Node *gPar = par->parent;
        if (gPar == NULL && par->left == z)
        {
            // zig
            rightRotate(par);
        }
        else if (gPar == NULL && par->right == z)
        {
            // zag
            leftRotate(par);
        }
        else if (gPar->left == par && par->left == z)
        {
            // zig-zig
            rightRotate(gPar);
            rightRotate(par);
        }
        else if (gPar->right == par && par->right == z)
        {
            // zag-zag
            leftRotate(gPar);
            leftRotate(par);
        }
        else if (gPar->left == par && par->right == z)
        {
            // zig-zag
            leftRotate(par);
            rightRotate(gPar);
        }
        else if(gPar->right == par && par -> left ==z)
        {
            // zag-zig
            rightRotate(par);
            leftRotate(gPar);
        }
    }
    g_root = z;
}

void insert(int val)
{
    Node *t = new Node();
    t->left = NULL;
    t->right = NULL;
    t->left = NULL;
    t->value = val;
    if (g_root == NULL)
    {
        g_root = t;
        return;
    }
    Node *z = g_root;
    while (true)
    {
        if (z->value > val)
        {
            if (z->left == NULL)
            {
                z->left = t;
                t->parent = z;
                break;
            }
            else
                z = z->left;
        }
        else if (z->value < val)
        {
            if (z->right == NULL)
            {
                z->right = t;
                t->parent = z;
                break;
            }
            else
                z = z->right;
        }
        else
        {
            // val is already present in the three
            break;
        }
    }
    splay(t);
}

Node* find(int val)
{
    if (g_root == NULL)
    {
        return NULL;
    }
    Node *cur = g_root;
    while (true)
    {
        if (cur->value == val)
            break;
        else if (cur->value > val)
        {
            if (cur->left == NULL)
                break;
            else
                cur = cur->left;
        }
        else
        {
            if (cur->right == NULL)
                break;
            else
                cur = cur->right;
        }
    }
    if(cur != NULL){
        splay(cur);
        if (cur->value == val)
            return cur;
        else
            return NULL;

    }
    else
        return NULL;
}

bool remove(int val)
{
    Node *z = find(val);
    if (z == NULL)
        return false;
    splay(z);
    Node *t = z->left;
    if (t == NULL)
    {
        g_root = z->right;
        g_root->parent = NULL;
    }
    else
    {
        while (t->right)
            t = t->right;
        if (z->right != NULL)
        {
            t->right = z->right;
            z->right->parent=t;
        }
        g_root = z->left;
        g_root->parent = NULL;
    }
    free(z);
    return true;
}


int main()
{
    int a, v;
    bool c;
    Node *temp;
    while (true)
    {
        std::cout<<"1. Insert Element \n";
        std::cout<<"2. Find Element \n";
        std::cout<<"3. Delete Element \n";
        std::cout<<"4. Inorder Travelsal \n";
        std::cout<<"5. Exit \n";
        std::cin>>a;
        if (a == 1)
        {
            std::cout<<"Enter the value to be inserted: \n";
            std::cin>>v;
            insert(v);
        }
        else if (a == 2)
        {
            std::cout<<"Enter the value to be searched: \n";
            std::cin>>v;
            temp=find(v);
            if ((temp != NULL) && (temp->value == v))  
                std::cout<<"Found! \n";
            else
                std::cout<<"Not Found! \n";
        }
        else if (a == 3)
        {
            std::cout<<"Enter the value to be deleted: \n";
            std::cin>>v;
            c = remove(v);
            if (c)
                std::cout<<"Element deleted! \n";
            else
                std::cout<<"Couldn't be deleted! \n";
        }
        else if (a == 4)
        {
            std::string ino;
            inOrder(g_root, ino);
            std::cout<<"Inorder travelsal: \n";
            std::cout<<ino<<"\n";
        }
        else if (a == 5)
            break;
        else
        {
            std::cout<<"Wrong Input \n";
        }
    }

    return 0;
}

