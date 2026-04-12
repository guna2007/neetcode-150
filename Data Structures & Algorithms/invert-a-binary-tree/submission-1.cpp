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

    TreeNode* func(TreeNode* root)
    {
        if(!root) return NULL;


        func(root->left);
        func(root->right);
        swap(root->left,root->right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return func(root);
    }
};
