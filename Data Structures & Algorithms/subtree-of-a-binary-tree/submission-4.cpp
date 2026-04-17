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

    bool issame(TreeNode* p, TreeNode* q)
    {
        if(!p && !q) return 1;
        if(!p || !q) return 0;
        if(p->val == q->val)
            return issame(p->left,q->left) && issame(p->right,q->right);
        else return 0;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;
        
        if(root->val == subRoot->val && issame(root,subRoot))
            return true;
        int l = isSubtree(root->left,subRoot);
        int r = isSubtree(root->right,subRoot);
        
        return l || r;
    }
};
