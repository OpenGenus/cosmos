/*
 * C++ Program To Implement AA Tree
 */
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int count, level;
    string key;	
    node *right;
    node *left;
    node *parent;
    node *root;
}*root;
 
/*
 * Class Declaration
 */
class AATree
{
    public:
        int lookup(string &);
        void skew(node *);
        bool split(node *);
        void rebal(node *);
        node *insert(node *,node *);
        void print(node *);
        int countnode(node *);
        AATree()
	{
            root = NULL;
        }
};
 
/*
 * Main: Contains Menu
 */
int main()
{
    AATree at;
    int ch;
    string x;
    ifstream fin ("test.txt");
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"\nOperations on AA Tree"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert String into the Tree"<<endl;
        cout<<"2.Print Tree Data"<<endl;
        cout<<"3.Total Tree Nodes"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            if (fin.is_open())
    	    {
                while (fin>>x)
                {
                    at.lookup(x);
                }
                fin.close();
            }
	    break;
        case 2:
            cout<<"Elemets of AA Tree"<<endl;
            at.print(root);
            break;
        case 3:
            cout<<"Total number of nodes"<<endl;
            cout<<at.countnode(root)<<endl;
            break;
        case 4:
            cout<<"Exiting"<<endl;
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}
/*
 * Insert String into the Tree
 */
int AATree::lookup(string &key)
{
    node *temp = new node;
    temp->key = key;
    temp->level = 1;
    temp->count = 0;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp = insert(root, temp);
    return temp->count;
}
 
/*
 * Skew Tree
 */
 
void AATree::skew(node *temp)
{
    node *ptr = temp->left;
    if (temp->parent->left == temp)
        temp->parent->left = ptr;
    else
        temp->parent->right = ptr;
    ptr->parent = temp->parent;
    temp->parent = ptr;
    temp->left = ptr->right;
    if (temp->left != NULL)
    	temp->left->parent = temp;
    ptr->right = temp;
    temp->level = (temp->left ? temp->left->level + 1 : 1);
}
 
/*
 * Splitting of AA Tree
 */
bool AATree::split(node *temp)
{
    node* ptr = temp->right;
    if (ptr && ptr->right && (ptr->right->level == temp->level))
    {
        if (temp->parent->left == temp)
            temp->parent->left = ptr;
        else
            temp->parent->right = ptr;
        ptr->parent = temp->parent;
        temp->parent = ptr;
        temp->right = ptr->left;
        if (temp->right != NULL)
            temp->right->parent = temp;
        ptr->left = temp;
        ptr->level = temp->level + 1;
        return true;
    }
    return false;
}
 
/*
 * Rebalancing of AA Tree
 */
void AATree::rebal(node* temp)
{
    temp->left = NULL;
    temp->right = NULL;
    temp->level = 1;
    for (temp = temp->parent; temp != root; temp = temp->parent)
    {
        if (temp->level != (temp->left ? temp->left->level + 1 : 1 ))
        {
            skew(temp);
            if (temp->right == NULL)
                temp = temp->parent;
            else if (temp->level != temp->right->level)
                temp = temp->parent;
        }
        if (temp->parent != root)
        {
            if (split(temp->parent) == false)
                break;
        }
    }
}
 
/*
 * Insert Function to insert string into the tree
 */
node* AATree::insert(node* temp, node* ins)
{
    if (root == NULL)
    {
        ins->count = 1;
        ins->parent = NULL;
        ins->left = NULL;
        ins->right = NULL;
        root = ins;
        return root;
    }
    if (ins->key < temp->key)
    {
        if (temp->left)
            return insert(temp->left, ins);
        temp->left = ins;
        ins->parent = temp;
        ins->count = 1;
        rebal(ins);
        return ins;
    }
    if (ins->key > temp->key)
    {
        if (temp->right)
            return insert(temp->right, ins);
        temp->right = ins;
        ins->parent = temp;
        ins->count = 1;
        rebal(ins);
        return ins;
    }
    temp->count++;
    delete ins;
    return temp;
}
 
/*
 * Display Tree Elements
 */
void AATree::print(node* temp)
{
    if (!temp)
        return;
    print(temp->left);
    cout <<"Value: "<<temp->key << "  Count:" << temp->count;
    cout<<"  Level: "<<temp->level<<endl;
    print(temp->right);
}
 
/*
 * Count number of nodes in AA Tree
 */
int AATree::countnode(node* temp)
{
    if (!temp)
        return 0;
    int count = 1;
    count = count + countnode(temp->left);
    count = count + countnode(temp->right);
    return count;
}
