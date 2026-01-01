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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            while(n--) {
                TreeNode *node = q.front();
                q.pop();
                level.insert(level.end(), node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result.insert(result.begin(), level);
        }

        return result;
    }
};