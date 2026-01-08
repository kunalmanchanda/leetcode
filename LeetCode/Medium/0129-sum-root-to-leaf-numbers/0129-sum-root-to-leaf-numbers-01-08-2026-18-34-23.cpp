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
private:
    bool isLeaf(TreeNode *root) {
        return (root->left == NULL && root->right == NULL);
    }

    void traversal(TreeNode *root, vector<int> &ans, int sum) {
        if(root == NULL) return;
        
        if(isLeaf(root)) {
            sum = sum * 10 + root->val;
            ans.push_back(sum);
            return;
        }

        traversal(root->left, ans, sum * 10 + root->val);
        traversal(root->right, ans, sum * 10 + root->val);
    }
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(root == NULL) return res;

        vector<int> ans;

        traversal(root, ans, 0);

        for(auto it: ans) {
            res += it;
        }

        return res;
    }
};