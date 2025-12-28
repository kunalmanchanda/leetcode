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
    int solve(TreeNode *root, int &sum) {
        if(root == NULL) return 0;
        
        int left = solve(root->left, sum);

        int right = solve(root->right, sum);

        int currSum = max(root->val + max(left, right), root->val);
        int ans = max(currSum, root->val + left + right);

        sum = max(sum, ans);

        return currSum;
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        if(root->left == NULL && root->right == NULL) return root->val;

        solve(root, sum);

        return sum;
    }
};