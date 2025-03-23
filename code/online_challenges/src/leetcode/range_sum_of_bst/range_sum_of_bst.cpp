/* Part of Cosmos by OpenGenus Foundation */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   
public:
    int gsum=0;
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        if(root == NULL) return gsum;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            root = s.top();
            s.pop();
            if(root != NULL)
            {
                if(root -> val >= L && root -> val <= R) gsum += root -> val;
                if(root -> val > L) s.push(root -> left);
                if(root -> val < R) s.push(root -> right);
            }
        }
        
        return gsum;
        
    }
};