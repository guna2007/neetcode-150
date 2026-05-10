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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder)
    {
        //if arrays become empty means no node exists
        if(preorder.empty() || inorder.empty())
        {
            return NULL;
        }

        //first element in preorder is always root
        int rootVal = preorder[0];

        //create root node
        TreeNode* root = new TreeNode(rootVal);

        //find root index in inorder
        int idx = 0;

        while(inorder[idx] != rootVal)
        {
            idx++;
        }

        //logic:
        //left side of inorder -> left subtree
        //right side of inorder -> right subtree

        vector<int> leftInorder;
        vector<int> rightInorder;

        //elements before idx go to left inorder
        for(int i = 0; i < idx; i++)
        {
            leftInorder.push_back(inorder[i]);
        }

        //elements after idx go to right inorder
        for(int i = idx + 1; i < inorder.size(); i++)
        {
            rightInorder.push_back(inorder[i]);
        }

        //now split preorder also
        //after root in preorder:
        //first left subtree elements come
        //then right subtree elements come

        vector<int> leftPreorder;
        vector<int> rightPreorder;

        //number of elements in left subtree
        int leftSize = leftInorder.size();

        //take leftSize elements after root
        for(int i = 1; i <= leftSize; i++)
        {
            leftPreorder.push_back(preorder[i]);
        }

        //remaining elements go to right preorder
        for(int i = leftSize + 1; i < preorder.size(); i++)
        {
            rightPreorder.push_back(preorder[i]);
        }

        //recursively build left and right subtree
        root->left = build(leftPreorder, leftInorder);

        root->right = build(rightPreorder, rightInorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        //logic is to iterate on preorder array
        //first element becomes root

        //in inorder:
        //left side of root belongs to left subtree
        //right side belongs to right subtree

        //split arrays into left and right parts
        //repeat recursively until arrays become empty

        return build(preorder, inorder);
    }
};