/* Part of Cosmos by OpenGenus Foundation */

/*
* Processes range minimum query.
* Query function returns index of minimum element in given interval.
* Code assumes that length of array can be contained into integer.
*/

#include <iostream>
#include <utility>
#include <vector>

struct Node
{
    // store the data in variable value
    int index;
    // store the interval in a pair of integers
    std::pair<int, int> interval;
    Node *left;
    Node *right;
};

int build(std::vector<int> &array, Node *node, int L, int R)
{
    node->interval = std::make_pair(L, R);
    if (L == R)
    {
        node->index = L;
        return node->index;
    }

    node->left = new Node;
    node->right = new Node;
    int leftIndex = build(array, node->left, L, (L + R) / 2);
    int rightIndex = build(array, node->right, (L + R) / 2 + 1, R);

    node->index = (array[leftIndex] < array[rightIndex]) ? leftIndex : rightIndex;

    return node->index;
}

// returns the index of smallest element in the range [start, end]
int query(std::vector<int> &array, Node *node, int start, int end)
{
    if (start > end)
        return -1;
    int L = node->interval.first;
    int R = node->interval.second;

    if (R < start || L > end)
    {
        return -1;
    }

    if (start <= L && end >= R)
    {
        return node->index;
    }

    int leftIndex = query(array, node->left, start, end);
    int rightIndex = query(array, node->right, start, end);

    if (leftIndex == -1)
        return rightIndex;
    if (rightIndex == -1)
        return leftIndex;

    return (array[leftIndex] < array[rightIndex]) ? leftIndex : rightIndex;
}

// update adds new value to array[x] rather than replace it
void update(std::vector<int> &array, Node *node, int x, int value)
{
    int L = node->interval.first;
    int R = node->interval.second;

    if (L == R)
    {
        array[L] += value;
        return;
    }

    if (L <= x && (L + R)/2 >= x)
        // x is in left subtree
        update(array, node->left, x, value);
    else
        // x is in right subtree
        update(array, node->right, x, value);

    int leftIndex = node->left->index;
    int rightIndex = node->right->index;

    //update current node
    node->index = (array[leftIndex] < array[rightIndex]) ? leftIndex : rightIndex;
}

// To clear allocated memory at end of program
void clearMem(Node *node)
{
    int L = node->interval.first;
    int R = node->interval.second;

    if (L != R)
    {
        clearMem(node->left);
        clearMem(node->right);
    }
    delete node;
}


int main()
{
    // define n and array
    int n = 8;
    std::vector<int> array = {5, 4, 3, 2, 1, 0, 7, 0};

    Node *root = new Node;
    build(array, root, 0, n - 1);

    // sample query

    std::cout << "The smallest element in the interval [1, 6] is "
              << array[query(array, root, 0, 5)] << '\n';

    // change 0 at index 5 to 8
    update(array, root, 5, 8);

    for (int i = 0; i < n; ++i)
        std::cout<<array[query(array, root, i, i)] << ' ';
    std::cout << '\n';

    std::cout << "The smallest element in the interval [1, 6] after update is "
              << array[query(array, root, 0, 5)] << '\n';

    clearMem(root);
    return 0;
}
