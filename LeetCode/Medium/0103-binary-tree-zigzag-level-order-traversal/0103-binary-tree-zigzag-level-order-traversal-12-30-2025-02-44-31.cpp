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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if(root == NULL) {
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;

        while(!q.empty()) {
            int n = q.size();
            vector<int> level;

            while(n--) {
                TreeNode *node = q.front();
                q.pop();

                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }

                level.push_back(node->val);
            }

            if(!flag) {
                reverse(level.begin(), level.end());
            }

            result.push_back(level);
            flag = !flag;
        }

        return result;
    }
};