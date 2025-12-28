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
    int height(TreeNode *root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void solve(TreeNode *root, int &diameter) {
        if(root == NULL) return;

        int lh = height(root->left);
        int rh = height(root->right);

        if(lh + rh > diameter) {
            diameter = lh + rh;
        }

        solve(root->left, diameter);
        solve(root->right, diameter);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        solve(root, diameter);
        return diameter;
    }
};