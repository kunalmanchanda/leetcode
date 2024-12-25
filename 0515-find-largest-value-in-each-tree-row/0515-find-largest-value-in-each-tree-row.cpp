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
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        return 1 + max(height(root->left) , height(root->right));
    }
public:
    vector<int> largestValues(TreeNode* root) {
        int h = height(root);
        if(h == 0) {
            vector<int> ans;
            return ans;
        }

        vector<int> res(h, INT_MIN);

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()) {
            pair <TreeNode*, int> p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int depth = p.second;

            res[depth] = max(res[depth], node->val);

            if(node->left) {
                q.push({node->left, depth + 1});
            }

            if(node->right) {
                q.push({node->right, depth + 1});
            }
        }

        return res;
    }
};