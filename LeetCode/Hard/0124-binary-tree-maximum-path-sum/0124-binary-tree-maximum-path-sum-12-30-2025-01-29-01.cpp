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
// the path can be left + root, right + root, or the root itself to avoid the negative paths or root + left + right also, it need not be leaf node to leaf node
private:
    int solve(TreeNode *root, int &maxSum) {
        if(root == NULL) return 0;

        int left = max(0, solve(root->left, maxSum));
        int right = max(0, solve(root->right, maxSum));

        maxSum = max(maxSum, root->val + left + right);

        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;

        int result = INT_MIN;
        
        solve(root, result);
        
        return result;
    }
};