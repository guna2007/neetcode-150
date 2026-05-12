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

    unordered_map<int,int> mp;
    int preidx = 0;

    TreeNode* helper(vector<int>& preorder,int l,int r)
    {
        if(l > r) return NULL;

        TreeNode* root = new TreeNode(preorder[preidx]);
        int idx = mp[preorder[preidx]];
        preidx++;

        root->left = helper(preorder,l,idx-1);
        root->right = helper(preorder,idx+1,r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //load map
        for(int i = 0;i < inorder.size();i++)
        {
            mp[inorder[i]] = i;
        }

        return helper(preorder,0,inorder.size()-1);
    }
};