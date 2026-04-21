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

    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root) return NULL;

        TreeNode* l = helper(root->left,p,q);
        TreeNode* r = helper(root->right,p,q);

        

        if(root->val < p->val && root->val < q->val) return r;
        if(root->val > p->val && root->val > q->val) return l;
        if(root->val > p->val || root->val > q->val) return root;

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return helper(root,p,q);
    }
};
