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
    void solve(TreeNode* root, int targetSum, vector<int> &path, vector<vector<int>> &result) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(targetSum == root->val) {
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }

        path.push_back(root->val);

        solve(root->left, targetSum - root->val, path, result);
        solve(root->right, targetSum - root->val, path, result);

        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;

        solve(root, targetSum, path, result);

        return result;
    }
};