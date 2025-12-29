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
    int total = 0;

    void solve(TreeNode *root, int targetSum, long long currSum) {
        if(root == NULL) return;

        currSum = currSum + root->val;

        if(targetSum == currSum) {
            total++;
        }

        solve(root->left, targetSum, currSum);
        solve(root->right, targetSum, currSum);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;

        solve(root, targetSum, 0);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return total;
    }
};