#include <iostream>
using namespace std;
// Part of Cosmos by OpenGenus Foundation
struct node
{
    int d;
    node *left;
    node *right;
};

struct node* newnode(int num)
{
    node *temp = new node;
    temp->d = num;
    temp->left = temp->right = NULL;
    return temp;
}

void lefttree(struct node *root, int level, int *maxlevel)
{
    if (root == NULL)
        return;


    if (*maxlevel < level)
    {
        cout << root->d << endl;
        *maxlevel = level;
    }

    lefttree(root->left, level + 1, maxlevel);
    lefttree(root->right, level + 1, maxlevel);

}

int main()
{
    node *root = newnode(12);
    root->left = newnode(10);
    root->right = newnode(30);
    root->right->left = newnode(25);
    root->right->right = newnode(40);

    int maxlevel = 0;

    lefttree(root, 1, &maxlevel);

    cout << endl;
    return 0;
}
