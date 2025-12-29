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
    bool solve(TreeNode *root, int targetSum, int curr) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL) return targetSum == curr + root->val; 
        return solve(root->left, targetSum, curr + root->val) || solve(root->right, targetSum, curr + root->val); 
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum, 0);
    }
};