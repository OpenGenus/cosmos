#include <iostream>
#include <algorithm>

struct Leftist
{
    Leftist *left, *right;
    // dis is the distance to the right-bottom side of the tree
    int dis, value, size;
    Leftist(int val = 0)
    {
        left = NULL, right = NULL;
        dis = 0, value = val, size = 1;
    }
    ~Leftist()
    {
        delete left;
        delete right;
    }
};

Leftist* merge(Leftist *x, Leftist *y)
{
    // if x or y is NULL, return the other tree to be the answer
    if (x == NULL)
        return y;
    if (y == NULL)
        return x;

    if (y->value < x->value)
        std::swap(x, y);

    // We take x as new root, so add the size of y to x
    x->size += y->size;

    // merge the origin right sub-tree of x with y to construct the new right sub-tree of x
    x->right = merge(x->right, y);

    if (x->left == NULL && x->right != NULL)
        // if x->left is NULL pointer, swap the sub-trees to make it leftist
        std::swap(x->left, x->right);
    else if (x->right != NULL && x->left->dis < x->right->dis)
        // if the distance of left sub-tree is smaller, swap the sub-trees to make it leftist
        std::swap(x->left, x->right);

    // calculate the new distance
    if (x->right == NULL)
        x->dis = 0;
    else
        x->dis = x->right->dis + 1;
    return x;
}

Leftist* delete_root(Leftist *T)
{
    //deleting root equals to make a new tree containing only left sub-tree and right sub-tree
    Leftist *my_left = T->left;
    Leftist *my_right = T->right;
    T->left = T->right = NULL;
    delete T;
    return merge(my_left, my_right);
}

int main()
{

    Leftist *my_tree = new Leftist(10); // create a tree with root = 10
    // adding a node to a tree is the same as creating a new tree and merge them together
    my_tree = merge(my_tree, new Leftist(100)); // push 100
    my_tree = merge(my_tree, new Leftist(10000)); // push 10000
    my_tree = merge(my_tree, new Leftist(1));   // push 1
    my_tree = merge(my_tree, new Leftist(1266)); // push 1266
    while (my_tree != NULL)
    {
        std::cout << my_tree->value << std::endl;
        my_tree = delete_root(my_tree);
    }


    return 0;
}
/* the output should be
 * 1
 * 10
 * 100
 * 1266
 * 10000
 */
