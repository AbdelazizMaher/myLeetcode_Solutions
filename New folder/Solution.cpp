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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderVec {};

        inorder(root, inorderVec); 
        return inorderVec;             
    }

    void inorder(TreeNode* node, vector<int>& inorderVec) 
    {
        if(node == nullptr)
            return;

        if(node->left)
            inorder(node->left, inorderVec);

        inorderVec.push_back(node->val);

        if(node->right)
            inorder(node->right, inorderVec);
    }
};