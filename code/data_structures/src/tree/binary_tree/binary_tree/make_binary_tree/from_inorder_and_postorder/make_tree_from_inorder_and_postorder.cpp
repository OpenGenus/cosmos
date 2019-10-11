#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class TreeNode
{
    using Treetype = TreeNode<T>;

public:
    T data;
    Treetype * left;
    Treetype * right;

    TreeNode(T data) : data(data), left(NULL), right(NULL)
    {
    }
};

template <typename BidiIt>
TreeNode<int>* buildTreeHelper(BidiIt in_first, BidiIt in_last,
                               BidiIt post_first, BidiIt post_last);

TreeNode<int>* buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return buildTreeHelper(begin(inorder), end(inorder),
                           begin(postorder), end(postorder));
}

template <typename BidiIt>
TreeNode<int>* buildTreeHelper(BidiIt in_first, BidiIt in_last,
                               BidiIt post_first, BidiIt post_last)
{
    if (in_first == in_last)
        return nullptr;
    if (post_first == post_last)
        return nullptr;
    const auto val = *prev(post_last);
    TreeNode<int>* root = new TreeNode<int>(val);
    auto in_root_pos = find(in_first, in_last, val);
    auto left_size = distance(in_first, in_root_pos);
    auto post_left_last = next(post_first, left_size);
    root->left = buildTreeHelper(in_first, in_root_pos, post_first, post_left_last);
    root->right = buildTreeHelper(next(in_root_pos), in_last, post_left_last,
                                  prev(post_last));
    return root;
}

void postorderPrint(TreeNode<int>* root)
{
    if (root == NULL)
        return;

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";

    return;
}

int main()
{
    vector<int> postorder = {7, 8, 6, 4, 2, 5, 3, 1};
    vector<int> inorder = {4, 7, 6, 8, 2, 1, 3, 5};

    TreeNode<int>* root = buildTree(inorder, postorder);

    postorderPrint(root);    // 7 8 6 4 2 5 3 1

    return 0;
}

/*
 * // test tree is
 *              1
 *             / \
 *            2   3
 *           /     \
 *          4       5
 \
 \           6
 \          / \
 \         7   8
 */
