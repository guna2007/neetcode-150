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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return NULL;

        TreeNode* root = new TreeNode(preorder[0]);

        int idx = 0;
        for(int i = 0;i < inorder.size();i++)
        {
            if(inorder[i] == preorder[0]) 
            {
                idx = i;
                break;
            }
        }

        vector<int> lpre(preorder.begin() + 1, preorder.begin()+idx+1);
        vector<int> rpre(preorder.begin() + idx+1, preorder.end());
        vector<int> lin(inorder.begin(), inorder.begin()+idx);
        vector<int> rin(inorder.begin()+idx+1, inorder.end());

        root->left =  buildTree(lpre,lin);
        root->right =  buildTree(rpre,rin);

        return root;
    }
};