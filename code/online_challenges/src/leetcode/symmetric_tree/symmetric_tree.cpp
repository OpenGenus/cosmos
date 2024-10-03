/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        return (!left && left == right) ||
               (left && right && left->val == right->val && isMirror(left->left, right->right) && isMirror(left->right, right->left));
    }

    bool isSymmetric(TreeNode *root)
    {
        return !root || isMirror(root->left, root->right);
    }
};

