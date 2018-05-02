#include <iostream>
#include <stdlib.h>

class SplayTree
{
    public:

    class Node
    {
        public:
        int value;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;

        Node(int v){
            value = v;
        }
    };

    void inOrder(Node*, std::string &s);
    void rightRotate(Node*);
    void leftRotate(Node*);
    void splay(Node*);
    void insert(int val);
    Node* find(int val);
    bool remove(int val);

    Node *root=nullptr;

};

void SplayTree::inOrder(Node *cur, std::string &s)
{
    if (cur == nullptr)
        return;
    if (cur->left)
        inOrder(cur->left, s);
    s += std::to_string(cur->value) + " ";
    if (cur->right)
        inOrder(cur->right, s);
}


void SplayTree::rightRotate(Node *z)
{
    Node *l = z->left;
    Node *c = l->right;
    Node *p = z->parent;
    if (p != nullptr)
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
    if (c != nullptr)
        c->parent = z;
}

void SplayTree::leftRotate(Node *z)
{
    Node *r = z->right;
    Node *c = r->left;
    Node *p = z->parent;
    if (p != nullptr)
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
    if (c != nullptr)
        c->parent = z;
}

void SplayTree::splay(Node *z)
{
    if (z == nullptr)
        return;
    while (true)
    {
        Node *par = z->parent;
        if (par == nullptr)
        {
            // z is the root
            break;
        }
        Node *gPar = par->parent;
        if (gPar == nullptr && par->left == z)
        {
            // zig
            rightRotate(par);
        }
        else if (gPar == nullptr && par->right == z)
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
    root = z;
}

void SplayTree::insert(int val)
{
    Node *t = new Node(val);
    if (root == nullptr)
    {
        root = t;
        return;
    }
    Node *z = root;
    while (true)
    {
        if (z->value > val)
        {
            if (z->left == nullptr)
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
            if (z->right == nullptr)
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

SplayTree::Node* SplayTree::find(int val)
{
    if (root == nullptr)
        return nullptr;
    Node *cur = root;
    while (true)
    {
        if (cur->value == val)
            break;
        else if (cur->value > val)
        {
            if (cur->left == nullptr)
                break;
            else
                cur = cur->left;
        }
        else
        {
            if (cur->right == nullptr)
                break;
            else
                cur = cur->right;
        }
    }
    if(cur != nullptr){
        splay(cur);
        if (cur->value == val)
            return cur;
        else
            return nullptr;

    }
    else
        return nullptr;
}

bool SplayTree::remove(int val)
{
    Node *z = find(val);
    if (z == nullptr)
        return false;
    splay(z);
    Node *t = z->left;
    if (t == nullptr)
    {
        root = z->right;
        root->parent = nullptr;
    }
    else
    {
        while (t->right)
            t = t->right;
        if (z->right != nullptr)
        {
            t->right = z->right;
            z->right->parent=t;
        }
        root = z->left;
        root->parent = nullptr;
    }
    free(z);
    return true;
}


int main()
{
    int a, v;
    bool c;
    SplayTree t;
    SplayTree::Node *temp;
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
            t.insert(v);
        }
        else if (a == 2)
        {
            std::cout<<"Enter the value to be searched: \n";
            std::cin>>v;
            temp=t.find(v);
            if ((temp != nullptr) && (temp->value == v))  
                std::cout<<"Found! \n";
            else
                std::cout<<"Not Found! \n";
        }
        else if (a == 3)
        {
            std::cout<<"Enter the value to be deleted: \n";
            std::cin>>v;
            c = t.remove(v);
            if (c)
                std::cout<<"Element deleted! \n";
            else
                std::cout<<"Couldn't be deleted! \n";
        }
        else if (a == 4)
        {
            std::string ino;
            t.inOrder(t.root,ino);
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

