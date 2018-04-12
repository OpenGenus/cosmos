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

void rightview(struct node *root, int level, int *maxlevel)
{
    if (root == NULL)
        return;


    if (*maxlevel < level)
    {
        cout << root->d << " ";
        *maxlevel = level;
    }

    rightview(root->right, level + 1, maxlevel);
    rightview(root->left, level + 1, maxlevel);

}

int main()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);


    int maxlevel = 0;

    cout << "\nRight view : ";
    rightview(root, 1, &maxlevel);

    cout << endl;
    return 0;
}
