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
    vector<int> res;
    void traversal(TreeNode *root, int level) {
        if(root == NULL) return;

        if(res.size() == level) res.push_back(root->val);
        traversal(root->right, level + 1);
        traversal(root->left, level + 1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        traversal(root, 0);
        return res;
    }
};