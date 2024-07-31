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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> queue;

        queue.push(root->left);
        queue.push(root->right);

        while ( queue.size() > 0 ) 
        {
            TreeNode* left = queue.front(); 
            queue.pop();
            TreeNode* right = queue.front();
            queue.pop();

            if (left == nullptr && right == nullptr) 
                continue; 

            if (left == nullptr || right == nullptr) 
                return false; 

            if (left->val != right->val)
                return false; 

            queue.push(left->left);
            queue.push(right->right);
            queue.push(left->right);
            queue.push(right->left);                  
        }
        return true;
    }
};