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

        int lh = height(root->left);
        int rh = height(root->right);

        return 1 + max(lh, rh);
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root == NULL) return NULL;

        int lh = height(root->left);
        int rh = height(root->right);

        if(lh == rh) return root;

        if(lh > rh) return subtreeWithAllDeepest(root->left);
        
        return subtreeWithAllDeepest(root->right);
    }
};