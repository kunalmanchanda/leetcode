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
    void traversal(TreeNode *root, string path, vector<string> &res) {
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) {
            path += to_string(root->val);
            res.push_back(path);
            return;
        }

        path = path + to_string(root->val) + "->";

        traversal(root->left, path, res);
        traversal(root->right, path, res);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;

        string path = "";

        traversal(root, path, res);

        return res;

    }
};